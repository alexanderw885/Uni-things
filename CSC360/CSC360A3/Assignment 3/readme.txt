Alexander Williams
V01042108
CSC 360 Summer 2024
Assignment 3

consists of 4 parts. you can compile all four executables with "make",
and remove all .o files with "make clean".

-----------------------------------------
diskinfo
run with "./diskinfo file.IMA", prints info about provided image file

disklist
run with "./disklist file.IMA", prints all files and directories in image file

diskget
run with "./diskget file.IMA file_to_get.ext", creates file_to_get.ext in working directory
Only works in root directory of image file

diskput
run with "./diskput file.IMA file_to_put.ext", places file into image file.
Does not currently enter file location into the backup FAT tables

---------------------------------------

Due to a lack of time, as it can be a very busy time of year, diskput is incomplete, and diskget may also need bug testing
This will be fixed at a later point in time, after the class has ended.