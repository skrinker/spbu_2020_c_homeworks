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


void splitDigits(int number, int array[], int arrayLength)
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

int getNumberLength(int number)
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
    int res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}
