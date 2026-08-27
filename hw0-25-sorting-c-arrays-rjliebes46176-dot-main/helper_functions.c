/* Implementation of helper functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper_functions.h"

InputArgs* parse_input_args( int argc, char* argv[] )
{
    /* Parse the input arguments
     * The function allocates memory for the InputArgs struct
     * (caller -- main -- is responsible for freeing the memory)
     * Returns NULL on failure
     * Expected usage: <program name> <a/d> <input file> <output file>
     * where `a` or `d` stand for ascending/descending
     */

    // Check if the number of arguments is correct
    if ( argc != 4)
    {
        printf( "Usage: %s <a/d> <input file> <output file>\n \nwhere `a` or `d` stand for ascending/descending\n", argv[0] ) ;
        
        exit(1) ;
    }

    // allocate memory for the InputArgs struct
    InputArgs* args = (InputArgs*) malloc( sizeof(InputArgs) ) ;

    // get the strings for each of the command line arguments
    char* order = argv[1] ;
    char* input_file_name = argv[2] ;
    char* output_file_name = argv[3] ;

    // is it ascending or descending?
    if( strcmp( order, "a" ) == 0 )
    {
        args->_ascending = 1 ;
    }
    else if ( strcmp( order, "d" ) == 0 )
    {
        args->_ascending = 0 ;
    }
    else
    {
        // always check for error conditions in your code!

        printf( "First argument must be either `a` or `d` \n" ) ;
        return NULL ;
    }

    // open the input and output files
    args->_input_file = fopen(input_file_name, "r");
    if (args->_input_file == NULL)
    {
        // failed to open the input file -- close it and return an error (NULL)
        // note we can free the args struct since the input file was never opened

        printf("Could not open input file %s \n", input_file_name );
        fclose(args->_input_file);
        free(args);

        return NULL;
    }

    args->_output_file = fopen(output_file_name, "w");
    if (args->_output_file == NULL)
    {
        // failed to open the input file -- close it and return an error (NULL)
        // note we can free the args struct since the input file was never opened

        printf("Could not open output file %s \n", output_file_name);
        fclose(args->_input_file);
        fclose(args->_output_file);
        free(args);

        return NULL;
    }

    return args ;
}

int read_array( FILE* inputFile, int** arr )
{
    /* Read in the array from the input file
     * The function allocates memory for the array
     * The caller is responsible for freeing the memory
     * Returns the number of elements read, or -1 on failure
     */

    // sanity checks
    if ( inputFile == NULL || arr == NULL )
    {
        return -1 ;
    }

    // read in the number of elements
    int count = 0 ;
    if ( fscanf( inputFile, "%d", &count ) != 1 )
    {
        return -1 ;
    }

    // allocate memory for the input array
    *arr = (int*) malloc( sizeof(int) * count ) ;
    if ( *arr == NULL )
    {
        return -1 ;
    }

    // Read one line at at time -- check if we encountered an error
    for ( int i = 0 ; i < count ; i++ )
    {
        if ( fscanf( inputFile, "%d", &((*arr)[i]) ) != 1 )
        {
            free( *arr ) ;
            *arr = NULL ;

            return -1 ;
        }
    }

    // return how many elements we read
    return count ;
}

void print_array( FILE* output, int* arr, int count )
{
    // print the array to the output "stream" 
    // (could be a file or stdout)
    // all numbers in one line, separated by spaces

    for ( int i = 0 ; i < count ; i++ )
        fprintf( output, "%d ", arr[i] ) ;
}

int is_sorted( int* arr, int count, int ascending )
{
    /* Check if the array is sorted in the specified order
     */

    // sanity checks
    if ( arr == NULL || count <= 0 )
    {
        return 0 ;
    }

    // 0 and 1 sized arrays are automatically "sorted"
    if( ( count == 0 ) | ( count == 1 ) )
        return 1 ;

    // what are we doing here?
    // see if you can figure it out!
    for ( int i = 1 ; i < count ; i++ )
    {
        if ( ascending && arr[i] < arr[i-1] )
        {
            return 0 ;
        }
        else if ( !ascending && arr[i] > arr[i-1] )
        {
            return 0 ;
        }
    }

    // array is sorted
    return 1 ;
}   