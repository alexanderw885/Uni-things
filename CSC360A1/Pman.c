#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For fork()
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#include "LinkedList.h"

#define LEN 128 // Max length of user input

int argNum; // Number of arguments provided by user when prompted

Node* list; // head of LinkedList of all child programs

// runs program who's name is provided argement
// this is accomplished by making a fork of the program, which runs
// the specified program
void bg(char** args)
{

	// Need to copy over all provided args except for bg
	char* childArgs[argNum+1];

	// Must add ./ before program name in childArgs[0]
	int i;
	for(i = 0; args[1][i]!='\0'; i++){}
	childArgs[0] = (char*) malloc((i+3)*sizeof(char));

	char * dotslash = "./";
	strncpy(childArgs[0], dotslash, 3);
	strcat(childArgs[0], args[1]);

	// Then rest of arguments
	for(int i=1; i<argNum; i++)
		childArgs[i] = strdup(args[i+1]);

	childArgs[argNum] = NULL; // array must be terminated by NULL

	pid_t pid = fork();
	if(pid<0) // Something went wrong
	{ 
		printf("fork error, exiting program\n");
		exit(1);
	}
	else if (pid == 0) // Child fork, executes given program
	{

		if(execvp(childArgs[0], childArgs) <0)
		{
			printf("Invalid program address\n");
			exit(-1);
		}

	}
	else if (pid >0) // Parent fork, adds child to LinkedList
	{

		int waitval;
		int status;

		// usleep helps ensure execvp is called before waitval, so if the program
		// ends instantly, it won't be saved in the linkedlist
		usleep(100000);
		waitval = waitpid(pid, &status, WNOHANG);
		if(waitval == -1)
		{
			printf("waitpid error\n");
			exit(1);
		}

		if(WIFEXITED(status))
			printf("program %d exited with code %d\n", pid, WEXITSTATUS(status));
		else
			list = addNode(list, pid, childArgs[0]);
		return;
	}
}

// Prints list of all currently executing programs
void bglist()
{
	printlist(list);
}

// Terminates process with specified PID
void bgkill(int pid)
{
	// Lots of error handling
	if(!exists(pid))
	{
		printf("pid %d is not in list\n", pid);
		return;
	}
	int killval = kill(pid, SIGKILL);
	if(killval == -1)
	{
		printf("error terminating %d\n", pid);
		return;
	}
	// terminating process
	int status;
	int wait = waitpid(pid, &status, 0);
	if(WIFSIGNALED(status))
	{
		if(WTERMSIG(status))
			printf("program %d terminated by signal\n", pid);
	}
	else
	{
		printf("program didn't stop from terminate signal? check ps\n");
		return;
	}
	list = removeNode(list, pid);
	return;
}

// Temporarily stops process with given PID
void bgstop(int pid)
{
	// More error handling
	if(!exists(pid))
	{
		printf("pid %d is not in list\n", pid);
		return;
	}
	int killval = kill(pid, SIGSTOP);
	if(killval == -1)
	{
		printf("error stopping %d\n", pid);
		return;
	}
	// 2 lines of actually stopping process
	int status;
	int wait = waitpid(pid, &status, WUNTRACED | WNOHANG);
	printf("program %d stopped\n", pid);
	
	return;
}	

// resumes stopped process with gived PID
void bgstart(int pid)
{
	// So much error handling
	if(!exists(pid))
	{
		printf("pid %d is not in list\n", pid);
		return;
	}
	int killval = kill(pid, SIGCONT);
	if(killval == -1)
	{
		printf("error continuing %d\n", pid);
		return;
	}
	// Starting process
	int status;
	int wait = waitpid(pid, &status, WCONTINUED | WNOHANG);
	if(WIFCONTINUED(status))
		printf("program %d continued\n", pid);
	else
		printf("program %d did not continue\n", pid);
	return;

}

// Helper function to read frim a line in proc/PID/status
// removes leading/trailing whitespace, returns value in provided argument "out"
void getInfo(char* out, char* in)
{
	//first, get past leading whitespace
	int inpointer = 0;
	int outpointer = 0;
	while (in[inpointer] == ' ')
		inpointer++;
	inpointer++;
	//now copy to out until trailing whitespace
	while(in[inpointer] != ' ' && in[inpointer] != '\n'
	   && in[inpointer] != '\0')
	{
		out[outpointer] = in[inpointer];
		inpointer++;
		outpointer++;
	}
	//lastly, ensure in is terminated properly
	out[outpointer] = '\0';
	return;
}

