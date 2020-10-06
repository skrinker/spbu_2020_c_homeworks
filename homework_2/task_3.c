#include "stdio.h"
#include "stdlib.h"

int putZerosToEnd(int array[], int size)
{
    int count = 0;

    for (int i = 0; i < size; ++i)
        if (array[i] != 0) {
            array[count] = array[i];
            count++;
        }

    while (count < size)
        array[count++] = 0;
}

int main()
{
    int size = 0;
    printf("Введите длину массива: \n");
    scanf("%d", &size);

    printf("Введите массив: \n");
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
        scanf("%d", &array[i]);

    putZerosToEnd(array, size);

    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);

    free(array);
    return 0;
}
