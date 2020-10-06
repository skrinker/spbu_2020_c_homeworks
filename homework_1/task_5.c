#include "../library/commonUtils/intArrayOperations.h"
#include "../library/commonUtils/numericOperations.h"
#include "stdio.h"
#include "stdlib.h"
#define n 7

int findRepeatedMax(int arr[], int r)
{
    int i;
    for (i = r - 1; i > 0; i--) {
        if (arr[i] == arr[i - 1]) {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int arrayLength;
    printf("Введите длину массива: \n");
    scanf("%d", &arrayLength);
    printf("Введите массив: \n");
    int* array = malloc(arrayLength * sizeof(int));
    for (int i = 0; i < arrayLength; i++) {
        scanf("%d", &array[i]);
    }
    mergeSort(array, 0, arrayLength - 1);
    printf("repeated max value: %d \n", findRepeatedMax(array, arrayLength - 1));
    return 0;
}