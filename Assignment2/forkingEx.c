#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>


void forkexample(int argc, char *argv[]) 
{
	while(1){
	    // child process because return value zero
	    if (fork()==0){
	        printf("Hello from Child!\n");

	    	printf("%s\n", argv[0]);
	    	printf("%s\n", argv[1]);
	 	}
	    // parent process because return value non-zero.
	    else{    
	    	wait(NULL);
	        printf("Hello from Parent!\n"); 
	    }
	}        
}

int main(int argc, char *argv[])
{ 
    forkexample(argc, argv);
    return 0; 
}
