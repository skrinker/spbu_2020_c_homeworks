#include "numericOperations.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int binPow(int a, int n)
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
