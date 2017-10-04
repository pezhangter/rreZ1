void random_array(char *array, long bytes);
int get_histogram(
    FILE *file_ptr, 
    long hist[], 
    int block_size, 
    long *milliseconds, 
    long *total_bytes_read);