#include <stdio.h>
#include <stdlib.h>

struct Block {
	int block_size; 				// # of bytes in the data section
 	struct Block *next_block; 		// pointer to the next block
};
// The data section follows in memory after the above struct.

//overhead size
const int struct_SIZE = sizeof(struct Block);

//size of a void pointer
const int VP_SIZE = sizeof(void*);


void my_initialize_heap(int size){

}

void* my_malloc(int size){

}

void* my_free(void data){

}




