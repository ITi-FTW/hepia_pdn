#include <stdio.h>               
#include <string.h>                                     
#include <stdlib.h> 
#include <pthread.h>

unsigned int arrNumbers[25];
unsigned int SUM = 0;


void *sum(void *sizeOfArray) {
	
	// Init
	int tmp = *((int *) sizeOfArray);
   	
	// Display
	printf("=====================\n");
	printf("SUM\n");
	printf("=====================\n");
	
	// Sum of the user input
	for (int j=0; j < tmp; j++)
	{
		printf("Numéro : %d - SUM : %d\n", j, SUM);
		printf("Valeur : %d", arrNumbers[j]);
		SUM += arrNumbers[j];
	}

	return NULL; 
} 

int main(int argc, char **argv) { 
		
	if (argc > 1) {
				
		for(int i=1; i < argc; i++)
		{
			arrNumbers[i-2] = atoi(argv[i]); 
		}

		// Init
    	pthread_t thread;
		unsigned int *sizeOfArray = (unsigned int *)malloc(sizeof(unsigned int));

		*sizeOfArray = argc;
	
		// Create the thread
    	int code = pthread_create(&thread, NULL, sum, sizeOfArray);
		if (code != 0) {
    		fprintf(stderr, "pthread_create failed!\n");
       		return EXIT_FAILURE;
   		}
		
		// Sleep the main process
		pthread_join(thread, NULL);
		
		// Display the sum of the array
		printf("=====================\n");
		printf("Somme du tableau : %d\n", SUM);
		printf("=====================\n");
	
    	return EXIT_SUCCESS; 
	} else {
		fprintf(stderr, "Please provide arguments !\n");
		return EXIT_FAILURE;
	}
}
