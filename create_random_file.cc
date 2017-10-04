#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include "library.h"

int main(int argc, char *argv[]) {

	char *filename = argv[1];
	long total_bytes = strtol(argv[2], NULL, 10);
	long block_size = strtol(argv[3], NULL, 10);
	char buffer[block_size];

	struct timeb t;
	ftime(&t);
	long start_in_ms = t.time * 1000 + t.millitm;

	FILE *fp = fopen(filename, "w");

	long bytes_done = 0;
	while (bytes_done < total_bytes){
		memset(&buffer, 0, block_size);
		if (total_bytes - bytes_done < block_size){

			bytes_done = total_bytes;
			random_array(buffer, total_bytes - bytes_done);

		} else {
			bytes_done = bytes_done + block_size;
			random_array(buffer, block_size);

		}
		fwrite(buffer, 1, block_size, fp);
		fflush(fp);
	}
	ftime(&t);
	long end_in_ms = t.time * 1000 + t.millitm;	
	fclose(fp);


	long duration = end_in_ms - start_in_ms;

	fclose(fp);
	printf("%f Bps %ld milliseconds with a block_size of %ld and a total_bytes of %ld\n", 
		(double) total_bytes/duration * 1000,
		duration, block_size, total_bytes);

  	return 0;
}
