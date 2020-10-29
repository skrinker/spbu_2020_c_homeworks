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

void splitDigits(unsigned long long number, int array[], int arrayLength)
{
    int i = 0;
    if (arrayLength > getNumberLength(number)) {
        array[0] = 0;
    }
    while (number > 0) {
        ++i;
        array[arrayLength - i] = number % 10;
        number /= 10;
    }
}

int getNumberLength(unsigned long long number)
{
    int numberLength = 0;
    while (number > 0) {
        ++numberLength;
        number /= 10;
    }
    return numberLength;
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

int binaryPow(int a, int n)
{
    int result = 1;
    while (power > 0) {
        if (power & 1)
            result *= number;
        number *= number;
        power >>= 1;
    }
    return res;
}
