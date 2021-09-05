#include <stdio.h>
#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

void bubble_sort(int arr[], int arr_len);
void swap(int *a, int *b);
void print_array(int arr[], int arr_size);

void bubble_sort(int arr[], int arr_len){
    for(int i =0;i < arr_len; i++){
        for(int j = 0; j < arr_len - 1; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void print_array(int arr[], int arr_size){
    for(int i = 0; i < arr_size; i++)
        printf("%d\n", arr[i]);
}


int main() {
    int a[7] = {9,2,5,2,4,8,4};
    printf("%s\n", "Initial array:");
    print_array(a, ARR_SIZE(a));
    bubble_sort(a,ARR_SIZE(a));
    printf("%s\n", "Array after bubble sort:");
    print_array(a, ARR_SIZE(a));
    return 0;
}
