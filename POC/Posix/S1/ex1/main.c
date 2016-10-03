#include <stdio.h>               
#include <string.h>                                     
#include <stdlib.h> 
#include <pthread.h>

#define NUM_THREADS 16

void *thread(void *thread_id) {
    int id = *((int *) thread_id);
    printf("Hello from thread %d\n", id);
	free(thread_id);
    return NULL; 
} 

int main() { 
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
		int *id = (int *)malloc(sizeof(int));
		*id = i;
        int code = pthread_create(&threads[i], NULL, thread, id);
        if (code != 0) {
            fprintf(stderr, "pthread_create failed!\n");
            return EXIT_FAILURE;
        }
    }
	
	for (int j = 0; j < NUM_THREADS; j++){
		pthread_join(threads[j], NULL);
	}

    return EXIT_SUCCESS; 
}
