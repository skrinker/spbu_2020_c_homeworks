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