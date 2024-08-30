/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief This file is the implementation file that will perform the statistal analysis requested in the first assignment on Introduction to Embedded Systems.
 *
 * <Add Extended Description Here>
 *
 * @author David Vega
 * @date 08-28-2024
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  printf("\n");
  printf("Array Unsorted: ");
  print_array(test, SIZE);
  printf("Array Sorted: ");
  sort_array(test, SIZE);
  print_array(test, SIZE);
  printf("\n");
  printf("Array Statistics:");
  print_statistics(test, SIZE);
  printf("\n");
}

/* Add other Implementation File Code Here */
void print_statistics( unsigned char array_data[], unsigned int size)
{
	printf("\n");
	printf("Median of array is: %d", find_median( array_data, size ));
	printf("\n");
	printf("Mean of array is: %d", find_mean( array_data, size ));
	printf("\n");
	printf("Maximum of array is: %d", find_maximum( array_data, size ));
	printf("\n");
	printf("Minimum of array is: %d", find_minimum( array_data, size ));
	printf("\n");
}
void print_array( unsigned char array_data[], unsigned int size )
{
	for( int i=0; i<size; i++ ){
		printf("%d ", array_data[i]);
	}
	printf("\n");
}
unsigned char find_median( unsigned char array_data[], unsigned int size )
{
	
	sort_array(array_data, size); //sorting first before finding the median
	
	unsigned char median;

	if( size%2 == 0)
		median = ( array_data[size/2] + array_data[size/2+1] )/2.0;
	else
		median = array_data[size/2 + 1];
	
	return median;
}
unsigned char find_mean( unsigned char array_data[], unsigned int size )
{
	unsigned char sum=0, mean= 0;
	for ( int i=0; i<size; i++ ){
		sum = sum + array_data[i];
	}
	
	mean = sum/2;

	return mean;
}
unsigned char find_maximum( unsigned char array_data[], unsigned int size )
{
	unsigned char max = array_data[0];

	for (int i=0; i<size; i++){
		if( max < array_data[i] )
			max = array_data[i];
	}
	return max;
}
unsigned char find_minimum( unsigned char array_data[], unsigned int size )
{
	unsigned char min = array_data[0];

	for (int i=0; i<size; i++){
		if( min > array_data[i] )
			min = array_data[i];
	}
	return min;
}
void sort_array( unsigned char array_data[], unsigned int size )
{
	int temp;
	for(int i=0; i<=size-1; i++){
		for(int j=0; j<size-i-1; j++){
			if(array_data[j] <= array_data[j+1]){
				temp = array_data[j];
				array_data[j] = array_data[j+1];
				array_data[j+1] = temp;
			}
		}		
	}
}
