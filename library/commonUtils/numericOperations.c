#include "numericOperations.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
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
