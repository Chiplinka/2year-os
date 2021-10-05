#include <stdio.h>
#include<stdlib.h>

int main() {
	
    char** s = (char**)malloc(sizeof(char*));
    //memory have' not been allocated for array of chars in initial version of the program
	
    char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n", s);
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return(0);
}