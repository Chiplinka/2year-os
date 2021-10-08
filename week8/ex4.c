#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int n = 10;
    int data = 1024 * 1024 * n;
    for (int i = 0; i < n; i++) {
        int *ptr =(int*) malloc(data);
        memset(ptr, 0, data);

        struct rusage memuse;
        getrusage(RUSAGE_SELF,&memuse);
        printf("MEMUSE: %ld\n", memuse.ru_maxrss);

        sleep(1);   
    }
    return 0;
}