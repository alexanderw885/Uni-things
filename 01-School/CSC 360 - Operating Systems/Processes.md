### What is a process?
a program in execution
it can be a passive entity (code in storage)m or active, with resources allocated to it
when active, has some concepts:
- Process state
- related data structures
- process communication
- process scheduling

a .c file is just code, not a process
gcc is a compiler, and a passive entity

any running program has a PID found through ```ps -l``` or just ```ps```

### Process Data Structure
#### Stack
often at top of memory, temporary data
space is freed as variables go out of scope
#### Heap
dynamic memory, allocated at runtime
this means some things such as variables are unknown until the program is running
#### Data
global and static variables, things allocated and initialized before the program runs
### Text
compiled program code

### Process states
![[Pasted image 20240515140559.png]]
### Process control blocks (PCB)
In kernel space
tracks processes in memory, kernel space
tracks state, process id, scheduling, memory control, device allocation, time consumption/limits
contains program counter, it points to the *next* instruction to be executed
![[Pasted image 20240515141511.png]]

### Context switching
context switch when running multiple programs at once
- saves states
- restores states
Both of these involve saving the registers of the program being switched, as well as the PCBs for each program
this can be done via timer interrupt, defined by
#### Process Scheduling

keeps CPU busy at all times, and keeps acceptable response times for each program
it makes these scheduling queues with linked lists, with ready queues, and I/O queues

there's a1umber of reasons for a process to be interrupted:  ![[Pasted image 20240517135620.png]]
#### Queuing scheduler
multiple parts:
Short term  scheduler: also known as CPU scheduler, or dispatcher. it's frequency is very high
does who goes from memory to 'next program'

long term scheduler: also known as job scheduler. tries to balance between CPU-intensive and I/O-intensive tasks.
lower frequency

medium term scheduler: who is not the next, brings things between long-term storage and memory

Different algorithms for determining queue
first come first serve, shortest job priority, round robin, and more (ch.5)

### Process Creation
parent process can create children process
can be represented as a tree: each child has one parent, but each parent can have multiple children
**Not always a binary tree**

Process ID(PID) and Parent ID (PPID)
usually non-negative integers


when you start computer, first process init(1). every program could be considered descended from init

show tree with command `pstree -p`
the -p shows PIDs

resources between parent and child can be shared, or child programs can get resources directly from the OS
in linux, resources are not shared

two approaches on scheduling: either parent waits until child finishes to run, or they run concurrently

#### How to do it
the command `fork()` creates a child process
returns a `pid_t` datatype
fork copies the caller's memory, but not the PID
it creates a whole new process with a new PCB to control it
if the return value =0, it's in the child process
if the return value >0, it's the parent process
if the return value <0, there was an error

The code is copied, so what you do is make a switch statement
```C
pid_t value = fork();
switch (value)
{
	case 0:
		printf("child process");
		break;
	case >0: //improper, but oh well. use if
		printf("parent process");
		break;
}
```
