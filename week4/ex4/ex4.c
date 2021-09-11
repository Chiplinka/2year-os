#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        char str[128];
        char *argv[4];
        argv[0] = "/bin/sh";
        argv[1] = "-c";
        argv[3] = NULL;
        int  status;
        for(;;){
            fgets(str, 127, stdin);
            int f = fork();
            if(f == 0){
                argv[2] = str;
                execvp("/bin/sh", argv);
            }else{
                while(wait(&status) != f);
            }
            
        }
    return 0;
}   