#include "stdio.h"
#include "stdlib.h"

void decompose(int index, int sum, int last, int a[], int number)
{
    if (sum == number) {
        for (int i = 0; i < index - 1; ++i) {
            printf("%d + ", a[i]);
        }
        printf("%d", a[index - 1]);
        printf("\n");
        return;
    }
    for (int i = last; i <= number - sum; ++i) {
        a[index] = i;
        decompose(index + 1, sum + i, i, a, number);
    }
}

int main()
{
    int number = 0;
    printf("Введите число: \n");
    scanf("%d", &number);
    int* array = (int*)malloc(number * sizeof(int));
    decompose(0, 0, 1, array, number);
    free(array);
    return 0;
}
