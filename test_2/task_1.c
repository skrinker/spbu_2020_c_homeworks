#include "../library/commonUtils/numericOperations.h"
#include <stdio.h>
#include <stdlib.h>

int** createFibonachiMatrix()
{
    int** matrix = malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = malloc(2 * sizeof(int));
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix[i][j] = (i == 0 && j == 0) ? 0 : 1;
        }
    }
    return matrix;
}

int main()
{
    int** matrix = createFibonachiMatrix();
    int** firstMatrix = createFibonachiMatrix();
    int** result = malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        result[i] = malloc(2 * sizeof(int));
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
        }
    }
    printf("Input number: \n");
    int number = 0;
    scanf("%d", &number);
    printf("Result: \n %d \n", getFibonachiNumber(matrix, result, firstMatrix, number));

    for (int i = 0; i < 2; i++) {
        free(matrix[i]);
        free(result[i]);
        free(firstMatrix[i]);
    }
    free(matrix);
    free(result);
    free(firstMatrix);

    return 0;
}