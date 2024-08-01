not all [pages](Memory%20Basics) need to be in memory at the same time, only parts at a time

Programs can have larger virtual memory address space than physical
each process is only using fraction of total address space

### misc
fork() makes all new space in virtual memory for child
vfork() shares virtual memory space with child and parent. parent is just suspended while child is running
### Demand Paging
Pages are swapped in as they need them, on demand. Not all at once
2nd column of page table is valid-invalid bit, to check of legal for process to use page, if page is in memory or not.

If you try to run a process when a page isn't loaded, process is terminated. Then, the page table sends request to load page into memory, and then restarts the process once page is loaded

###### Performance
Page fault rate is % time page is not found, rated 0-1
Effective Access time (EAT)
= (1-page_fault_rate) * memory_access_time + page_fault_rate * page_fault_time

### Page Replacement
when we need to store a new page but there's not enough space
find page that isn't being used right now, and swap page out to disk, making space for the new requested page
but how do you choose which page to swap out?
##### FIFO
put pages into [queue](queues.md). When queue is full, dequeue first page put in
Strangely, the more frames (spaces) in the queue, there can be more frame faults
##### OPT/MIN
the theoretical optimal algorithm will replace the page that won't be used for the longest time. This obviously cannot be made for real, as it needs to know what pages will be needed ahead of time, but it's a benchmark to compare other algorithms to
##### LRU (Least Recently Used)
removes page that has not been used for the longest time
can be implemented with a stack, or by storing use time in data
counter:
- give every page 8 bits to track use time
- when visiting page, bit-shift right all pages and set most significant bit of visited page to 1

Linux used algorithms based on LRU
##### Second chance algorithms
also has reference bit, but only one bit this time
queue of pages like FIFO, but when you visit a page, set the reference to 1
when you need to remove a page, look at the reference bit
- if reference == 1, set reference to 0 and find another page
- if reference == 0, swap out that page
if every page was used recently, second-chance just becomes FIFO
##### page buffering
Not an algorithm, is used with other algorithms
keep a pool of free pages, so you can swap in a needed page without delay
Then you can remove a page after depending on the chosen algorithm

### Page Allocation
any process needs a minimum number of pages to run, there's two main ways to allocate them
##### Fixed allocation
- equal allocation: m frames, n processes, each process gets m/n frames. Any extra are free-buffer pool
- Proportional allocation: Frames are granted proportional to the size of the process
##### Priority allocation
higher priority process gets more frames when needed.
On replacement, a process will either replace its own frame or it will take from a lower priority process
### Thrashing
if a process cannot keep its minimum amount of pages, it must be swapped out.
If a frame can keep its minimum frames, but cannot keep the frames it uses regularly, it will start thrashing
thrashing: where the process spends most of its time swapping pages, getting many page faults

When cpu usage is low, the computer will schedule more processes
When thrashing, cpu usage is low but there's too many processes. But, since cpu usage is low, the computer will keep scheduling more and more processes