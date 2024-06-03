**Will be online**

not using review, intro, or structure
will cover interface, processes, 

#### First slides
batch processing vs time sharing
#### Interfaces:
OS services
CML or GUI
System calls
- what is, what isn't a system call
- user mode / kernel mode
Application program interface (API)
- what is API
- difference between api and system call
- flow of api (you call api, it calls system)

#### Processes
MOST IMPORTANT
what is a process?
- each executable could be executed multiple times
- not source code
- source code in storage, process is running executable
process structure
- stack, heap, data
states
- new->ready->running->waiting->...
PCB
- process state, number, registers...
- program counter always points to NEXT instruction
Context switch
- save/restore states
- switch between processes
scheduling
- queues, efficiency REVIEW THIS
- different schedulers
process creation
- fork(), exec(), wait(), process tree, PID/PPID
- resource sharing
- execution
process termination
- exit(), kill()
- zombie/orphan

#### IPC
memory passing
producer-consumer problem
shared memory solution
message passing
 \+ buffering
 