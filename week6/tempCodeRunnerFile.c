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