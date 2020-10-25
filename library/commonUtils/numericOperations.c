#include "numericOperations.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* splitDigits(unsigned long long number, int array[], int arrayLength)
{
    int i = 0;
    while (number > 0) {
        ++i;
        array[arrayLength - i] = number % 10;
        number = number / 10;
    }
    return array;
}

int getNumberLength(unsigned long long number)
{
    int digitsInNumber = 0;
    while (number > 0) {
        number /= 10;
        ++digitsInNumber;
    }
    return digitsInNumber;
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

int binaryPow(int number, int power)
{
    int result = 1;
    while (number) {
        if (number & 1)
            result *= number;
        number *= number;
        power >>= 1;
    }
    return result;
}
