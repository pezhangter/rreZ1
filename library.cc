#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * populate a random array (which is already
 * allocated with enough memory to hold n bytes.
 */
void random_array(char *array, long bytes){
	time_t t;
	srand((unsigned) time(&t));

	int i;
	for (i = 0; i < bytes; i++){
		char c = 'A' + (rand() % 26);
		array[i] = c;
	}
}

