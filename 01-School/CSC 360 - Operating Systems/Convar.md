related to [[Synchronisation]]

Used when we want to conditionally check if  some condition is met
differences to semaphore
- CV can wake all waiting threads
- Sem has a value it can count with, CV does not
- Sem is counter + mutex-lock + queue, CV is just a queue

`wait(convar, mutex)`
- mutex must be locked
- puts caller into queue 
- will automatically unlock the mutex while it waits
- once signal is received and thread is unblocked, mutex automatically locks again
- unblocks mutex when thread finishes
`signal(convar)`
- wakes up all threads waiting on the condition, lets one in if possible

```c
pthread_mutex_lock(mtx);
//check_condition;
pthread_cond_wait(cv, mtx);
// critical section
pthread_cond_signal(cv);
pthread_mutex_unlock(mtx);
```