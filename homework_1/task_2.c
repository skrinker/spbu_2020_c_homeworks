#include <stdio.h>

void swap(int *array, int startPoint, int endPoint)
{
    int i;
    for (i = 0; i < (endPoint - startPoint) / 2 + 1; i++) {
        int buf = array[startPoint + i];
        array[startPoint + i] = array[endPoint - i];
        array[endPoint - i] = buf;
    }
}
int main()
{
    int n = 2;
    int m = 3;
    int a[5] = { 1, 2, 3, 4, 5 };
    swap(a,  m, n + m - 1);
    swap(a, 0, m - 1);
    swap(a, 0, n + m - 1);
    return 0;
}

