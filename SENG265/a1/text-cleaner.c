#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

# define BUFFER_SIZE 2000

//cleans string in the standard input by removing all punctuation, and converting all uppercase letters into lowercase
//outputs string char by char to standard output
int main(){
	int length;
	char buffer[BUFFER_SIZE];

	while(fgets(buffer, BUFFER_SIZE, stdin)){
		length = strlen(buffer);

		for(int i=0; i<length; i++){
			if(!ispunct(buffer[i])){
				printf("%c", tolower(buffer[i]));
			}
		}
	}
	
}
