//CECS 424 ASSIGNMENT 2
//heapmanager.c
//Dominique Oyco (014605758)

#include "heapmanager.h"

// memory block
struct Block 
{
	int block_size;												// # of bytes in the data section
	struct Block *next_block; 									// pointer to the next block
};

const int OVERHEAD_SIZE = sizeof(struct Block);					//The size of the overhead
const int VP_SIZE = sizeof(void*);								//The size of the void pointer

struct Block *free_head;										//global pointer that always point to the first free block in the free list.

/*
uses malloc to initialize a buffer of the given size to use in your custom allocator.
param: size - the size of the buffer
*/
void my_initialize_heap (int size)
{
	free_head = malloc(size);									//initialize the buffer of a given size in the custom allocator
	free_head->block_size = size - OVERHEAD_SIZE; 				//initial block size
	free_head->next_block = NULL;								//next block is set to 0
}

/*
fills an allocation request based on the byte size 
and returns a pointer to the data portion of the block used to satisfy the request
param: size - the size of the buffer
*/
void* my_malloc (int size)
{
	int targetSize = ceil(size + OVERHEAD_SIZE);				//the

	//Initializing pointers
	struct Block *currentBlock = free_head; 					//The iterator for the free head
	struct Block *next_block;									//
	struct Block *new_block;									//

	while (currentBlock)
	{
		if (currentBlock->block_size >= targetSize)
		{
			int extraMem = currentBlock->block_size - targetSize;	//size of free block - size of space for allocation

			//Need to determine if the extra memory can support a new block
			if (extraMem > OVERHEAD_SIZE) 
			{
				//this block of code inserts a new block only if excess memory > size of
				//the overhead
				new_block = (struct Block *)((char *)(currentBlock + 1) + extraMem);
				new_block->block_size = size;
				new_block->next_block = NULL;

				currentBlock = currentBlock->next_block;

				return (void*)(new_block + 1);
			}

			else
			{
				currentBlock = currentBlock->next_block;

				return (void*)(currentBlock + 1);
			}

		}

		else if (currentBlock->block_size < targetSize)
		{
			currentBlock = currentBlock->next_block;
		}

		else
		{
			return NULL;
		}
	}
}

/*
Deallocates a value allocated in the data heap by finding the block 
with the data pointer and moving backwards in memory to find the block's
overhead information.
param: data - the pointer to the data portion of the block
*/
void my_free(void *data)
{ 
	struct Block *currentBlock = ((struct Block *)data - 1);					//calculating the offset of the block from the beginning of the block struct
	currentBlock->next_block = free_head;										//The next pointer points to the head's next block
	free_head = currentBlock;													//The pointer of the free head will be pointed to the block that is being freed
}