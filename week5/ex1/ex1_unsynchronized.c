#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* function_message(void *args) {
	int i = *((int *)args);
    printf("Hello from thread %d!\n",i);
}

int main() {
    
    int n = 10; /* Number of threads */
    pthread_t *thread[16];
    
 	for(int i = 0;i<n;i++){
    	thread[i] = (pthread_t *) malloc(sizeof(pthread_t));
        printf("%d thread created\n",i);
        int * thread_id = (int *)malloc(sizeof(int));
        *thread_id = i;
        pthread_create(thread[i], NULL, function_message, (void *) thread_id);
    }

    for(int i= 0; i <n;i++){
        pthread_join(*thread[i], NULL);
        printf("Terminating of thread %d\n", i);
    }

}