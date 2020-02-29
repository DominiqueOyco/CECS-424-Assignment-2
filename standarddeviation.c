//CECS 424 ASSIGNMENT 2
//standarddeviation.c
//Dominique Oyco (014605758)

#include <stdlib.h>
#include <math.h>

/*
This function calculates the mean of numbers
param: a - the integer array
param: n - the length of the array
*/
double calculateMean(int *a, int n)
{
	//initializing variables
	double mean = 0;
	double total = 0;

	//to get the mean of numbers, add them up to get the sum and divide the sum by the length of the all the numbers added
	for (int i = 0; i < n; i++)
	{
		total = total + a[i];
	}

	//Get the mean by dividing the sum by the total number of integers
	mean = total / (double)n;

	return mean;
}

/*
This function calculates the standard deviation using the formula
	sqrt( 1/n * summation(( xi - u )^2), 1 to n ),
where xi are the integers, u is the mean, and n is the size of the array
param: a - the integer array
param: n - the length of the array
*/
double calculateStdDeviation(int *a, int n)
{
	//initializing variables
	double u = calculateMean(a, n); 						//get the mean of the numbers in the array 
	double summation = 0;
	double stdDev = 0;

	//Calculating the summation of ( xi - u )^2
	for (int i = 0; i < n; i++)
	{
		summation = summation + pow(a[i] - u, 2);			//pow is a built in double function that allows you to get the square of a number
	}

	//Get the standard deviation by dividing the summation by the total number of integers
	stdDev = summation / (double)n;
	stdDev = sqrt(stdDev);

	return stdDev;
}