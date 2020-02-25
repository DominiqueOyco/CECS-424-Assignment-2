#include <stdio.h>
#include <stdlib.h>

const int OVERHEAD_SIZE = sizeof(struct Block);				//the size of the overhead

const int VP_SIZE = sizeof(void*);							//the size of the void pointer

Block *free_head;											//Global pointer to Block at head of free list

struct Block {
	int block_size; 										// # of bytes in the data section
 	struct Block *next_block; 								// pointer to the next block
};
// The data section follows in memory after the above struct.

void my_initialize_heap(int size){
	free_head = (Block *)malloc(size);						//use malloc to initalize the buffer of a give size

	free_head->block_size = size - OVERHEAD_SIZE;			

	free_head->next_block = null;

	free_head->data = ((char*)free_head + OVERHEAD_SIZE);
}

void* my_malloc(int size){

}

void* my_free(void data){

}




