#include "../library/commonUtils/numericOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int number)
{
    if (number % 2 == 0 && number != 2 || number == 1)
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
    printf("all prime numbers less than input: \n");
    for (int i = 0; i < number; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}