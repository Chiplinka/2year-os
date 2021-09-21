# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>  

int Buffer = 2;
int BufferSize = 10;

void *Producer(void* q){    
    while(1){
        if(Buffer>=BufferSize){
            continue;
        }           
        else{
            Buffer++;
        }   
        printf("Buffer: %d\n",Buffer);
        sleep(1);
    }    
    
}

void *Consumer(void* q)
{
    while(1){
        if(Buffer<=0){            
           continue; 
        }                
        else{
            Buffer--;
        } 
        printf("Buffer: %d\n",Buffer);
        sleep(1);             
    }    
}

int main(){    
    pthread_t ptid,ctid;          
    pthread_create(&ptid,NULL,Producer,NULL);
    pthread_create(&ctid,NULL,Consumer,NULL);
    pthread_join(ptid,NULL);
    pthread_join(ctid,NULL);
    return 0;
}