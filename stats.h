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
 * @file stats.h
 * @brief This files contains all function prototypes and function documentation that will be used in stats.c
 *
 * <Add Extended Description Here>
 *
 * @author David Vega
 * @date 08-28-2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

void print_statistics( unsigned char array_data[], unsigned int size );
void print_array( unsigned char array_data[], unsigned int size );
unsigned char find_median( unsigned char array_data[], unsigned int size );
unsigned char find_mean( unsigned char array_data[], unsigned int size );
unsigned char find_maximum( unsigned char array_data[], unsigned int size );
unsigned char find_minimum( unsigned char array_data[], unsigned int size );
void sort_array( unsigned char array_data[], unsigned int size )

/**
 * @brief print_statistics - Prints the statistics of array ( min, max, mean, mediun ).
 * @brief print_array - Prints array to screen.
 * @brief find_median - Returns median value.
 * @brief find_mean - Returns mean value.
 * @brief find maximum - Returns maximum value from array.
 * @brief find_minimum - Returns mimimum value from array.
 * @brief sort_array - Sorts the array from largest to smallest. 
 *
 * @param array_data[] - Is the pointer to first element of array.
 * @param size - Is the size of the array.
 *
 * @return void - Used when nothing needs to be returned.
 * @return unsigned char - Used when a numerical value needs to be returned.
 */


#endif /* __STATS_H__ */
