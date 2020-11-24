#include "../library/matrix/matrix.h"

void fillMatrix(int** matrix, int height, int width)
{
    int inputNumber = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("{%d; %d} : ", i, j);
            scanf("%d", &inputNumber);
            matrix[i][j] = inputNumber;
        }
    }
}

int main()
{
    int width = 3;
    int height = 4;
    int** matrix = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; ++i) {
        matrix[i] = malloc(sizeof(int) * width);
    }
    int** result = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; ++i) {
        result[i] = malloc(sizeof(int) * width);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result[i][j] = 0;
        }
    }

    fillMatrix(matrix, height, width);

    int** newMatrix = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; ++i) {
        newMatrix[i] = malloc(sizeof(int) * width);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    Matrix* matrix1 = createMatrix(matrix, width, height);
    Matrix* matrix2 = createMatrix(newMatrix, width, height);
    Matrix* resultMatrix = createMatrix(result, width, height);

    add(matrix1, matrix2, resultMatrix);
    printMatrix(resultMatrix);

    substract(matrix1, matrix2, resultMatrix);
    printMatrix(resultMatrix);

    nullify(resultMatrix);
    multiply(matrix1, matrix2, resultMatrix);
    printMatrix(resultMatrix);

    destroyMatrix(matrix1);
    destroyMatrix(matrix2);
    destroyMatrix(resultMatrix);
    return 0;
}