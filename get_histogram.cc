#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include "library.h"

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	long block_size = strtol(argv[2], NULL, 10);

	long hist[26];
	long milliseconds;
	long filelen;

	FILE *file_ptr = fopen(filename, "r");
	 
	int i;
	for (i = 0; i < 26; i++){
		hist[i] = 0;
	}

	int ret = get_histogram( file_ptr, 
	                         hist, 
	                         block_size,
	                         &milliseconds,
	                         &filelen);
	 
	printf("%ld ms.\n", milliseconds);
	printf("%ld Bytes of BLOCK SIZE\n", block_size);
	printf("%ld Bytes of TOTAL BYTES\n", filelen);

	for(int i=0; i < 26; i++) {
	    printf("%c : %d\n", 'A' + i, hist[i]);
	}
	printf("Data rate: %f Bps\n", (double)filelen/milliseconds * 1000);

	return 0;
}