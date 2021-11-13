#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    int rs = 3, pr = 5; // number of resource and processes
    int is_finished = 0;
    

    FILE* input_file = fopen("input_ok.txt", "r");
    FILE* output = fopen("ex1_output_ok.txt", "w");
    int curr;

    int e[rs];
    int a[rs];

    int c[pr][rs];
    int r[pr][rs];

    int ready[pr];
    for(int k = 0;k<pr;k++){
        ready[k] = 0;
    }
    int ii =0,jj = 0;
    int gg = 1;
    for(int i=0;i<rs;i++){
        fscanf(input_file, "%d", &curr);
        e[i] = curr;
        //printf("%d ", e[i]);
    }
    //printf("\n");
    for(int i=0;i<rs;i++){
        fscanf(input_file, "%d", &curr);
        a[i] = curr;
        //printf("%d ", a[i]);
    }
    //printf("\n");
    for(int i=0;i<pr;i++){
        for(int j=0;j<rs;j++){
            fscanf(input_file, "%d", &curr);
            c[i][j] = curr;
            //printf("%d ", c[i][j]);
        }
            
        //printf("\n");
    }
    //printf("\n");
    for(int i=0;i<pr;i++){
        for(int j=0;j<rs;j++){
            fscanf(input_file, "%d", &curr);
            r[i][j] = curr;
            //printf("%d ", r[i][j]);
        }
           
        //printf("\n");
    }
    //printf("\n");
    //printf("\n\n");

    int sos = 0;
    while(gg==1){
        gg = 0;
        //printf("%d %d %d\n", a[0],a[1],a[2]);
        for(int i = 0;i < pr;i++){
            sos = 0;
            for(int j = 0;j < rs;j++){
                if(r[i][j] <= a[j]){
                    sos++;
                }
            }
            if(sos == rs && ready[i] == 0){
                for(int pg = 0;pg < rs;pg++){
                    a[pg] += c[i][pg];
                } 
                gg=1; 
                //printf("Hh %d  \n", i);
                ready[i] = 1;
            }          
        }

    }
    int hgh = 1;
    for(int i = 0;i<pr;i++){
        if(ready[i] == 0){
            hgh = 0;
            fprintf(output, "Process %d deadlocked\n", i + 1);;
        }
    }
    if(hgh == 1){
        fprintf(output, "No deadlock\n");
    }
    return 0;
}