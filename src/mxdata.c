#include <stdio.h>
#include <stdlib.h>
#include "mxdata.h"

Mxdata init_Mxdata(int rows, int cols, double init_val) {
    Mxdata mt;
    mt.rows = rows;
    mt.cols = cols;
    mt.data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i) {
        mt.data[i] = (double *)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; ++j) {
            mt.data[i][j] = 0;
        }
    }
    return mt;
}

void free_Mxdata(Mxdata mt) {
    for (int i = 0; i < mt.rows; ++i) {
        free(mt.data[i]);
    }
    free(mt.data);
}

void print_Mxdata(Mxdata mt) {
    printf("Matrix has %i rows and %i cols \n", mt.rows, mt.cols);
    for (int i = 0; i < mt.rows; ++i) {
        for (int j = 0; j < mt.cols; ++j) {
            printf("%G ", mt.data[i][j]);
        }
        printf("\n");
    }
}
