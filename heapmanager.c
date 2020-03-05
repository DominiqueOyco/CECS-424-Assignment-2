//CECS 424 ASSIGNMENT 2
//heapmanager.c
//Dominique Oyco (014605758)

#include "heapmanager.h"

//memory block
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
	//The data size must be a multiple of (void*) size. Have to take the ceiling of the data size/void pointer size
	//to know which multiple of (void*) to use
	int targetSize = (int) ceil((size + OVERHEAD_SIZE) / (double) VP_SIZE) * VP_SIZE;	//MEM ALLOCATION REQUEST segmented into multiples of the void pointer rounded up

	//Initializing pointers
	struct Block *currentBlock = free_head; 					//The iterator for the free head
	struct Block *next_block;									
	struct Block *new_block;									

	while (currentBlock)
	{
		if (currentBlock->block_size >= targetSize)
		{
			int extraMem = currentBlock->block_size - targetSize;						//size of free block - size of space for allocation

			//Determine if the extra memory can support a new block. If yes, then split 
			if (extraMem > OVERHEAD_SIZE) 
			{
				new_block = (struct Block *)((char *)(currentBlock + 1) + extraMem);	//Finding the location of new block based on size that needed to split & allocation request
				new_block->block_size = size;											//initializing new block by pointing new block to the new block size
				new_block->next_block = NULL;											//set next_block pointer to null

				currentBlock = currentBlock->next_block;								//Make the current block redirect pointer to the nextblock

				return (void*)(new_block + 1);											//Return a pointer to the data region of the block, which is “overhead size” bytes past
																						//the start of the block.
			}

			//Then redirect pointers to the block to point to the block that follows it if the remaining memory is <= the size of the overhead
			else
			{
				currentBlock = currentBlock->next_block;

				return (void*)(currentBlock + 1);
			}

		}

		//If you the block cannot be split, then redirect pointers to the block to point to the block that follows it.
		else if (currentBlock->block_size < targetSize)
		{
			currentBlock = currentBlock->next_block;
		}

		//If no blocks can be found, return NULL
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