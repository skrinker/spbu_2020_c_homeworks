#include "stdio.h"

unsigned long long getRecursiveFactorial(int number)
{
    if (number <= 1)
        return 1;

    return getRecursiveFactorial(number - 1) * number;
}

unsigned long long getInteractiveFactorial(int number)
{
    unsigned long long factorial = 1;
    for (int i = 2; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    int number = 0;
    printf("Enter a number (up to and including 20):  \n");
    scanf("%d", &number);
    while (number < 0) {
        printf("Value should be more than 0, try again =( \n");
        scanf("%d", &number);
    }
    printf("%llu\n", getInteractiveFactorial(number));
    printf("%llu\n", getRecursiveFactorial(number));
    printf("Magic, the values are equal!\n");
    return 0;
}