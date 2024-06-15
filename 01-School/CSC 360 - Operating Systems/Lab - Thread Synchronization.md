
Mutual exclusions (Mutex)
Condition Variables (Convar)

### Mutex
basic mechanism to assure exclusive access to critical section. When thread is in critical section, mutex locks out other threads
Only applies to threads that are all in the same process

If a thread reached a locked mutex, the thread will simply be suspended until the mutex is unlocked, and then resumes where it was
##### Warnings
if handled incorrectly, can cause deadlocks
mutex can only be unlocked by the thread that locks it. If a thread locks it and terminates, it will not be unlocked

#### Creating and Using
declaration:
`pthread_mutex_t myMutex`

Routines
```c
pthread_mutex_init(&myMutex, myAttr);
pthread_mutex_destroy(&myMutex);
pthread_mutex_lock(&myMutex);
pthread_mutex_unlock(&myMutex);
pthread_mutex_trylock(&myMutex);
```

initialize outside of threads as global
when going into critical section, `pthread_mutex_lock` or `pthread_mutex_trylock`
lock suspends the program until it can lock it, while trylock returns if it cannot lock it

once leaving critical section, `pthread_mutex_unlock`

destroy when done
### Convar
a container of threads waiting for a certain condition. allows us to suspend threads until free to prevent busy waiting/cpu use
**must always be associated with a mutex**

#### Creating and Using
declaration:
`pthread_cond_t myConvar;`

routines:
```c
pthread_cond_init(&myConvar, 
	const pthread_condattr_t *attr);
	// attr can be NULL
pthread_cond_destroy(&myConvar);
pthread_cond_wait(&myConvar, &myMutex);
pthread_cond_signal(&myConvar);
pthread_cond_broadcast(&myConvar);
```

thread A:
```c
pthread_mutex_lock(&mylock);
while(!condition)
{
	pthread_cond_wait(&mycond, &mylock);
}
// critical section
pthread_mutex_unlock(&mylock);
```
thread B:
```c
pthread_mutex_lock(&mylock);
// critical section
// makes condition true
pthread_cond_signal(&mycond);
pthread_mutex_unlock(&mylock);
```