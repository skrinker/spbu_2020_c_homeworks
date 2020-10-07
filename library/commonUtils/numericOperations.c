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
