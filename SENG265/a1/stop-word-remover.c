#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

# define NUM_STOPS 9
# define MAX_WORDS 500
# define MAX_LENGTH 25
# define BUFFER_SIZE 2000

void tokenize(char*, char output[MAX_WORDS][MAX_LENGTH]);

void clean(char*, char*);

int main(){
//list of stop words to remove 
	char stops[NUM_STOPS][10];
	strncpy(stops[0], "the", 9);
	strncpy(stops[1], "a", 9);
	strncpy(stops[2], "an", 9);
	strncpy(stops[3], "of", 9);
	strncpy(stops[4], "for", 9);
	strncpy(stops[5], "to", 9);
	strncpy(stops[6], "and", 9);
	strncpy(stops[7], "but", 9);
	strncpy(stops[8], "yet", 9);


	char words[MAX_WORDS][MAX_LENGTH];
	char buffer[BUFFER_SIZE];


//goes through input one line at a time
	while(fgets(buffer, BUFFER_SIZE, stdin)){


//cleaning garbage out of words array
		for(int i=0; i<MAX_WORDS; i++){
			strncpy(words[i], "\0", MAX_LENGTH-1);
		}


		tokenize(buffer, words);

//now we have an array of words, compare them to all the stop words and send to stdout
		for(int i=0; i<MAX_WORDS; i++){
			int delete = 0;
			int nospace = 0;

			for(int j=0; j<NUM_STOPS; j++){

//if string is empty, it is skipped from the output
				if(!(strcmp(words[i], "\0"))
				|| delete == 1){
					delete = 1;
				} 

//if a stopword is found in the string, 
//the termination character is checked to see if strings are the same length.
				char *match = strstr(words[i], stops[j]);
				if(match != NULL && delete != 1){
					char *endwordpoint = strchr(words[i], '\0');
					char *endstoppoint = strchr(stops[j], '\0');
					int endword = (int)(endwordpoint-words[i]);
					int endstop = (int)(endstoppoint-stops[j]);
					if(endword == endstop){
						delete = 1;
					} 
				} 
			}

//if delete is not zero, prints word to standard output.
//prints with a space after the word unless that word is a new line
			if(delete == 0){
				int index;
				char *location = strchr(words[i], '\n');
			
				if(location != NULL){
					index = (int)(location-words[i]);
					words[i][index] = '\0';
					nospace = 1;

				}
				if(nospace == 0){
					fprintf(stdout, "%s ", words[i]);
				} else {
					fprintf(stdout, "%s", words[i]);
				}
			}
		}
	fprintf(stdout, "\n");
	}
}

//takes an array of chars, splits it word by word into a 2d array of chars
void tokenize(char *input, char output[MAX_WORDS][MAX_LENGTH]){
	char *t;
	int num_words = 0;

	t = strtok(input, " ");
	while(t && num_words < MAX_WORDS){
		strncpy(output[num_words], t, MAX_LENGTH-1);
		num_words++;
		t=strtok(NULL, " ");
	}
}
















