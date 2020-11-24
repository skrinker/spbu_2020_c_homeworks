#include "matrix.h"

struct Matrix {
    int height;
    int width;
    int** matrix;
};

Matrix* createMatrix(int** matrix, int width, int height)
{
    Matrix* createdMatrix = malloc(sizeof(Matrix));
    createdMatrix->width = width;
    createdMatrix->height = height;
    createdMatrix->matrix = matrix;
}

bool add(Matrix* matrix1, Matrix* matrix2, Matrix* result)
{
    if (matrix1->height != matrix2->height && matrix1->width != matrix2->width)
        return false;

    for (int i = 0; i < matrix1->height; ++i) {
        for (int j = 0; j < matrix1->height; ++j) {
            result->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }
    return true;
}

bool substract(Matrix* matrix1, Matrix* matrix2, Matrix* result)
{
    if (matrix1->height != matrix2->height && matrix1->width != matrix2->width)
        return false;

    for (int i = 0; i < matrix1->height; ++i) {
        for (int j = 0; j < matrix1->height; ++j) {
            result->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
        }
    }
    return true;
}

bool multiply(Matrix* matrix1, Matrix* matrix2, Matrix* result)
{
    if (matrix1->height != matrix2->height && matrix1->width != matrix2->width)
        return false;
    for (int i = 0; i < matrix1->height; ++i) {
        for (int j = 0; j < matrix1->width; ++j) {
            for (int k = 0; k < matrix1->width; ++k) {
                result->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
        }
    }
    return true;
}

void printMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->height; ++i) {
        for (int j = 0; j < matrix->width; ++j) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void destroyMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->height; ++i) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

void nullify(Matrix* matrix)
{
    for (int i = 0; i < matrix->height; ++i) {
        for (int j = 0; j < matrix->width; ++j) {
            matrix->matrix[i][j] = 0;
        }
    }
}