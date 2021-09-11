#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int a;
    int n = 777;
    int f = fork();
    if(f)
        printf("Hello from parent [%d - %d]\n",f,n);
    else
        printf("Hello from child [%d - %d]\n",f,n);
    return 0;
}