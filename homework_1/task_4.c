#include "../library/commonUtils/numericOperations.h"
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

void fillMatrix(int** matrix, int size)
{
    int inputNumber = 0;
    printf("fill in a matrix of size %d \n", size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("{%d; %d} : ", i, j);
            scanf("%d", &inputNumber);
            matrix[i][j] = inputNumber;
        }
    }
}

void printSpiral(int** matrix, int size)
{
    int i = size / 2;
    int j = size / 2;
    printf("%d ", matrix[j][i]);
    int stepNumber = 0;
    int stepsInOneDirection = 0;
    int step = 0;
    int direction = 0; // 0 - left, 1 up, 2 right, 3 down
    while (stepNumber < size * size - 1) {
        if (stepNumber % 2 == 0)
            stepsInOneDirection++;
        for (step = 0; step < stepsInOneDirection * 2; step++) {
            switch (direction) {
            case LEFT:
                i--;
                break;
            case UP:
                j--;
                break;
            case RIGHT:
                i++;
                break;
            case DOWN:
                j++;
                break;
            }
            printf("%d ", matrix[j][i]);
            stepNumber++;
            if (stepNumber == size * size - 1)
                break;
            if (step == stepsInOneDirection - 1)
                direction = (direction + 1) % 4;
        }
        direction = (direction + 1) % 4;
    }
    printf("\n\n");
}

bool isPrime(int number)
{
    if (number % 2 == 0)
        return false;
    for (int i = 3; i < number / 2; i = i + 2)
        if (number % i == 0)
            return false;
    return true;
}
