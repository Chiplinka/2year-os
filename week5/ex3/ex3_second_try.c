# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>  

int Buffer = 2;
int BufferSize = 8;
int cons_sleep = 0;
int prod_sleep = 0;
char buf[16];
int cnt = 0;

void * Consumer(void * q) {
    while(1) {
        while(cons_sleep){}
        if(cnt <= 0) {
            cons_sleep = 1;
            continue;
        }
        cnt--;
        char k = buf[cnt];
        prod_sleep = 0;
    }
}


void * Producer(void * _) {
    while(1) {
        while(prod_sleep){}
        if(cnt == 8) {
            prod_sleep = 1;
            continue;
        }
        cnt++;
        char k  = buf[cnt];
        cons_sleep = 0;
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
