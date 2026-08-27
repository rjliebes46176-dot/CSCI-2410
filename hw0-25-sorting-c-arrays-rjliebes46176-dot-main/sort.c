/* CSCI 2410 
 * Homework 0.25
 * Basic Sorting Algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper_functions.h"
#include "sorting_function.h"

int main( int argc, char* argv[] )
{
    // first, call the function to parse the input arguments 
    // from the command line 
    InputArgs* input_args = parse_input_args( argc, argv ) ;

    // did it fail? 
    // if so, print an error message and exit the program
    if ( input_args == NULL )
    {
        printf("Failed to parse input arguments\n");
        return -1 ;
    } 

    // this is where will store the input values
    // i.e., the numbers to be sorted
    // read the array from the input file
    int* input_array = NULL ;
    int count = read_array( input_args->_input_file, &input_array ) ;

    // call the SORTING function -- YOUR CODE!
    int status = sorting_function( input_array, count, input_args->_ascending ) ;

    // did the sorting function fail?
    if( status )
    {
        printf(" Sorting function failed!!!\n ") ;

        fclose( input_args->_input_file ) ;
        fclose( input_args->_output_file ) ;

        free( input_array ) ;
        free( input_args ) ; 

        return -1 ;
    }

    // verify if the array is ACTUALLY SORTED
    int sorted = is_sorted( input_array, count, input_args->_ascending ) ;

    if( !sorted )
        fprintf( input_args->_output_file, "Array is NOT sorted in" ) ;
    else
        fprintf( input_args->_output_file, "Array is SORTED in" ) ;
    
    fprintf( input_args->_output_file, " %s order!\n\n", 
        ( input_args->_ascending ? "ascending" : "descending" ) ) ;


    // write the (potentially sorted) array to output file
    print_array( input_args->_output_file, input_array, count) ;

    // release memory at the end, close files
    // ALWAYS "clean up" after yourself!
    fclose( input_args->_input_file ) ;
    fclose( input_args->_output_file ) ;
    free( input_array ) ;
    free( input_args ) ; 

    return 0 ;
}