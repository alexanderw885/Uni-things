need to synchronize between multiple programs
(producer-consumer, multi-threading,...)

with threads, if you have multiple threads all accessing and changing the same data, results may get lost and overwritten, so you can't have them do that
sharing is nondeterministic

### Critical Selection Problem
this is the code accessing shared data, you need to make sure only one thread is in the critical section at any time

#### Solutions

must have 3 properties
- mutual exclusion: only one process in critical section at a time
- making progress: if no process in critical section, another process can enter
- bounded waiting: waiting time to get to critical section is bounded
###### turns:
make int turn
if it's your turn, do the critical section, then change turn to next thread
not great, forces threads to alternate

###### Flags
each thread has a flag
when no other flag is true, set your flag as true
then do critical section
now set flag to false
```c
while(true)
{
	flag[i] = true;
	while(flag[j]){};
	//critical section
	flag[i] = false
	//non-critical section 
}
```
this can make a deadlock, what if both i and j are true at the same time? neither can do critical section

###### Dekker's solution
```c
//shared data
int turn;
boolean flag[];

while(true)
{
	flag[i] = true;
	while(flag[j])
	{
		if (turn == j)
		{
			flag[i] = false;
			while (turn == j){}// wait
			flag[i] = true;
		}
	}
	// critical section
	turn = j;
	flag[i] = false;
	// non-critical section
}
```

###### Peterson's solution
```c
bool flag[2] = {false, false};
int turn;

while(true)
{
	flag[i] = true;
	turn = j;
	while(flag[j] && turn == j){} //wait
	// critical section
	flag[i] = false;
	// non-critical section
}
```

# Semaphore

```c
#include <pthread.h>
#include <semaphore.h>
```
work similarly to mutexes. With mutexes, they can only be unlocked by the thread that locked them. 
Semaphores are only a value, and a signal. 

only 2 functions
```c
wait(S): // call with P()
	while S <= 0 
		do nothing;
	S--;

Signal(S): // call with V()
	S++;
```

Semaphore S - integer value
can be binary, or counting
binary semaphores are like mutexes, 0=locked, 1=unlocked
counting semaphores can let a program run through the critical section multiple times in a row, until the value goes down to 0

#### Binary semaphore example
```c
sem_t sem;

do
{
	wait(sem);
	// criticl section
	signal(sem);
	//non-critical section
} while (1);
```