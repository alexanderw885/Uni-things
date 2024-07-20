12 means 12-bit entries
1 sector to one cluster, 512 bytes
![[Pasted image 20240710135019.png]]
### FAT Tables
FAT1 and FAT2 are exactly the same, FAT2 is just a backup table
	Probably modify both if you have to modify them at all
Remember, entries are 12 bits!
positions 0 and 1 are reserved

to calculate free space, just count how many 0\x00 entries there are

### Root directories
Also essentially a table
each sector of a directory contains 32 entries, each 32 bytes long


# Assignment

For integers, you need to reverse value of bytes, this system uses little endian!!!!!

how to read? 
when the disk file is small: mmap (Map File into Memory)
```c
#include <sys/mman.h>

void *mmap (void *addr, size t length,
			int prot, int flags,
			int fd, off toffset)
```


When the disk file is large: File Pointer  
```c
#include <stdio.h>  
size t fread (void *ptr,
			  size_t size,
			  size_t nmemb,
			  FILE *stream) 

size t fwrite (const void *ptr,
			   size_t size,
			   size_t nmemb,
			   FILE *stream)

int fseek (FILE *stream,
		   long int offset,
		   int whence)  

```

