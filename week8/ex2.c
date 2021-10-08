#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>

int main() {
    //free memory amount is decreasing, si = 0 and so is not 0 at some time    
	int n = 30;
	int mult = 1000 * 1024 * 1024;
    for (int i = 0; i < n; i++) {
        int * ptr = (int*)malloc(mult);
        memset(ptr, 0, mult);
        sleep(1);
    }

    return 0;
}