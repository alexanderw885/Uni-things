
/*
This program when run, should take 2 command line arguments, both will be integers.
1) First command line integer argument. Allocated an array of size of this number. The array
whill hold integers. Further instruction provided in the code below.
2) Second command line integer argument. This will be the seed provided to the
random number generator.
*/


#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *m, const void *n)
{
    int im = *(int *)m;
    int in = *(int *)n;

    return im - in;
}



int main(int argc, char *argv[])
{

    int i, num_ints;

    if (argc < 3) {
        fprintf(stderr, "usage: %s <num ints> <seed>\n", argv[0]);
        exit(1);
    }

    num_ints = atoi(argv[1]); // First command line argument
    int *int_array = (int *)malloc(sizeof(int) * atoi(argv[1]));
    if(int_array == NULL){
        printf("malloc failure");
        exit(1);
    }

    srand(atoi(argv[2])); // Seeds the random number generator

    // For loop generated random numbers
    for (i = 0; i < num_ints; i++) {
        int_array[i]=rand();
    }
    qsort(int_array, num_ints, sizeof(int), compare_ints);

    for(i = 0; i < num_ints; i++){
        printf("%d\n", int_array[i]);
    }
    free(int_array);

/*  Create an array of integers of the size of the first command line argument
    Fill this array with random numbers
    Sort the array
    Print the results of the array
    FREE the array at the end.
    You will need to use dynamic memory
*/
}
