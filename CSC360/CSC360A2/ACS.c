#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#include "utilities.h"

#define NQUEUES 2 // enables generalization, or highter priority queues
#define NCLERKS 5

// GLOBAL VARIABLES
// general
double startTime; // in 10ths of seconds

// queues
Customer* queues[NQUEUES];
int qHead[NQUEUES];
int qTail[NQUEUES];
pthread_mutex_t mtxQ;
pthread_cond_t cvQ;
int inQ; // Convar condition
int done; // Signals clerks to terminate when true

// totals
int numTotal;
int custClassTotal[NQUEUES];
int classTime[NQUEUES];
pthread_mutex_t mtxTotal;


void* CustThread(char* info)
{
    // Extract customer info
    info[strcspn(info, "\n")] = '\0'; // removes trailing newline
    Customer self;
    makeCust(&self, info);
    

    // Waiti until ready to enter the queue
    struct timeval now;
    gettimeofday(&now, NULL);
    double deltaTime = currTime(startTime);
    printf("Customer %d has arrived\n", self.id);
    if(deltaTime < (double)self.arrivalTime / 10)
    {
        usleep(((double)(self.arrivalTime) - deltaTime) * 100000);
    }
    
    int class = self.class;
    //CRITICAL SECTION
    pthread_mutex_lock(&mtxQ);
    queues[self.class][qTail[class]] = self;
    qTail[class]++;
    printf("Customer %d is entering queue %d. Current length: %d.\n", 
        self.id, self.class, qTail[class]-qHead[class]);
    pthread_cond_signal(&cvQ);
    pthread_mutex_unlock(&mtxQ);
    inQ++;
    // CRITICAL SECTION OVER
    free(info);
    pthread_exit(0);
}

void* ClerkThread(int* idPointer)
{
    int id = *idPointer;
    free(idPointer);
    printf("clerk %d ready to go!\n", id);

    while(!done)
    {
        Customer serving;
        // CRITICAL SECTION
        // Uses convar to not enter queue when there's no customers
        pthread_mutex_lock(&mtxQ);
        while(inQ == 0 && !done)
            pthread_cond_wait(&cvQ, &mtxQ);
        if(done)
        {
            pthread_cond_signal(&cvQ);
            pthread_mutex_unlock(&mtxQ);
            break;
        }
        for(int i=NQUEUES-1; i>=0; i--)
        {
            if(qHead[i] < qTail[i])
            {
                serving = queues[i][qHead[i]];
                qHead[i]++;
                inQ--;
                break;
            }
        }
        if(inQ || done)
            pthread_cond_signal(&cvQ);
        pthread_mutex_unlock(&mtxQ);
        // CRITICAL SECTION OVER

        // inputting data for totals for averages
        // CRITICAL SECTION
        pthread_mutex_lock(&mtxTotal);
        custClassTotal[serving.class]++;
        classTime[serving.class] += currTime(startTime) - (double)(serving.arrivalTime)/10;
        int served = 0;
        for(int i=0; i<NQUEUES; i++)
        {
            served += custClassTotal[i];
        }
        if(served == numTotal)
            done = 1;
        if(done)
            pthread_cond_signal(&cvQ);
        pthread_mutex_unlock(&mtxTotal);
        // CRITICAL SECTION OVER

        // Handling customer
        printf("Clerk %d begins serving customer %d from queue %d at time %.2f, who waited %.2f seconds.\n",
             id, serving.id, serving.class, currTime(startTime), currTime(startTime) - ((double)serving.arrivalTime)/10);
        usleep(serving.serviceTime * 100000);
        printf("Clerk %d finished serving customer %d at time %.2f\n", id, serving.id, currTime(startTime));
    }
    pthread_exit(0);
}



