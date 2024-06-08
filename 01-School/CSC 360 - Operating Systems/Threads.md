Threads are a basic unit of CPU utilization
each process is a unit of resource allocation, and each process has at least one thread.

When creating new threads, you are *not* creating new processes. Once the process ends, all threads will terminate
Here it shows that cade, data, and files are shared by all threads in a process
![[Pasted image 20240604133948.png]]

##### Ex: single thread web server
this server can only work on a single request at a time, or it will have to make a process for each request. However, processes are expensive

If it was multi-threaded, it could have one main thread that delegates tasks to other threads

##### Warning!
If one thread crashes, the whole process will crash. In large projects, it's good to breaks into tasks, each with its own threads

### Why use threads?
it's very easy to share data between threads compared to IPC
Faster to create and terminate
Takes less resources than processes

GOLBAL VARIABLES DECLARED OUT OF A FUNCTION ARE SHARED BETWEEN THREADS
but that won't always work properly
what if two threads call variable at the same time? data will get overwritten

### User vs Kernel threads
##### User
can't run on its own, can only run if told to
  execute code by kernel thread
each process schedules its own threads
no context switching
blacking call blocks whole process
invisible to OS kernel before mapping 
  (kernel only sees process, not what's in it)
##### Kernel
kernel manages all threads
can pickup another thread if one blocks
the actual thread being scheduled and executed by processor

#### User-Kernel Mapping (NOT ON TESTS)
##### Many-one
many user threads are all mapped to single kernel threads, creating a many-one relation.
if a blacking call is made, stops entire process
each kernel thread can only operate on one CPU, so the whole process must be on a single CPU
##### One-one
separate kernel thread for every user thread
doesn't have the problems of many-one, but higher cost
Creating kernel threads is much higher cost, and kernel space is more valuable than user space.
Not generally used
##### Many-many
any number of user threads being assigned to that many or less kernel threads
doesn't have disadvantages of many-one, but is cheaper than one-one
##### Two-level
allows both one-one and many-many operations

### Issues
if you call `fork()` in a thread, does it duplicate just that thread or all threads?
**`fork()` only duplicates that fork, not all of them** (depends on OS)

When you deliver a signal, how to pass to just one or all threads?

When thread crashes, whole process crashes
Safety feature, just in case shared memory was ruined

expensive to create/kill threads, so it's better to create threads once and reuse them as much as possible

### Pthread library
POSIX.1 specifies set of interfaces for threads

question: how does Pthread manage user and kernel threads? Many-many, many-one,...?
Documents in slide 7-14
Answer: in linux, with Pthread,  it's one-one


### Example: producer-consumer
```c
void *producer(void *fifo)
{
	// produce/put elements in fifo
	
}

void *consumer(void *fifo)
{
	// consumes elements in fifo
}

int main()
{
	queue *fifo;
	pthread_t pro;
	pthread_t con;
	fifo = queieInit();
	if(fifo == NULL)
	{
		fprint(stderr, "main: Queue failed init.\n");
		exit(1);
	}
	pthread_create
		(&pro, NULL, producer, fifo);
	pthread_create
		(&con, NULL, consumer, fifo);
	// MUST use join, or main thread
	// will end too soon
	pthread_join(pro, NULL);
	pthread_join(con, NULL);
}
```