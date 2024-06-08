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