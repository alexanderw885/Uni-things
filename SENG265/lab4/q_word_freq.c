# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>


int word_freq(char *sentence, char *word);

/*
 * This program will take a word from the command line.
 * An example of sequence of terminal commands to run the program is:

        gcc word_freq.c -o word_freq
        ./word_freq match

 * Properly implemented, the running the above commands will
 * produce the following output to console:

        The word "match" appears 4 times

 * NOTE: To keep things simple, we are keeping case in place.
 * That is to say that "match" and "Match" are considered as different
 * in counting.
 */


int main(int argc, char*argv[]){
        int num;
        if (argc < 2) {
            printf("usage: %s <word>\n", argv[0]);
            exit(1);
        }

        char *word = argv[1];

        char st0[] = "Awk scans each input file for lines that match any "
                    "of a set of patterns specified literally in prog or "
                    "in one or more  files specified  as  -f progfile.  "
                    "With each pattern there can be an associated action "
                    "that will be performed when a line of a file matches "
                    "the pattern.  Each line is  matched  against the "
                    "pattern portion of every pattern-action statement; "
                    "the associated action is performed for each matched "
                    "pattern. The file name - means the standard input.  "
                    "Any file of the form var=value is treated as an "
                    "assignment, not a filename, and  is  executed  at  "
                    "the time  it  would  have been opened if it were a "
                    "filename.  The option -v followed by var=value is an "
                    "assignment to be done before prog  is  executed;  "
                    "any  number  of  -v  options  may be present.  The "
                    "-F fs option defines the input field separator to "
                    "be the regular expression fs. An input line is "
                    "normally made up of fields separated by  white  "
                    "space, or  by  the regular expression FS.  The "
                    "fields are denoted $1, $2, ..., while $0 refers to "
                    "the entire line.  If FS is null, the input  line  "
                    "is split into one field per character.";

        char *st1 = "aaa bbb aaa aaa bbb ccc ddd zzz aaa";

        num = word_freq(st0, word);
        printf("The word \"%s\" appears %d times in st0.\n", word, num);


        num = word_freq(st1, word);
        printf("The word \"%s\" appears %d times in st1.\n", word, num);

        
}

/*
 * COMPLETE IMPLEMENTATION OF THE FUNCTION BELOW
 */

int word_freq(char *sentence, char *word){
	int MAX_WORDS=strlen(sentence);
	const int MAX_LENGTH=20;
	char allWords[MAX_WORDS][MAX_LENGTH];
	char *t;
	int num_words=0;

	char input[MAX_WORDS];
	strncpy(input, sentence, MAX_WORDS*MAX_LENGTH);

	t=strtok(input, " ");
	while(t && num_words < MAX_WORDS){
		strncpy(allWords[num_words], t, MAX_LENGTH-1);
		num_words++;
		t=strtok(NULL, " ");
	}

	
	int freq = 0;
	int equal;
	
	for(int i=0; i<MAX_WORDS; i++){
		equal=strncmp(allWords[i], word, MAX_LENGTH);
		if(equal==0){
			freq++;
		}
	}

        return freq;
}