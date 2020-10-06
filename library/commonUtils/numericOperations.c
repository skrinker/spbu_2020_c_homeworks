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

int* splitDigits(int number, int array[], int arrayLength)
{
    int i = 0;
    while (number > 0) {
        ++i;
        array[arrayLength - i] = number % 10;
        number = number / 10;
    }
    return array;
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