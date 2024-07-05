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
- Hard link
	- creates mirror copy of original file, that is completely disconnected from original. Deleting original does not affect mirror copy