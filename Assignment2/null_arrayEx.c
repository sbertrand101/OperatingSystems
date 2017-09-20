#include<stdio.h>
#include<string.h>

#define MAX_INPUT_CHAR 10


int main(){
	char *p[MAX_INPUT_CHAR] = {NULL};

	for (int i=0; i<MAX_INPUT_CHAR; i++){
		printf("%s", p[i]);
	}

	return 0;
}
