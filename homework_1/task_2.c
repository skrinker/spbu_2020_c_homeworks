#include "../library/commonUtils/intArrayOperations.h"
#include "../library/commonUtils/numericOperations.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    int arrayLength = 0;
    printf("Введите длину массива: \n");
    scanf("%d", &arrayLength);
    printf("Введите массив: \n");
    int* array = malloc(arrayLength * sizeof(int));
    for (int i = 0; i < arrayLength; i++) {
        scanf("%d", &array[i]);
    }
    int n = 0;
    printf("Введите n:\n");
    scanf("%d", &n);
    int m = 0;
    printf("Введите m:\n");
    scanf("%d", &m);
    reverse(array, m, n + m - 1);
    reverse(array, 0, m - 1);
    reverse(array, 0, n + m - 1);
    printf("Измененный массив:\n");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
