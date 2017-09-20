//Stephanie Bertrand
//I pledge the Honor Code, meaning I completed this assignment on my own.

/*
Problem:
Write a program that imitates a simple linux shell (i.e. a command interpreter)
that uses fork() and execvp().  The parent process will have to wait for the 
termination of the child.  The child process must parse the line of input into 
a set of arguments that will execvp using the filename and remaining arguments. 
*/

/* 
Solution:
In a while loop, keep accepting stdin, with max string size of 100, until 
EOF is reached.  When forking, create an if-else statement that dedicates 
code for the parent (pid > 0), and the child (pid = 0). The parent will 
wait(NULL) until the child has finished.  The child will parse any 
'spacing' between the string of words and store them in an array 
of max size 10.  The child will then call execvp accepting these
arguments.  Error messages are deployed if something goes wrong when 
executing fork() or execvp().
*/

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX_INPUT_CHAR 100
#define MAX_ARGS 10

int main(){
	while(1){
		char str[MAX_INPUT_CHAR];
		pid_t pid;

		printf("%% ");
		if(fgets(str, MAX_INPUT_CHAR, stdin) == NULL){			//Keep accepting stdin until EOF is reached
			break;}
		
	 	if((pid=fork())==0){									//Child process
	 		const char delims[] = " \t\r\n\v\f";
	 		char *word;
	 		char *argv[MAX_ARGS] = {NULL};
	 		int i = 0;
				 
			word =  strtok(str, delims);

	   		while(word != NULL){ 								//Loop: Keep parsing until end of string is reached, ie. pointer = NULL
      			argv[i] = malloc(strlen(word) + 1);
      			strcpy(argv[i], word);							//Place each parsed argument in argv[i]
      			i++;

	      		word = strtok(NULL, delims);					
	   		}

			if(execvp(argv[0], argv) < 0){						//If there's no error execvp will replace the below code with new code
				fprintf(stderr, "%s", "ERROR: Execvp failed. Please enter a file in /bin as your first argument.  Command line argument must be less than 100 characters long.\n");		//execvp failed error message and abort
				exit(1);
			}
	 	}

	 	else if(pid < 0){										
	 		fprintf(stderr, "%s", "ERROR: forking child process failed.\n");	//Forking failed error message and abort
	 		exit(1);
	 	}

	 	else{													//Parent process, pid > 0
	 		wait(NULL);											//Waits until child process executes
	 	}
 	}
    return 0;
}