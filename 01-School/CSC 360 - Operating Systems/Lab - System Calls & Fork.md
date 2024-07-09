
system calls change mode from user mode to kernel code

`fork()`
creates child process, in [[processes]]
`man 2 fork()`

`exec*()`
family of functions to replace current process with another program
`man 3 exec()`
for our assignment, we'll use:
`execvp(char *file, char *argv[])`
this replaces entire process with program at path `file`

```c
#include <wait.h>
wait()
```
makes parent program suspend execution, waits for specified child to change state or terminate
when child completes execution, it still exists in the table as a "zombie process", waits for parent to collect/read exit status
After that, child is eliminated
has three options: ![[Pasted image 20240521114357.png]]
```c
// in parent:
int status;
waitpid(89, &status, optionals);

//in child
exit(1)
encode(1)
// or something
```

`kill()`
sends signal to specified pid
prototype: `int kill(pin_t, int signal`
returns 0 on success, -1 on error
signals:
- SIGKILL: terminates process, cannot be blocked by process
- SIGTERM: terminates process, can be blocked by process
- SIGSTOP: pauses process
- SIGSTART: resumes process

