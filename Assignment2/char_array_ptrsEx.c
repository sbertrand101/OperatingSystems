#include<stdio.h>
#include<string.h>

void printSomething(char *p)
{
    printf("p: %s",p);
    return;
}

int main(){
	char *p = "hello";
	char m[] = "hello";

	printSomething(p);

	printSomething(m);			//These two are essentially the same. "Arrays decay into pointers"
	printSomething(&m[0]);

	printf("%s", p);
//	printf("%s", *p);			printf wants type char *, not type char

	printf("%s", m);
	printf("%s", &m[0]);
	return 0;
}

