#Set Operations in C

*Description of files*

main.c : The program's main function. Here code execution starts. All the set operation functions are called by this file.

main.o : Object code of the c file main.c. This is used to link with other files while creating an ELF binary file.

set\_op.c : This file Contains the source codes of each set operation.

set\_op.o : Object code of set\_op.c.

set\_op.h : Header file contains all the function declarations of set operations.

link.sh : Bash script to compile and link all the files.
