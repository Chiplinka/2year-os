#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* function_message(void *args) {
	int i = *((int *)args);
    printf("Hello from thread %d!\n",i);
}

int main() {
    
    int n = 10; /* Number of threads */
 	for(int i = 0;i<n;i++){
		pthread_t thread;
    	int *b = malloc(sizeof(int));
    	*b = i;
    	pthread_create(&thread, NULL, function_message, (void*) b);
    	printf("%d thread created\n",i);
    	pthread_join(thread, NULL);
        printf("Terminating of thread %d\n", i);
    }

}