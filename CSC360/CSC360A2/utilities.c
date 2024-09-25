#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "utilities.h"

// Creates a linked list of customers, only used to store data before initializing threads
void makeCust(Customer* out, char info[])
{
    // Tokenizing line to get data and ensureing values are valid 
    char* token;
    char * delim = ":";
    char* end;
    
    token = strtok(info, delim);
    out->id = atoi(token);
    if(out->id < 0 || (out->id == 0 && strncmp("0", token, 2)))
    {
        printf("invalid id in customer with id \"%s\": id must be >= 0\n", info);
        exit(1);
    }

    delim = ",";
    token = strtok(NULL, delim);
    out->class = atoi(token);
    if((out->class == 0 && strncmp("0", token, 2)) || out->class > 1 || out->class < 0)
    {
        printf("invalid class in customer with id \"%s\": class must 0 or 1\n", info);
        exit(1);
    }

    token = strtok(NULL, delim);
    out->arrivalTime = atoi(token);
    if(out->arrivalTime < 0 || (out->arrivalTime == 0 && strncmp("0", token, 2)))
    {
        printf("invalid arrival time in customer with id \"%s\": time must be >= 0\n", info);
        exit(1);
    }

    token =strtok(NULL, delim);
    out-> serviceTime = atoi(token);
    if(out->id < 0 || (out->serviceTime == 0 && strncmp("0", token, 2)))
    {
        printf("invalid service time in customer with id \"%s\": time must be >= 0\n", info);
        exit(1);
    }
    return;
}

double currTime(double start)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    double current= (now.tv_sec + (double) now.tv_usec / 1000000);
    return current - start;
}
