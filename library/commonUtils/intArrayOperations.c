#include "intArrayOperations.h"
#include "numericOperations.h"

void reverse(int* array, int startPoint, int endPoint)
{
    for (int i = 0; i < (endPoint - startPoint) / 2 + 1; i++) {
        swap(&array[startPoint + i], &array[endPoint - i]);
    }
}