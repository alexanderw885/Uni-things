threads, pthread
- motivation
- types of kernel thread/process thread mapping
- potential issues
- how to use `pthread` functions
- producer-consumer problems

synchronisation
- race condition
- critical sections
- algorithms in synchronisation slides
- mutexes
- semaphores
	- binary/counting
- convars
- monitors
- dining philosophers

scheduling
- what is CPU scheduling
- context switching
- turnaround time
- preemptive or non-preemptive
- waiting time
- algorithms
	- FCFS
	- Shortest job first
	- preemptive shortest job first
	- round-robin
		- quantum times
	- multi-queue scheduling
		- simulate multi-queue when given list of process arrival/running time
- Thread scheduling
	- process contention scope: inside 1 process
	- system contention scope: in kernel mode, run on one+ CPUs