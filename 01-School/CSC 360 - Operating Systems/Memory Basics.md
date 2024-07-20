### Background
access by address
- for both code and data
- User programs typically refer to memory addresses as things such as 'i', or 'count'... These must be mapped to physical memory
Address binding
- compile time: absolute code, containing actual physical addresses. Fixed, always the same
- load time: relocatable code, relative to start of program. If program moves, it must be reloaded but not recompiled
- execution time: if program is moved around during course of execution, binding should be delayed until execution time. Requires special hardware, used by most OS nowadays

remember difference between logical and physical memory
- logical: used by cpu, virtual memory
- physical: seen by memory unit, location on drive
the CPU does __not__ ever see the physical address, only the MMU can see it.

but how do these relate to address binding?
- at compile or load time, physical and logical addresses are identical
- at execution time, they are different

the set of all logical addresses is the logical address space
logical space can be larger than physical address space

### MMU - Memory Management Unit
handles mapping of physical to logical addresses
physical address = logical addr. + relocation base

###### Dynamic loading
instead of loading whole program into memory at once, load each routine as it's called. Reduces total memory usage, but increased complexity and overhead

###### Dynamic linking
library modules will NOT get fully included in exe modules. only a stub is linked to exe module, containing references to actual library, which is linked at runtime

###### Dynamically linked libraries
(DLLs)
easy to upgrade/update. As long as stub doesn't change, can update just by loading new version of DLL onto system
### Swapping
not used much in modern OS
if not enough memory to lead process, then some process which isn't currently using the CPU may have their memory swapped out to a fast local disk called the backing store
- swap out: moves program to backing store, low priority
- swap in: address binding

### Contiguous Memory Allocation
single or multi partition allocation
multi might be for multiple operating systems, or for other users

How to allocate memory for a process?
there's three methods
- First-fit: first big enough space, fastest search
- Best-fit: smallest space big enough for process
- Worst-fit: Largest space big enough to hold

This can create __fragmentations__
- External fragmentation: enough total free space, but not a large enough single space for a process
- Internal Fragmentation: difference between allocated and requested size

if programs in memory are relocatable, then you can reduce external fragmentation by combining all free partitions together, making larger free partitions for new processes

### Paging
terms:
- Page: divide logical memory space into fixed blocks of same size
- Frame: divide physical memory into blocks of same size
- Page table: looks up what frame a page is stored in (translates page number into frame number)

Page lookups must be done for every memory reference, and when process gets swapped in/out of CPU. 
Hardware Support: translation look-aside buffer (TLB)
it's a cache
search in TLB for info, if not, then go to page
Note that TLB does not have enough space for an entire page

### Segmentation
Memory is divided into segments (code, stack, heap, data,...)
memory segmentation supports this by providing addresses with segment number, and an offset from beginning of segment

each segment has a base index, and a size limit. This is stored in a segment table