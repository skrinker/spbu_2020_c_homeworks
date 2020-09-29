#include "stdbool.h"
#include "stdio.h"

void rec(int idx, int sum, int last, int a[], int n)
{
    if (sum == n) {
        for (int i = 0; i < idx; i++) {
            if (i == idx - 1)
                printf("%d", a[i]);
            else
                printf("%d + ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = last; i <= n - sum; i++) {
        a[idx] = i;
        rec(idx + 1, sum + i, i, a, n);
    }
}

int main()
{
    int n;
    printf("Введите число: \n");
    scanf("%d", &n);
    int a[n];
    rec(0, 0, 1, a, n);
    return 0;
}