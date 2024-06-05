# Threads
**MUST ADD -pthread OR -lpthread IN GCC COMMAND!!!!!**

a thread is the flow of execution in a process
different threads execute in parallel

each thread has its own:
ID, registers, stack+pointers, local variables, signal mask, priority, return address

threads share:
process instructions, data segment, file descriptors, signals, current directory, user/group ID

#### Creation
`#include<pthread.h>`
```
int pthread_create
(
   pthread t *thread,
   pthread_attr_t attr,
   void *(*start_routine)(void *),
   void *arg
);
```

thread: returns thread ID
attr: attribute object of thread
start_routine: function to be executed by thread
arg: arguments for functions
returns 0 on success

no limit on number of threads, no hierarchy tree other than main thread. If main thread terminates, all thread terminates

attributes can be passed via attr when calling, or is assigned certain attributes via default

initialize attribute with:
`int pthread_attr_init(pthread_attr_t *arttr)`
`int pthread_attr_destroy(pthread_attr_t *arttr)`


#### Termination
thread self terminates upon finishing task.
`pthread_exit()` to exit in execution
`pthread_concel(ID)` cancels thread with given ID, returns 0 on success

#### Joining
`pthread_join(ID, retval)` waits for termination of other thread
similar to `waitpid`
ID = thread ID
retval = value to get from terminated thread