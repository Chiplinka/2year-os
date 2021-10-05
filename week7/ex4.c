#include <stdlib.h>
#include <stdio.h>

void * reallocate(void *ptr, size_t size){
    if (ptr == NULL)
		return malloc(size);
	if (size == 0){
		free(ptr);
		return NULL;
	}       
    void* ptr_temp = ptr;
	ptr = malloc(size * sizeof(int));
	memcpy(ptr, ptr_temp, size);
    return ptr;  
}
        
int main(){
    int n,n2;
    printf("Enter size of array\n");
    scanf("%d", &n);
	int* ptr = (int*)malloc(n * sizeof(int));

	printf("Initial: ");
	for (int i = 0; i < n; i++){
		ptr[i] = i;
		printf("%d ", ptr[i]);
	}
    printf("\n");
    printf("Enter new size of array\n");
    scanf("%d", &n2);
	ptr = (int*) reallocate(ptr, n2 * sizeof(int));

    if(n2 > n){
        for (int i = n; i < n2; i++)
			ptr[i] = 0;
    }
	printf("Reallocation: ");
	for (int i = 0; i < n2; i++)
		printf("%d ", ptr[i]);
    return 0;
}