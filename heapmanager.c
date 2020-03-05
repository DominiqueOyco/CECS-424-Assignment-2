//CECS 424 ASSIGNMENT 2
//main.c
//Dominique Oyco (014605758)
#include "standarddeviation.h"
#include "heapmanager.h"
#include <stdio.h>
#include <math.h>


//ONLY NEEDS HEX!
int main() {
	
	my_initialize_heap(10000);
	//Test 1
	//-----------------------//
	printf("\n***TEST 1***\n\n");
	// int *p, *r;
	int *p = my_malloc(sizeof(int));
	printf("Address of int pointer: 0x%p in hex and %d in dec \n", p, p);
	my_free(p);
	
	int *r = my_malloc(sizeof(int));
	printf("Address of int pointer:  0x%p in hex and %d in dec \n", r, r);

	//-----------------------//
	//Test 2
	//-----------------------//
	printf("\n***TEST 2***\n\n");
	int *q, *s;
	q = my_malloc(sizeof(int));
	s = my_malloc(sizeof(int));
	printf("Address of int pointer 1: 0x%X in hex and %d in dec\n", q, q);
	printf("Address of int pointer 2: 0x%X in hex and %d in dec\n", s, s);
	printf("Size of overhead + int: %d \n", OVERHEAD_SIZE + sizeof(int));
	//-----------------------//
	//Test 3
	//-----------------------//
	printf("\n***TEST 3***\n\n");
	int *x, *t, *v;
	x = my_malloc(sizeof(int));
	t = my_malloc(sizeof(int));
	v = my_malloc(sizeof(int));
	printf("Address of int pointer 1: 0x%X in hex and %d in dec\n", x, x);
	printf("Address of int pointer 2: 0x%X in hex and %d in dec\n", t, t);
	printf("Address of int pointer 3: 0x%X in hex and %d in dec\n", v, v);
	my_free(t);
	double *y;
	y = my_malloc(sizeof(double));
	printf("Address of double pointer: 0x%X in hex and %d in dec\n", y, y);
	int *w = my_malloc(sizeof(int));
	printf("Address of int pointer: 0x%X in hex and %d in dec\n", w, w);
	//-----------------------//
	//Test 4
	//-----------------------//
	printf("\n***TEST 4***\n\n");
	char *c;
	int *z;
	c = my_malloc(sizeof(char));
	z = my_malloc(sizeof(int));
	printf("Address of char pointer: 0x%X in hex and %d in dec \n", c, c);
	printf("Address of int pointer:  0x%X in hex and %d in dec \n", z, z);
	//-----------------------//
	
	//Test 5
	//-----------------------//
	printf("\n***TEST 5***\n\n");
	int *myArray = my_malloc(100*sizeof(int));
	int *f = my_malloc(sizeof(int));
	*f = 13;
	printf("Address of array: 0x%X in hex and %d in dec \n", myArray, myArray);
	printf("Address of int: 0x%X in hex and %d in dec \n", f, f);
	printf("Value of int: %d in dec \n", *f);
	my_free(myArray);
	printf("Address of int: 0x%X in hex and %d in dec \n", f, f);
	printf("Value of int: %d in dec \n", *f);
	//-----------------------//


	//--------------------------------------//
	//---SOLVE STANDARD DEVIATION PROBLEM---//
	//--------------------------------------//


	int    numberOfIntegers = 0;
	int    currentInput = 0;
	double stdDeviation = 0;

	my_initialize_heap(10000);

	//First get user input 

	//Get the size of the array
	printf("Please enter a positive integer: ");
	scanf("%d", &numberOfIntegers);

	//Allocate space for an array of entered integers
	int *stdDevArray = my_malloc(numberOfIntegers * sizeof(int));

	//Read integers into the array
	for (int i = 0; i < numberOfIntegers; i++)
	{
		printf("Please enter an integer to put into the array: ");
		scanf("%d", &stdDevArray[i]);
	}


	// Calculate standard deviation of integers
	//   Formula:
	//   sqrt( 1/n * summation( xi - u )^2, 1 to n ),
	//   where xi = integers entered and u = total arithmetic mean
	stdDeviation = calculateStdDeviation(stdDevArray, numberOfIntegers);

	//Print the standard deviation
	printf("The standard deviation is : %f ", stdDeviation);
	

	//system("pause");

	return 0;
}