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