int main()
{
    //read and open file
    char fname[100];
    FILE* file;
    do
    {
        printf("Enter customer file name: ");
        scanf("%[^\n]", fname);
        file = fopen(fname, "r");
        while(getchar() != '\n'); // Clear scanf
        if(file == NULL)
        {
            printf("invalid file name\n");
            exit(1);
        }
    } 
    while(file == NULL);

    // create preparing customer info
    char line[128];
    fgets(line, 128, file);
    numTotal = atoi(line);

    if(numTotal == 0)
    {
        printf("invalid declaration of number of customers, \"%s\"\n", line);
        exit(1);
    }
    
    // Setting up threads and mutexes, allocation data
    pthread_t* customers = (pthread_t*) malloc(sizeof(pthread_t) * numTotal);
    pthread_t* clerks = (pthread_t*) malloc(sizeof(pthread_t) * NCLERKS);
    done = 0;
    inQ = 0;
    if(pthread_mutex_init(&mtxTotal, NULL) != 0)
    {
        printf("error initializing totals mutex\n");
        exit(1);
    }
    pthread_cond_init(&cvQ, NULL);
    if(pthread_mutex_init(&mtxQ, NULL) != 0)
    {
        printf("error initializing queuemutex\n");
        exit(1);
    }
    for(int i=0; i<NQUEUES; i++)
    {
        custClassTotal[i] = 0;
        classTime[i] = 0;
        queues[i] = (Customer*) malloc(sizeof(Customer) * numTotal);
        qHead[i] = 0;
        qTail[i] = 0;
    }

    // Create clerk threads
    for(int i=0; i<NCLERKS; i++)
    {
        int *id = malloc(sizeof(int));;
        *id = i;
        int error = pthread_create(&clerks[i], NULL, (void*)ClerkThread, (void*)id);
        if(error != 0)
        {
            printf("error initializing clerk thread %d\n", i);
            exit(1);
        }


    }

    // Create customer threads
    struct timeval start;
    gettimeofday(&start, NULL);
    startTime = (start.tv_sec + (double) start.tv_usec / 1000000);
    int i = 0;
    while(fgets(line, 128, file))
    {
        if(line[0] == '\n')
            break;
        if(i == numTotal)
        {
            printf("ERROR: Expected number of customers exceeded. Expected: %d\n exiting program.\n", numTotal);
            printf("line: |%s|\n", line);
            exit(1);
        }
        char* outline = (char*) malloc(sizeof(char) * 128);
        strncpy(outline, line, 128);

        int error = pthread_create(&customers[i], NULL, (void*)CustThread, (void*)outline);
        if(error != 0)
        {
            printf("Error creating customer threads\n");
            exit(1);
        }
        i++;
    }
    if(i != numTotal)
    {
        printf("expected number of customers: %d, actual: %d. moving forwards with %d customers\n", numTotal, i, i);
        numTotal = i;
    }
    
    
    // Joining customer threads
    for(int i=0; i<numTotal; i++)
    {
        void* retval;
        pthread_join(customers[i], &retval);
    }
    // Joining clerk threads
    for(int i=0; i<NCLERKS; i++)
    {
        void* retval;
        pthread_join(clerks[i], &retval);
    }

    printf("----------------------------------------\nOver the course of %.2f seconds:\n----------------------------------------\n", currTime(startTime));
    

    double totalWait = 0;
    for(int i=NQUEUES-1; i>=0; i--)
    {
        printf("the average waiting time for queue %d is %.2f seconds, over %d customers.\n",
            i, (double)(classTime[i])/custClassTotal[i], custClassTotal[i]);
        totalWait += (double)(classTime[i]);
    }
    printf("the average waiting time for all customers is %.2f seconds, over %d customers.\n", totalWait/numTotal, numTotal);

    // freeing queues and mutexes
    fclose(file);
    free(customers);
    free(clerks);
    pthread_mutex_destroy(&mtxTotal);
    pthread_cond_destroy(&cvQ);
    pthread_mutex_destroy(&mtxQ);
    for(int i=0; i<NQUEUES; i++)
    {
        free(queues[i]);
    }
}