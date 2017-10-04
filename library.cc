#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/timeb.h>
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

/**
 * file_ptr : the file pointer, ready to be read from.
 * hist: an array to hold 26 long integers.  hist[0] is the
 *       number of 'A', and hist[1] is the number of 'B', etc.
 * block_size: the buffer size to be used.
 * milliseconds: time it took to complete the file scan
 * total_bytes_read: the amount data in bytes read
 *
 * returns: -1 if there is an error.
 */
int get_histogram(
    FILE *file_ptr, 
    long hist[], 
    int block_size, 
    long *milliseconds, 
    long *total_bytes_read){

	fseek(file_ptr, 0, SEEK_END);
	*total_bytes_read = (unsigned long) ftell(file_ptr);
	fseek(from_file, 0, SEEK_SET);//go back to the beginning of the file
	struct timeb t;
	ftime(&t);
	long start_in_ms = t.time * 1000 + t.millitm;

	char buffer[block_size];

	long bytes_done = 0;
	long bytes_to_read = 0;
	int i;
	while (bytes_done < *total_bytes_read){
		memset(&buffer, 0, block_size);
		if (*total_bytes_read - bytes_done < block_size){

			bytes_done = *total_bytes_read;
			bytes_to_read = *total_bytes_read - bytes_done;
			fread(buffer, 1, bytes_to_read, file_ptr);

		} else {
			bytes_done = bytes_done + block_size;
			bytes_to_read = block_size;
			fread(buffer, 1, bytes_to_read, file_ptr);

		}
		for (i = 0; i < bytes_to_read; i++){
			hist[buffer[i] - 'A'] += 1;
		}
	}
	ftime(&t);
	long end_in_ms = t.time * 1000 + t.millitm;
	*milliseconds = end_in_ms - start_in_ms;

	return 0;
}
