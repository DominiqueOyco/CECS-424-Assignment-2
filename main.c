//CECS 424 ASSIGNMENT 2
//main.c
//Dominique Oyco (014605758)

#include "standarddeviation.h"
#include "heapmanager.h"
#include <stdio.h>
#include <math.h>

//Allocates an int; prints the address of the returned pointer. Frees the int, then allocate
//another int and print its address. 
void testCase1(){
	my_initialize_heap(10000);
	printf("\nFirst Test: Allocate An Int Value\n\n");
	int *p = my_malloc(sizeof(int));
	int *q = my_malloc(sizeof(int));
	printf("The address of the int pointer is: %p\n", p);
	my_free(p);
	printf("The address of another int pointer is: %p\n\n", q);
}

//Allocates two individual int values and print their addresses; Values are exactly the size
//of the overhead plus the size of a void* apart.
void testCase2(){
	my_initialize_heap(10000);
	printf("\nSecond Test: Allocate Two Individual Int Values\n\n");
	int *r, *s;
	r = my_malloc(sizeof(int));
	s = my_malloc(sizeof(int));
	printf("The address of the 1st int pointer is: %p\n", r);
	printf("The address of the 2nd int pointer is: %p\n", s);
	printf("The Size of overhead + int: %lu \n\n", OVERHEAD_SIZE + sizeof(int));
}

//Allocates three int values and print their addresses, then frees the second of the three.
//Also allocates a double and print its address
void testCase3(){
	my_initialize_heap(10000);
	printf("\nThird Test: Allocate An Three Int Values & a Double Value\n\n");
	int *t, *u, *v;
	t = my_malloc(sizeof(int));
	u = my_malloc(sizeof(int));
	v = my_malloc(sizeof(int));
	printf("The address of the 1st int pointer is: %p\n", t);
	printf("The address of the 2nd int pointer is: %p\n", u);
	printf("The address of the 3rd int pointer is: %p\n", v);
	my_free(u);
	double *w;
	w = my_malloc(sizeof(double));
	printf("The address of the double pointer is: %p\n", w);
	int *x = my_malloc(sizeof(int));
	printf("The address of int pointer: %p\n\n", w);
}

//Allocates one char, then allocate one int, and prints their addresses. 
void testCase4(){
	my_initialize_heap(10000);
	printf("\nFourth Test: Allocate An Int Pointer\n\n");
	char *y;
	int *z;
	y = my_malloc(sizeof(char));
	z = my_malloc(sizeof(int));
	printf("The address of the char pointer: %p\n", y);
	printf("The address of the int pointer:  %p\n\n", z);
}

//Allocates space for a 100-element int array, then for one more int value. 
void testCase5(){
	my_initialize_heap(10000);
	printf("\nFifth Test: Allocate An Int Pointer\n\n");
	int *newArray = my_malloc(100*sizeof(int));
	int *k = my_malloc(sizeof(int));
	*k = 13;
	printf("The address of the new array is: %p\n", newArray);
	printf("Address of int: %p\n", k);
	printf("Value of int: %d\n", *k);
	my_free(newArray);
	printf("Address of int: %p\n", k);
	printf("Value of int: %d\n\n", *k);
}

void testCases(int choice){
	switch(choice){
		case 1: 
			testCase1();
      		break;

		case 2:
			testCase2();
			break;

		case 3:
			testCase3();
      		break;

		case 4:
			testCase4();
			printf("Comparing with Test Case 2...\n");
			testCase2();
      		break;

		case 5:
			testCase5();
      		break;

	}
}

void stdSolver(int *b, int n){
	my_initialize_heap(10000);

	//call the calculateStdDeviation method from the standarddeviation class
	//to calculate the standard deviation
	double stdDeviation = calculateStdDeviation(b, n);	

	//Print the standard deviation
	printf("The standard deviation is : %f ", stdDeviation);
}

int main() {
    /*
    TESTING THE HEAP MANAGER
    */
	int caseValue;
	printf("Testing cases for the heap manager\n");
	printf("Please enter a case to test (1-5): ");
	scanf("%d", &caseValue);

	testCases(caseValue);


    /*
    TESTING THE STANDARD DEVIATION PROBLEM
    */
	int    arrSize = 0;
	double stdDeviation = 0;

	//Get the size of the array
	printf("Please enter the size of the array: ");
	scanf("%d", &arrSize);

	//Allocate space for an array of integers
	int *stdDevArray = my_malloc(arrSize * sizeof(int));

	//Read integers into the array
	for (int i = 0; i < arrSize; i++)
	{
		printf("Please enter an integer to put into the array: ");
		scanf("%d", &stdDevArray[i]);
	}

	stdSolver(stdDevArray, arrSize);
	return 0;
}