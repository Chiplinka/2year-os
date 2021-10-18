#include <stdio.h>
#include <stdint.h>

typedef struct page{
    int id;
    uint16_t age;
} page;

int n=0;
float miss=0, hit=0;
page frames[100000];
int curr;
int validReading =0;

int findPage(int pageId, int n){
    for(int i=0; i<n; i++){
        if(frames[i].id == pageId) return i;
    }
    return -1;
}

int main(){    
    printf("Specify number of page frames:\n");
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        frames[i].id = -1;
        frames[i].age = 0;
    }
    FILE* input_file = fopen("input.txt", "r");
    FILE* output = fopen("ex1_output1.txt", "w");
    while(!feof(input_file)){
        if(fscanf(input_file, "%d", &curr) == -1) break;
        for(int i=0; i<n; i++){
          fprintf(output, "i = %d  id = %d age = %d\n", i, frames[i].id, frames[i].age);
        }
        fprintf(output, "current page number %d\n\n", curr);
        for(int i=0; i<n; i++){
            frames[i].age >>=1;
        }
        if(findPage(curr, n) == -1){
            miss++;
            int chosenPage = -1;
            for(int i=0; i<n; i++){
                if(frames[i].id == -1){
                    chosenPage = i;
                }
            }
            if(chosenPage!=-1){
                frames[chosenPage].id = curr;
                frames[chosenPage].age |=1<<(sizeof(uint16_t)*8-1);
            }
            else {
                uint16_t minAge = UINT16_MAX;
                for(int i=0; i<n; i++){
                    if(minAge>=frames[i].age){
                        minAge = frames[i].age;
                        chosenPage = i;
                    }
                }
                frames[chosenPage].id = curr;
                frames[chosenPage].age = 0;
                frames[chosenPage].age |=1<<(sizeof(uint16_t)*8-1);
            }
        }
        else{
            hit++;
            frames[findPage(curr, n)].age |=1<<(sizeof(uint16_t)*8-1);
        }
    }
    printf("hit=%f miss=%f ratio=%f\n", hit, miss, (float)hit/miss);
}