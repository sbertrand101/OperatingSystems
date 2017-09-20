#include<stdio.h>
#include<string.h>

#define MAX_INPUT_CHAR 10


int main(){
	char str[MAX_INPUT_CHAR];

	scanf("%MAX_INPUT_CHARs", str);
//	fgets(str, MAX_INPUT_CHAR, stdin);
//	sscanf(str, "%s", str);

	printf("%s", str);
	return 0;
}
