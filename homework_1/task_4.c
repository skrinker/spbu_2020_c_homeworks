#include <stdbool.h>
#include <stdio.h>

bool isPrime(int number)
{
    if (number % 2 == 0)
        return false;
    for (int i = 3; i < number / 2; i = i + 2)
        if (number % i == 0)
            return false;
    return true;
}

int main()
{
    int number = 0;
    printf("input number: \n");
    scanf("%d", &number);
    printf("primary numbers up to n: \n");
    for (int i = 2; i <= number; i++)
        if (isPrime(i))
            printf("%d\n", i);
}
