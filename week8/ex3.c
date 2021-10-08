#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>

int main() {
    //Task 3: VIRT and RES memory  usage increases and %MEM increases
	int n = 50;
	int mult = 10 * 1024 * 1024;
    for (int i = 0; i < n; i++) {
        int * ptr = (int*)malloc(mult);
        memset(ptr, 0, mult);
        sleep(1);
    }   

    return 0;
}