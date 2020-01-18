#include <stdio.h>
#include "mxdata.h"


//int argc, char **argv
int main() {
    Matrix mat = init_Matrix(10, 3, 0);
    print_Matrix(mat);
    return 0;
}
