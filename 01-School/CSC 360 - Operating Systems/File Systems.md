what is a file?
- unit of stored data. Often in hard drive, sometimes in memory. If in memory, much faster, but volatile
- file types can be different types (binary, text, mp4, ...)
- contains meta information (size, creation/editing time, location, protection...)

two types of file structures
- unstructured
	- binary executable
- structured with records
- binary archive with model

### File access methods
sequential access
- straightforward
- reads from start to end, cannot skip anything
Direct access (relative access)
- can access data anywhere in file without reading everything before it
- does not use index or random access, uses physical location of data
Indexed access
- index file contains pointers to each file
- To locate file, search the indexes and use pointers to navigate to file

## Directory structure
a directory is a special file, a collection of meta information from other files
allows for direct and indirect access

Unix file system is hierarchical/tree-like highest level, root, is denoted with '/'
there is also a directory called root, which is something else

two types of path:
- absolute; path from root
- relative; path from some directory to another

instead of tree, file structure can also be a directed acyclic graph (DAG)

##### Links
two types of links
- Symbolic link (soft link)
	- file that contains path to another file, that references original copy. deleting original deletes soft linked file
	- can create with `ln -s parent child`
- Hard link
	- creates mirror copy of original file.. Deleting original does not affect mirror copy
	- Editing the original does edit copy
	- can create with `ln parent child` command

You can make a hard link to a soft link, and deleting the original or the soft link will preserve the hard link
### Sharing and Protection
different users can have different permissions 

What do you do when something goes wrong, things like hardware failure or software corruption, or network failure in remote storage?
##### RAID
redundant array of independent disks
a mix of copies of stored data and checksum bits

##### Consistency control
what if multiple users want to access the same file
- lock the file so they can't all change it
- or just sensitive parts of the files 

### Implementation
high level view
different operating systems use different implementations:
DOS: [FAT](\(FAT%20(File%20Allocation%20Table\))(file allocation table) - assignment 3
Linux: inode

file system can be divided into Sectors, which are often in the range of 512 bytes to 4KB

two types of blocks:
- data blocks
- control blocks: boot, partitions, root directory, file control

two types of accessing blocks
- logical block address: provided by OS kernel 
- physical block address: determined by disk geometry, physical aspects of storage

- a boot control block contains information of how to boot the system off that disk
- a volume control block (master file in unix, superblock in windows) contains info such as partition table, number of blocks in file system, pointers to free blocks, pointers to free FCB blocks
- the File Control Block (FCB) contains detail about ownership, size, permissions, dates, etc.  Every file has a FCB


### Allocation
- Contiguous Allocation
	- requires all blocks of a file be kept together contiguously
	- very fast
	- can be problems with incorrect estimations of size: too large information wastes space, too small means you need to reallocate
- Linked allocation
	- like a linked list, each block points to the next
	- very easy to expand
- Indexed allocation
	- index block has a list of pointers to all other blocks in file
	- random access
	- easy to expand
	- limited by size of index
	- multiple layers of indexes can increase the max possible file size