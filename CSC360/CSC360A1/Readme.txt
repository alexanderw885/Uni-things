Alexander Williams V01042108
CSC 360
Assignment #1
Due: May 31, 2024


Pman.c was made in a linux environment

in order to compile the program, use the provided makefile.
Pman.c depends on LinkedList.c and LinkedList.h

inf, blank, and args are all testing files for Pman, and are not required to run the program

COMMANDS:

bg <name>:
	runs file with specified name in same file as Pman. You do not need to add ./

bglist:
	shows all processes still running that were created by this instance of Pman

bgstop <PID>:
	temporarily stops process created by this instance of Pman with specified PID

bgstart <PID>:
	starts stopped process created by this instance of Pman with specified PID

bgkill <PID>:
	terminates process created by this instance of Pman with specified PID

pstat <PID>:
	shows information from proc/pid/stat and proc/pid/status from process with specified PID

exit:
	exits Pman, DOES NOT terminate child processes


TODO:

terminate all children upon exiting Pman
