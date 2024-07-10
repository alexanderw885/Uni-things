#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "emalloc.h"

#define MAX_LINE_LEN 5000

void inccounter(Patient *p, void *arg) {
    /* DO NOT CHANGE THIS FUNCTION. */
    int *ip = (int *)arg;
    (*ip)++;
}


void print_word(Patient *p, void *arg) {
    /* DO NOT CHANGE THIS FUNCTION. */
    char *fmt = (char *)arg;
    printf(fmt, p->name, p->birth_year, p->priority);
}


void dump(Patient *list) {
    /* DO NOT CHANGE THIS FUNCTION. */
    int len = 0;

    apply(list, inccounter, &len);    
    printf("Number of patients: %d\n", len);

    apply(list, print_word, "%s,%d,%d\n");
}

Patient *tokenize_line(char *line) {

	char words[10][50];
	char *t;
	int num_words;
	//looks at line part by part, converting into patients
	t = strtok(line, ",");
	while(t && num_words < 10){
		strncpy(words[num_words], t, 50-1);
		num_words++;
		t=strtok(NULL, ",");
	}
	//was easier to look for new line in string then remove it
	//took me forever to realize there was a \n at all
	if(strncmp(words[0], "dequeue\n", 50) == 0){
		return NULL;
	}


	Patient *new;
	new = new_patient(words[1], atoi(words[2]), atoi(words[3]));
	
	return new;
}

Patient *read_lines(Patient *list) {
	char buffer[MAX_LINE_LEN];
	Patient *head = NULL;
	//converts stdin into lines, converts lines into patients, and adds/removes accordingly
	while(fgets(buffer, MAX_LINE_LEN, stdin)){
		//printf("%s", buffer);
		Patient *new = tokenize_line(buffer);
		//printf("%s %d %d\n", new->name, new->birth_year, new->priority);
		if(new == NULL){
			head = remove_front(head);
		} else{
			head = add_with_priority(head, new);
		}
		
	}
	return head;
}

void deallocate_memory(Patient *list) {
	//deallocates list of patients. 
	//does not deallocate strings as they're just pointers and did not require malloc
        Patient *pointer;
	while(pointer != NULL){
		pointer = list->next;
		free(list);
		list = pointer;
	}

}


int main(int argc, char *argv[]) {
    /* DO NOT CHANGE THE MAIN FUNCTION. YOU HAVE TO IMPLEMENT YOUR
        CODE TO FOLLOW THE SEQUENCE OF INSTRUCTIONS BELOW. */
    Patient *list = NULL;

    if (argc != 1) {
            printf("Usage: %s\n", argv[0]);
            printf("Should receive no parameters\n");
            printf("Read from the stdin instead\n");
            exit(1);
    }

    list = read_lines(list);
 
    dump(list);
    
    deallocate_memory(list);

    exit(0); 
}
