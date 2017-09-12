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

int main(){

	char inputchar;
	char outputline[81];
	outputline[80] = '\0';
	int i=0;

	while(scanf("%c", &inputchar) != EOF){			//scan in character one at a time, add to output array
													
		if(inputchar == '*'){						//change '**' -> '^'
			scanf("%c", &inputchar);
			if(inputchar == '*'){
				outputline[i] = '^';
				i++;
			}
			else{
				outputline[i] = '*';				//if no '**', keep '*'
				i++;
				if(i == sizeof(outputline) - 1){	//check if array is filled and ready to print
					printf("%80s\n", outputline);
					i=0;
				}
				if(inputchar == '\n'){
					outputline[i] = ' ';
					i++;
				}
				else{
					outputline[i] = inputchar;		//add character proceeding single '*'
					i++;
				}
			}
		}
		else if(inputchar == '\n'){					//change '\n' -> ' '
			outputline[i] = ' ';
			i++;
		}
		else{
			outputline[i] = inputchar;
			i++;
		}	

		if(i == sizeof(outputline)-1){				//fill array until 80 chars have been reached, then print
			printf("%80s\n", outputline);
			i=0;
		}
	}

	return 1;
}