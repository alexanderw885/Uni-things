# Linux
### Accessing and using linux server: 
To use linux at home: Virtual box 
remote access with PuTTy o in terminal to access linux server:
```ssh alexanderw@linux.csc.uvic.ca```

**Make sure you use bash, or do everything on linux server**

let uid = alexanderw885
remote copy file:
```scp alexanderw885@from_host:dir alexanderw885@to_host:dir```

zip assignments into one package before sending to remote
```tar -czvf zipname file1 file2...```

and to extract the files out:
```tar -zxvf```

all linux basic linux commands from SENG 265 work

##### Limit your processes to prevent bit issues!
```ulimit -u``` shows you max number of processes allowed
```ulimit -u 15``` limits to 15 processes, so you could log in from another terminal to kill the program

##### Chmod
owner-group-others
read=4, write=2 execute=1
```chmod 751 filemane```
7 means 4+2+1 for owner
5 means 4+1 for group
1 means 1 for others


##### man
manual ;
```man 1 cd```
number shows the sections; 
Section 1: user commands; usually use those
Section 2: system calls

defaults to section 1 if not specified

#### If something goes wrong
to check processes, ```cd /proc```
find the process id, use ```ps -l```
then use ```kill -9 PID```


### Background processes in Linux
Ctrl+C to terminate foreground process
Ctrl+Z suspends foreground process, send to background
fg - bring program back to foreground
fg PID - bring specified program to background
bg PID - put specified program to background
& - run program in background


# C
need text editor, compiler, and C standard library
vi or vim from terminal
gedit for GUI

compile:
```bash
gcc file.c -o outputFile ;
./outputFile
```
if you need to link multiple files;
```bash
gcc -c main.c -o main.o
gcc -c add.c -o add.o
gcc main.o add.o -o result
```
or, so it all in a makefile
```
result: add.o main.o
	gcc main.o add.o -o main
add.o: add.c add.h
	gcc add.c -c
main.o: main.c main.o
	gcc main.c -c

clean:
	rm *.o*
```
now to run it, just use the command
```make```
or ```make -f myMakefile```

to check processes, ```cd /proc```
