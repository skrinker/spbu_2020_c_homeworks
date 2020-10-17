#include "../library/commonUtils/numericOperations.c"
#include "stdio.h"
#include "stdlib.h"

#define INT_SIZE 32

void decimalToBinary(int number, int* binaryNum)
{
    for (int i = 0; i < 32; ++i) {
        binaryNum[i] = (number >> i) & 1;
    }
}

int findLastNonZeroIndex(int* array, int size)
{
    int i = 1;
    while (size > i) {
        if (array[size - i] != 0)
            break;
        ++i;
    }

    return size - i;
}

void printBinaryNum(int* binaryNum)
{
    int lastNonZeroIndex = findLastNonZeroIndex(binaryNum, INT_SIZE);
    for (int j = lastNonZeroIndex; j >= 0; --j) {
        printf("%d", binaryNum[j]);
    }
    printf("\n");
}

void sumBinaryNums(int* binaryNum1, int* binaryNum2, int* result)
{
    int resultSize = max(findLastNonZeroIndex(binaryNum1, INT_SIZE), findLastNonZeroIndex(binaryNum2, INT_SIZE)) + 2;
    int carry = 0;
    for (int i = 0; i < resultSize; ++i) {
        int bufSum = binaryNum1[i] + binaryNum2[i];
        if (bufSum + carry > 1) {
            result[i] = (bufSum + carry) % 2;
            carry = 1;
            continue;
        }
        result[i] = (bufSum + carry) % 2;
        if (carry > 0)
            --carry;
    }
}

int main()
{
    int* binaryNum1 = (int*)malloc(sizeof(int) * INT_SIZE);
    int* binaryNum2 = (int*)malloc(sizeof(int) * INT_SIZE);
    int* result = (int*)malloc(sizeof(int) * (INT_SIZE + 1));

    for (int i = 0; i < INT_SIZE + 1; ++i)
        result[i] = 0;

    int number1 = 0;
    printf("Enter value: \n");
    scanf("%d", &number1);
    printf("Binary form: \n");
    decimalToBinary(number1, binaryNum1);
    printBinaryNum(binaryNum1);

    int number2 = 0;
    printf("Enter value: \n");
    scanf("%d", &number2);
    printf("Binary form: \n");
    decimalToBinary(number2, binaryNum2);
    printBinaryNum(binaryNum2);

    printf("Sum: \n");
    sumBinaryNums(binaryNum1, binaryNum2, result);
    printBinaryNum(result);

    printf("Expected value: \n");
    decimalToBinary(number1 + number2, result);
    printBinaryNum(result);

    free(binaryNum1);
    free(binaryNum2);
    free(result);

    return 0;
}