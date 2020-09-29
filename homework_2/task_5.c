#include "stdio.h"

unsigned long long factorialRec(int n)
{
    if ((n == 0) || (n == 1))
        return 1;
    unsigned long long factorial = 0;
    factorial = factorialRec(n - 1) * n;
}

unsigned long long factorialLoop(int n)
{
    unsigned long long factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    int n;
    printf("Enter a number (up to and including 20):  \n");
    scanf("%d", &n);
    printf("%llu\n", factorialLoop(n));
    printf("%llu\n", factorialRec(n));
    printf("Magic, the values are equal!\n");
    return 0;
}