// Prints out info about the program specified via PID
// proc/pid/stat is missing ctxt switches, and proc/pid/status is missing utime and stime,
// so both had to be used
void pstat(int pid)
{
	// First get filepath set up for proc/pid/stat
	char* filepath = (char*) malloc(100*sizeof(char));
	//check to ensure sprintf succeeds
	int check = sprintf(filepath, "/proc/%d/stat", pid);
	if(check < 0)
	{
		printf("Failure in sprintf\n");
		return;
	}
	FILE* file;

	// Loop through stat to get all info except context switches
	if(file = fopen(filepath, "r"))
	{
		char stat[256];
		fgets(stat, 256, file);
		char* token;
		char delim = ' ';
		int i = 1; // start at one to match man proc(5)
		token = strtok(stat, &delim);

		// switch case to find relevant info from stat
		while(token != NULL)
		{
			switch(i)
			{
				case 2:
					printf("comm: %s\n", token);
					break;
				case 3:
					printf("state: %s\n", token);
					break;
				case 14:
					printf("utime: %.2f seconds\n", 
							atof(token)/sysconf(_SC_CLK_TCK));
					break;
				case 15:
					printf("stime: %.2f\n seconds", 
							atof(token)/sysconf(_SC_CLK_TCK));
					break;
				case 24:
					printf("rrs: %s\n", token);
					break;
			}

			token = strtok(NULL, &delim);
			i++;
		}

		fclose(file);
	}
	else
		printf("failed to open %s\n", filepath);


	strcat(filepath, "us");
	// This loop is in proc/pid/status, just to get context switches.
	if(file = fopen(filepath, "r"))
	{
		char stat[256];
		while(fgets(stat, 256, file))
		{
			char* token;
			char delim = ':';
			char info[128];
			token = strtok(stat, &delim);

			//Checking case to look for relevant information
			//format of file is in man proc(5)
			if(strncmp(token, "voluntary_ctxt_switches", 24) == 0)
			{
				token = strtok(NULL, &delim);
				getInfo(info, token);
				printf("voluntary ctxt switches: %s\n", info);

				//nv ctxt switches always comes right after voluntary,
				//so instead of redefining delim, info, and token for this last line,
				//might as well do it now and then break.
				fgets(stat, 256, file);
				token = strtok(stat, &delim);
				token = strtok(NULL, &delim);
				getInfo(info, token);
				printf("nonvoluntary ctxt switches: %s\n", info);
				break;
			}	
			fgets(stat, 256, file);
		}
	fclose(file);	
	}
	else
		printf("failed to open %s\n", filepath);

	free(filepath);
}

// Takes all arugments provided by user and tokenizes them by spaces
// returns array of arguments
// ArgList[0] is command for Pman
// ArgList[1] is PID, or program for bg to run
// ArgList[2+] are arguments for the program run by bg
int argNum;
char** TokenizeArg(char* input)
{
	argNum = 0;

	// Gets number of arguments provided
	for(int i=0; input[i]!='\0'; i++)
	{
		if(input[i] == ' ' || input[i] == '\n')
		{
			argNum++;
		}
	}
	//Allocate space for ArgList
	char** ArgList = (char**) malloc(sizeof(char*) * (argNum+1));
	if(ArgList == NULL)
	{
		printf("malloc error making ArgList in TokenizeArg\n");
		exit(1);
	}

	char* token;
	char delim = ' ';
	int i = 0;
	token = strtok(input, &delim);
	while(token != NULL)
	{
		ArgList[i] = strdup(token);
		i++;
		token = strtok(NULL, &delim);
	}


	return ArgList;
}

// Ensures that if the user command expects a PID, the user also provides a PID
// Returns 0 if the user either didn't enter a second argument or if second argument was not a number
// Returns providid PID otherwise
int atoiCheck(char** args)
{
	if(argNum <1)
	{
		printf("invalid number of arguments, please include PID\n");
		return 0;
	}
	int out = atoi(args[1]);
	if(out <=0)
	{
		printf("Invalid PID\n");
		return 0;
	}
	return out;
}

// Main loop, reads input and directs program to relevant function
// depending on user input
int main()
{
	int exit = 0;

	list = NULL;

	while(!exit)
	{

		// Taking user input
		printf("PMan: > ");
		char command[LEN];
		scanf("%[^\n]", command);
		char** args = TokenizeArg(command);

		while(getchar() != '\n'); // Clearing output to take input again

		// Routing program depending on user input
		// Would use switch case, but can't for strings
		if(strncmp(args[0], "bg", 3)==0)
		{
			if(argNum <1)
				printf("invalid number of arguments, please include program to run\n");
			else
				bg(args);
		} 
		else if (strncmp(args[0], "bglist", 7)==0)
		{
			bglist();
		}
		else if (strncmp(args[0], "bgkill", 7)==0)
		{
			int pid = atoiCheck(args);
			if(pid)
			{
				bgkill(pid);
			}

		}
		else if (strncmp(args[0], "bgstop", 7)==0)
		{

			int pid = atoiCheck(args);
			if(pid)
			{
				bgstop(pid);
			}
		}
		else if (strncmp(args[0], "bgstart", 8)==0)
		{
			int pid = atoiCheck(args);
			if(pid)
			{
				bgstart(pid);
			}
		}
		else if (strncmp(args[0], "pstat", 6)==0)
		{
			int pid = atoiCheck(args);
			if(pid)
			{
				pstat(pid);
			}
		}
		else if (strncmp(args[0], "exit", 5)==0)
		{
			printf("Exiting  pman.\n");
			exit = 1;
		}
		else
		{
			printf("PMan:> %s: command not found\n", args[0]);
			printf("you can exit the program by typing \"exit\"\n");
		}
		// Frees args after every loop to prevent memory leaks
		for(int i=0; i<=argNum; i++)
		{
			free(args[i]);
		}
		free(args);
	}

	printf("you should make sure all child programs are terminated\n");
	return 0;
}

