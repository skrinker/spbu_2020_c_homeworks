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
    while (number > 0) {
        ++i;
        array[arrayLength - i] = number % 10;
        number = number / 10;
    }
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

unsigned long long binaryPow(unsigned long long a, unsigned long long n)
{
    unsigned long long result = 1;
    while (n) {
        if (n & 1)
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
