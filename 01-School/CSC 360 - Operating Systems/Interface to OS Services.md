## Services
- user/programmer interfaces
	- command line
	- GUI
	- API
	- system calls
- program execution
- I/O operation
- file manipulation
- process communication
- error handling
- resource allocation
- resource sharing/protection

## Dual mode operations
user mode: what the user interacts with, applications, command line, things you see

kernel mode: OS system functions
things like process and memory management, storage, user management
lose these and the computer won't work

you interact with an application, and that application connects to the system call interface
the system call interface then calls functions in kernel mode
## System Calls
there's three types of system calls
Process control
- fork
- exec* $_{\text{(family of processes)}}$
- wait
- kill
- signal
- exit
- ...
file/device manipulation
- create
- open
- read
- write
- lseek
- close
- socket
- bind
- listen
- connect
- ...
information manipulation
- time
- getpid
- getgid
- gethostname
- ...
#### Examples
copying from a to b
in CLI (command line interface)
```bash
cp /path/to/A /path/to/B
```
with system calls
```Shell
open("/path/to/A", O_RDONLY);
creat("path/to/B", S_IRWXU);
	open() with O_CREAT|O_WRONLY|O_TRUNC
read() and write()
close()
```
don't worry about this too much yet

## API

things like WIN32, Java API
higher layer of abstraction
mostly OS independent

with an API, you make the program and it interacts with the library, ex. the standard C library
this library then connects to the system call interface, and calls kernel functions for you

APIs are portable, but slower than system calls