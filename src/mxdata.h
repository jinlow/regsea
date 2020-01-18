#ifndef MXDATA_HEADER
#define MXDATA_HEADER

// Main Matrix datatype
typedef struct
{
    int rows;
    int cols;
    double **data;
} Matrix;

// Use to initialize a matrix
Matrix init_Matrix(int rows, int cols, double init_val);

// Display matrix and contents
void print_Matrix(Matrix mt);

#endif // MXDATA_HEADER
