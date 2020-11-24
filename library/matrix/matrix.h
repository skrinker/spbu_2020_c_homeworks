#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;

Matrix* createMatrix(int** matrix, int width, int height);
bool add(Matrix* matrix1, Matrix* matrix2, Matrix* result);
bool substract(Matrix* matrix1, Matrix* matrix2, Matrix* result);
bool multiply(Matrix* matrix1, Matrix* matrix2, Matrix* result);
void printMatrix(Matrix* matrix);
void destroyMatrix(Matrix* matrix);
void nullify(Matrix* matrix);
