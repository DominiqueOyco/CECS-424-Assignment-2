#include "stdbool.h"
#include <math.h>

/*
This function calculates the mean of numbers
param: a - the integer array
param: n - the length of the array
*/
double calculateMean(int *a, int n)
{
	double mean = 0;
	double total = 0;

	//to get the mean of numbers, add them up to get the sum and divide the sum by the length of the all the numbers added
	for (int i = 0; i < n; i++)
	{
		total = total + a[i];
	}

	//Second, divide by the total number of integers
	mean = sum / (double)length;

	return mean;
}

/*
This function calculates the standard deviation using the formula
	sqrt( 1/n * summation(( xi - u )^2), 1 to n ),
where xi are the integers, u is the arithmetic mean, and n is the size of the array
param: a - the integer array
param: n - the length of the array
*/
double calculateStdDeviation(int *a, int n)
{
	// Calculate standard deviation of integers
	//   Formula:
	//   sqrt( 1/n * summation(( xi - u )^2), 1 to n ),
	//   where xi = integers entered and u = total arithmetic mean
	//   and n is the size of the array

	double mean = calculateMean(array, length);
	double summation = 0;
	double stdDev = 0;

	//First calculate summation(( xi - u )^2)
	for (int i = 0; i < length; i++)
	{
		summation = summation + (array[i] - mean)*(array[i] - mean);
	}

	//Calculate the standard deviation
	stdDev = summation / (double)length;
	stdDev = sqrt(stdDev);

	return stdDev;
}