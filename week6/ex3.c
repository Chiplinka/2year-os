#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

typedef struct process{
    int number;
    int arrival;
    int burst;
    int compl_time;
    int ta_time;
    int w_time;

} process;

int proc_number= 0;
process p[10];

void readFromFile(const char *s){
    FILE *inp = fopen(s, "r");
    int at = 0, bt = 0;
    while (fscanf(inp, "%d,%d", &at, &bt) == 2){
        p[proc_number].arrival = at;
        p[proc_number].burst = bt;
        proc_number++;
    }
}


    

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}



void printArray(struct process arr[], int size)
{
    int i;
    printf("P#  %5s %5s %5s %5s %5s\n", "AT", "BT", "CT", "TAT", "WT");
    for (i=0; i < size; i++){
        printf("P%-2d %5d %5d %5d %5d %5d\n",
                arr[i].number,arr[i].arrival,arr[i].burst,
                arr[i].compl_time,arr[i].ta_time,arr[i].w_time);
    }
}


bool isDone(int arr[], int size){

    for(int i = 0;i<size;i++){
        if(arr!=0){return false;}
    }
    return true;


}


int main(int argc, char *argv[]) {
    readFromFile("input_ex3.csv");
    int quantum = 0;
    quantum = atoi(argv[1]);

    int time= 0;
    int w_time[proc_number];
    int b_rem[proc_number];
    for(int i = 0;i<proc_number;i++){
        b_rem[i] = p[i].burst;
        w_time[i] = 0;
    }

    while(1){

        int flag  = 0;
        for(int i = 0;i<proc_number;i++){

            if(b_rem[i]>0 && time>=p[i].arrival){

                if(b_rem[i]>quantum){
                    time+=quantum;
                    b_rem[i]-=quantum;
                }else{
                    time += b_rem[i];
                    w_time[i] = time - p[i].burst -p[i].arrival;
                    b_rem[i] = 0;
                }

                flag = 1;
            }
        }
        if(flag==0){
            break;
        }
    }

    double avg_tat = 0;
    double avg_wait = 0;
    for(int i = 0;i<proc_number;i++){
        p[i].number = i;


        p[i].w_time =w_time[i];
        p[i].ta_time = w_time[i]+p[i].burst;
        p[i].compl_time = p[i].ta_time+p[i].arrival;

        if(p[i].w_time<0){
            p[i].w_time = 0;
        }
        avg_tat+=(double)p[i].ta_time;
        avg_wait+=(double)p[i].w_time;
    }







    avg_wait = avg_wait/(double)proc_number;
    avg_tat = avg_tat/(double)proc_number;

    printArray(p,proc_number);
    printf("Average TAT: %f",avg_tat);
    printf("\nAverage WT: %f\n",avg_wait);
   

}