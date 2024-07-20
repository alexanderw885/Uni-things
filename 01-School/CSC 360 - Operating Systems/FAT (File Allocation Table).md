This will largely be about FAT12 specifically

terms:
- Sector: smallest physical sections on drive
- Block in linux, Cluster in DOS: smallest logical unit of memory
one sector may contain one *or more* sector, but for the most part it will be 1-1 in this class
can find out with `fdisk -l`

### Disk Organisation
FAT-12 consists of four major sections
![[Pasted image 20240710135019.png]]
#### Boot Sector

quick overview
- Sector 0 on disk
- contains info on organisation of rest of disk
	- copies of FAT tables
	- size of sectors
	- sectors in a cluster
	- etc...

 more details:
 
#### FAT Tables
- contains pointers to every cluster on the disk
- most important tables in system, may have extra tables for redundancy
- has 3 values of interest:
	- value signifying this data cluster is the last cluster of a file
	- value signifying this data cluster is unused
	- value signifying where NEXT data cluster of current file is located

| Value         | Meaning                         |
| ------------- | ------------------------------- |
| 0x00          | Unused                          |
| 0xFF0-0xFF6   | Reserved cluster                |
| 0xFF7         | bad cluster                     |
| 0xFF8-0xFFF   | last cluster in file            |
| anything else | number of clusters in next file |
#### Directories
directories exist like files in disk. Each sector of a directory contains 16 entries, each 32-bytes, each points to some other file/sub-directory on disk


### How to read data
what do we read 12-bit tables?
put into 2 full bytes
if odd, ignore the last 4 bits
if even ignore first 4 bits