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
	FILE *file_ptr = fopen(filename, "w");
	
	int ret = get_histogram( file_ptr, 
	                         hist, 
	                         block_size,
	                         &milliseconds,
	                         &filelen);
	assert(! ret < 0)
	 
	printf("%d ms.\n", milliseconds);
	printf("%d Bytes of BLOCK SIZE\n", milliseconds);
	printf("%d Bytes of TOTAL BYTES\n", milliseconds);

	for(int i=0; i < 26; i++) {
	    printf("%c : %d\n", 'A' + i, hist[i]);
	}
	printf("Data rate: %f Bps\n", (double)filelen/milliseconds * 1000);

	return 0;
}