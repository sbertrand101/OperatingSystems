# OperatingSystems
Fall 2017 COMP 530: Operating Systems with Professor Kevin Jeffay

### **Assignment 1**
Write a C program on linux that reads in a string of characters from standard input, and write them as 80 character lines to standard output. 
* Every newline must be replaced by a space.
* Every double asterisk '**' replaced by a carrot '^'.

### **Assignment 2**
Write a C program that imitates a simple linux shell (i.e. a command interpreter) that uses fork() and execvp().
* Takes in command prompts less than 100 characters long
* Execvp() limited to take in 10 arguments
* The parent process waits for the child to finish executing
* The child process parses the command and execs the the filename and remaining arguments

