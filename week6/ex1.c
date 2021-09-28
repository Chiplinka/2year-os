#include <stdio.h>
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

int n = 0;
process p[10];

void readFromFile(const char *s){
    FILE *inp = fopen(s, "r");
    int at = 0, bt = 0;
    while (fscanf(inp, "%d,%d", &at, &bt) == 2){
        p[n].arrival = at;
        p[n].burst = bt;
        n++;
    }
}

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(struct process arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j].arrival > arr[j+1].arrival)
                swap(&arr[j], &arr[j+1]);
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



int main(int argc, char *argv[]) {
    readFromFile("input_ex1.csv");
    bubbleSort(p, n);

    int compl_sum = 0;
    double avg_tat = 0;
    double avg_wait = 0;
    for(int i = 0;i<n;i++){
        p[i].number = i;
        compl_sum = compl_sum+p[i].burst;
        p[i].compl_time = compl_sum;
        p[i].ta_time = p[i].compl_time-p[i].arrival;

        p[i].w_time = p[i].ta_time-p[i].burst;
        if(p[i].w_time<0){
            p[i].w_time = 0;
        }
        avg_tat+=(double)p[i].ta_time;
        avg_wait+=(double)p[i].w_time;
    }
    avg_wait = avg_wait/(double)n;
    avg_tat = avg_tat/(double)n;

    printArray(p,n);
     printf("Average Turnaround Time: %f",avg_tat);
    printf("\nAverage WT: %f\n",avg_wait);

}