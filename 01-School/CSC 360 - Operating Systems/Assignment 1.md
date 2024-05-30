look in Process Creation in [[Processes]], and in the process slide

execvp for bg
fork()
don't just use `wait()` in parent, otherwise it'll wait until the child ends

use kill for other processes
handle states with wait or waitpid

bglist prints out content in linkedlist

man 5 proc

can get parent PID with `getppid()`

get state:
```
ps aux
// or for specific state
cd proc/PID
cat stat
```
in C, use `proc()`

exiting program `exit()`


terminate another program
`kill(PID, signal)`
don't just kill the parent, kill the children too. otherwise it'll create orphan programs that keep running after we want them to stop