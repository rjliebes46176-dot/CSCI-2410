/* CSCI 2410 
 * Homework 0.25
 * Sorting algorithm IMPLEMENTATION
 * ONLY MODIFY THE sorting_function FUNCTION IN THIS FILE
 * DO NOT MODIFY ANY OTHER PART OF THIS FILE or OTHER FILES
 */

#include <stdlib.h>

#include "sorting_function.h"


int sorting_function( int arr[], int count, int ascending )
{
    // Implement a sorting algorithm of your choice here
    // You can use any algorithm you like (e.g., bubble sort, selection sort, insertion sort, etc.)
    // The 'ascending' parameter indicates whether to sort in ascending (1) or descending (0) order
    // 
    // The function returns 0 on success (by default), You should return non-zero value on failure

    if (ascending==1)
    {
        printf("Ascending was 1\n");

        

        return 0 ; // Return 0 to indicate success
    }
    if (ascending==0)
    {
        printf("Ascending was 0\n");



        return 0 ; // Return 0 to indicate success
    }
    printf("Ascending was not 1 or 0\n");
    return -1; // Return -1 to indicate failure
}
