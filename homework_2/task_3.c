#include "stdio.h"

int putZerosToEnd(int a[], int n) {
    int count = 0; 

    for (int i = 0; i < n; i++) 
        if (a[i] != 0) {
            a[count] = a[i]; 
            count++;
        }

    while (count < n) 
        a[count++] = 0;
}

int main() {
    int n = 0;
    printf("Введите длину массива: \n");
    scanf("%d", &n);

    printf("Введите массив: \n");
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    putZerosToEnd(arr, n); 

    for (int i = 0; i < n; i++) 
        printf("%d \t", arr[i]);
    return 0; 
}

