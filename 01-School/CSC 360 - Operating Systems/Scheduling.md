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