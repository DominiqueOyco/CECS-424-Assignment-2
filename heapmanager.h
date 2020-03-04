//CECS 424 ASSIGNMENT 2
//heapmanager.h
//Dominique Oyco (014605758)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Declaring the global variables
extern const int OVERHEAD_SIZE;					//The size of the overhead
extern const int VP_SIZE;						//The size of the void pointer

//prototypes
void my_initialize_heap (int size);
void* my_malloc (int size);
void my_free(void *data);