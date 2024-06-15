Mutual exclusion
has two states:
- locked: there is a thread in the critical section
- unlocked: no threads in critical section

if it's unlocked, it can be locked by at most one thread.
If it's locked, it can only be unlocked be the thread that locked it. This should be done when leaving the critical section

Order of Operations
1. Create mutex variable (initially unlocked)
2. Threads attempt to lock the mutex
	- If it's locked, thread is suspended until mutex is unlocked
	- if it's unlocked, one thread locks and enters critical section, then unlocks after
3. destroy mutex variable with function

**Try to keep critical section as small as possible!**
