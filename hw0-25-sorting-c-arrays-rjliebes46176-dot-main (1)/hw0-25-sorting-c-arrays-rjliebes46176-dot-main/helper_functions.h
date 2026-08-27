/* Just some helper functions -- the interfaces
 */

// this struct holds the input arguments
typedef struct _InputArgs
{
    int _ascending ; // 1 for ascending, 0 for descending
    FILE* _input_file ;
    FILE* _output_file ;
} InputArgs;

InputArgs* parse_input_args( int argc, char* argv[] ) ;
int read_array( FILE* inputFile, int** arr ) ;
void print_array( FILE* output, int* arr, int count ) ;
int is_sorted( int* arr, int count, int ascending ) ;