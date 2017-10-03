CC = g++
all: library.o create_random_file get_histogram

library.o: library.cc library.h
	$(CC) -o library.o -c library.cc
 
create_random_file: create_random_file.cc library.o
	$(CC) -o $@ $< library.o
 
get_histogram: get_histogram.cc library.o
	$(CC) -o $@ $< library.o