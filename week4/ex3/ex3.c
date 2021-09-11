#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int f = fork();
    if(f == 0){
        char str[128];
        for(;;){
            fgets(str, 127, stdin);
            system(str);
        }
    }
    return 0;
}   
