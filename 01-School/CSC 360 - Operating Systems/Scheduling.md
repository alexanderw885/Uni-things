### What is it
3 types:
- short term (CPU Scheduling): (milliseconds) which process goes next, how long does it get?
- medium term: (seconds) OS suspend or swap out processes for resources
- long term (batch scheduling): which jobs should be started?
we're talking about CPU scheduling, short term. In linux, the CPU scheduler and dispatcher are software components in Kernel

### CPU Scheduler

Goals:
maximise the use of resources
improve responsiveness

CPU I/O Burst cycle
- CPU burst: a period where process demands and actively utilises CPU computations
- I/O burst: a period where process waits for fetching from or writing to storage devices

The CPU does scheduling decisions only when it it  **not** sure when the next process should be.
only makes decisions in 4 conditions:
- switch from running to waiting
- switch from running to ready
- switch from waiting to ready
- termination
![[Pasted image 20240621134951.png]]

non-preemptive:
for conditions 1 and 4, there is no choice, a new process must be selected if one exists.
in a anon-preemptive policy, once a process gets the CPU, it will keep it until it either finishes or needs I/O

preemptive:
for conditions 2 and 3, there is a choice - either continue running current process, or switch another.
here, processes can be interrupted.
preemptive is the more popular system now, since the 90s

### Dispatcher
gives the CPU control to the selected process

it can:
- context switch
- mode switch
- start to execute from the newly loaded PC

it must be as fast as possible, as it runs on every context switch

### Criteria
CPU utilisation - keep the CPU running as often as possible
Throughput - number of processes completed in a unit of time
Turnaround time - time to complete given process
Waiting time - how much time the process spends in ready queue, waiting to get to CPU
Response time - time from user input to response

# Algorithms
many ways to do it
### First Come, First Serve
non-preemptive
very simple, easy to implement
not efficient at all
long waiting times
### Shortest Job First
based on length of **next** CPU burst
optimal for reducing average waiting time
if preemptive, it measures shortest remaining time
But, how do we know how long that burst will be?
### Prediction and Exponentially Weighted Moving Average
$$\tau_{n+1}=\alpha{}t+(a-\alpha)\tau_n$$
estimate\[i+1\] = $\alpha$\*burst\[i\] + (1-$\alpha$)\*estimate\[i\]

in essence, you start with a guess
run burst
average guess and actual burst time
use that as the guess for the next burst

if alpha = 1, past history is ignored and we assume next burst will be same as last burst.
if alpha = 0, then we ignore all previous burst times, assume times are constant
in general, alpha ~= 0.5

### Priority Scheduling
schedule jobs with greatest priority first, use other method to determine between same priority
static: priority stays same
dynamic: priority can change due to ageing, linger queuing time, ...

### Round Robin
each process gets a set time
CPU time quantum/slice, usually 10-100 ms
after that, process returns to waiting to let another process run
Usually run with FIFO

##### Time slice/ time quantum
longer quantum more closely runs in pure FCFS
shorter quantums are more responsive, but more overhead from context switching

### Multi-queue Scheduling
Different processes go into different groups, each of which can have its own scheduling algorithm.
Higher priority queue - foreground queue
- System process, interactive process
- Usually uses round-robin
lower priority queue - background queue
- batch process queue or lower
- usually uses FCFS
once a process is put into one queue, it will not change queues
Scheduling must be done between the two queues
- all high-priority process goes before any lower-priority queue
- 80/20: 80% of CPU time to high priority, 20% of time to low-priority

### Multi-queue with feedback scheduling
jobs can be moved from one queue to another if:
- characteristics of job change between CPU and I/O intensive
- job has waited a long time
most flexible, but also most complex
one example on how it could be implemented is: everything goes into top queue, after its turn with the CPU, it goes into secondary queue. after every turn, it goes into a lower priority queue
## Thread Scheduling
contention scope: scope in which threads compete for CPU; in what scope to apply scheduling alg
Process Contention Scope (PCS)
- between threads in same process
System Contention Scope (SCS)
- system scheduler for kernel threads on one of more CPUs

