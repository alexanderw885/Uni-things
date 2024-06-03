#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

#include "LinkedList.h"

// Adds new node to end of LinkedList, returns head
Node* addNode(Node* head, pid_t newPid, char* newPath)
{
	Node * new = (Node*) malloc(sizeof(Node));
	new->pid = newPid;
	new->path = strdup(newPath);
	new->next = NULL;

	// If list is empty
	if(head == NULL)
	{
		return new;
	}
	Node* pointer;
	pointer = head;
	while (pointer->next != NULL)
		pointer = pointer->next;

	pointer->next = new;
	return head;
}

// Removes node containing specified PID, returns head of list
// Prints error if PID is not in list
Node* removeNode(Node* head, pid_t pid)
{
	Node* pointer = head;
	Node* delete = NULL;
	if(head->pid == pid)
	{
		delete = head;
		head = head->next;
	}
		
	while(pointer->next != NULL && delete == NULL)
	{
		if(pointer->next->pid == pid)
		{
			delete = pointer->next;
			pointer->next = delete->next;
		}
		pointer = pointer->next;
	}

	if(delete == NULL)
	{
		return head;
	}

	free(delete->path);
	free(delete);	
	return head;
}

// Checks if process referenced by the node has terminated.
// return 0 if terminated, otherwise returns 1
int exists(pid_t pid)
{
	int status;
	int waitval = waitpid(pid, &status, WNOHANG | WUNTRACED | WCONTINUED);
	if(WIFEXITED(status))
		return 0;
	return 1;
}

// Iterates through linked list, printing out all programs in it
void printlist(Node* head)
{
	Node* pointer;
	pointer = head;
	int jobs =0;	
	while (pointer != NULL)
	{
		if(exists(pointer->pid))
		{
			printf("%d: %s\n", pointer->pid, pointer->path);
			pointer = pointer->next;
			jobs++;
		}
		else
		{
			printf("process %d has ended\n", pointer->pid);
			Node* delete = pointer;
			pointer = pointer->next;
			removeNode(head, delete->pid);
		}
	}	
	printf("Total number of jobs: %d\n", jobs);
	return;
}
