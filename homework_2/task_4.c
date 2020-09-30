#include "malloc.h"
#include "stdbool.h"
#include "stdio.h"

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

int* splitDigits(int number, int digitsInNumber)
{
    int* arr = malloc(digitsInNumber * sizeof(int));
    for (int i = 0; i < digitsInNumber; i++) {
        arr[i] = number / binPow(10, digitsInNumber - 1 - i) % 10;
    }
    return arr;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int getNumberLength(int number)
{
    int digitsInNumber = 0;
    while (number > 0) {
        number /= 10;
        digitsInNumber++;
    }
    return digitsInNumber;
}

int main()
{
    int number;
    printf("Введите число: \n");
    scanf("%d", &number);
    int digitsInNumber = getNumberLength(number);
    int* generatedNumber = splitDigits(number, digitsInNumber);
    mergeSort(generatedNumber, 0, digitsInNumber - 1);
    for (int i = 0; i < digitsInNumber; i++)
        if (generatedNumber[i] != 0)
            printf("%d", generatedNumber[i]);
    return 0;
}
