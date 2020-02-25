#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int OVERHEAD_SIZE = sizeof(struct Block);				//the size of the overhead

const int VP_SIZE = sizeof(void*);							//the size of the void pointer

Block *free_head;											//Global pointer that points to the first free block in the free list

struct Block {
	int block_size; 										//# of bytes in the data section
 	struct Block *next_block; 								//pointer to the next block
};
// The data section follows in memory after the above struct.

void my_initialize_heap(int size){
	free_head = (Block *)malloc(size);						//use malloc to initalize the buffer of a give size
	free_head->block_size = size - OVERHEAD_SIZE;			//this sets the initialize size for the block size
	free_head->next_block = null;							//sets the next block to null because 
	free_head->data = ((char*)free_head + OVERHEAD_SIZE);	//this initializes the data pointer
}

void* my_malloc(int size){

}


//Implementation of free(). Deallocates a value that was allocated in the data heap 
//The pointer will be to the data portion of a block; moves backwards in memory to find
//the block's overhead information, and then link it into the free list.
void my_free(void data){
	Block *currentBlock = (Block *)((char*)data - OVERHEAD_SIZE);
	currBlock->next_block = free_head;
	free_head = currBlock;
}




