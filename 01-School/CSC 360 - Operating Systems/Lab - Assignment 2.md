headers
```c
#include <pthread,h>
#include <sys/types,h>
```
compile
`gcc -pthread <source> -o <output>`

Main thread:
creates all customer threads
- all at once, or when they arrive?

Customer threads:
get info passed by `pthread_create()`
simulate arrival time
pick which queue to enter
enter operation:
```c
pthread_mutex_lock()
//enter operation -> length++
pthread_cond_wait()
```
get signaled by clerk
	- `pthread_cond_wait()` returns
	- check if this customer is head of queue, or go back to `wait()`
now ready to be served by clerk
- which clerk?
- get current simulation time to print info
- update overall waiting time
get served by clerk
- `usleep();`
tell clerk it can serve others

which clerk sent the signal?
- before sending signal, clerk sends id into global status variable for the queue it's going to signal
- when customer is signaled, checks value se which clerk

Problems:
multiple clerks signal at same time
- set queues to IDLE of BUSY status to prevent clerk sending their signal when busy
when the first in queue leaves, the second in queue becomes first and might leave
- 1st customer has to lock door to prevent others from leaving


Clerk thread (if you have them):
check for customer in queue
- if customers, return queue id to send signal
- if no customers, wait, then check again
fetch first customer from the picked queue
- `pthread_cond_signal(picked queue)`
- make sure to lock/unlock mutex
wait for customer to finish service
- `pthread_cond_wait();`

when clerk serves last customer, exit the program