#include "../library/commonUtils/numericOperations.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    unsigned long long number = 0;
    printf("Введите число: \n");
    scanf("%llu", &number);
    int digitsInNumber = getNumberLength(number);
    int* generatedNumber = malloc(digitsInNumber * sizeof(int));
    generatedNumber = splitDigits(number, generatedNumber, digitsInNumber);

    qsort(generatedNumber, digitsInNumber, sizeof(int), compare);
    int minNoneZeroValue = 0;

    for (int i = 0; i < digitsInNumber; ++i) {
        if (generatedNumber[i] != 0 && generatedNumber[i] > minNoneZeroValue) {
            minNoneZeroValue = digitsInNumber;
            swap(&generatedNumber[0], &generatedNumber[i]);
        }
    }
    printf("%d", generatedNumber[0]);
    for (int i = 1; i < digitsInNumber; ++i) {
        printf("%d", generatedNumber[i]);
    }

    free(generatedNumber);
    return 0;
}
