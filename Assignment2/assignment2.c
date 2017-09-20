//Stephanie Bertrand
//I pledge the Honor Code, meaning I completed this assignment on my own.

/*
Problem:
Write a program that reads in a string of characters from standard input,
and write them as 80 character lines to standard output. 
Every newline must be replaced by a space.
Every double asterisk '**' replaced by a carrot '^'.
*/

/* 
Solution:
Read in the input one character at a time, evaluate each character to see 
whether changes are necessary, then add the character to the 80-character array.
When the array is filled with 80 characters, print the array with a '\n' appended
at the end, reset the array's counter to 0, and resume the input read.
*/

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	while(1){
		char str[100];
//		char *parmList[] = {"/bin/ls", "-l", "/Users/sbertrand", NULL};

		printf("%% ");
		if(fgets(str, 100, stdin) == NULL){break;}
		
	 	if(fork()==0){
	 		const char delims[] = " \t\r\n\v\f";
	 		char *word;
	 		int argc = 0;
	 		char *argv[10];
	 		int i = 0;

//	 		printf("Hello world from child!\n");
	 		printf("What you wrote: %s", str);
				 
			word =  strtok(str, delims);

			/* walk through other tokens */
	   		while(word != NULL){ 					//Keep parsing until end of input is reached, ie. pointer = NULL
      			argv[i] = malloc(strlen(word) + 1);
      			strcpy(argv[i], word);
      			printf("Printing out argv[%d]: %s\n", argc, argv[i]);
      			i++;
      			argc++;
	      		word = strtok(NULL, delims);				//Continue parsing initial input
	   		}
	   		//printf("Printing out argv[%d]: %s\n", argc+1, argv[i+1]);
			execvp(argv[0], argv);
	 	}
	 	else{
	 		wait(NULL);
//	 		printf("Hello world from parent!\n");
	 	}
 	}
    return 0;
}