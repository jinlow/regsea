#ifndef MXDATA_HEADER
#define MXDATA_HEADER

// Main Mxdata datatype
typedef struct
{
    int rows;
    int cols;
    double **data;
} Mxdata;

// Use to initialize a matrix
Mxdata init_Mxdata(int rows, int cols, double init_val);

void free_Mxdata(Mxdata mt);

// Display matrix and contents
void print_Mxdata(Mxdata mt);

#endif // MXDATA_HEADER
