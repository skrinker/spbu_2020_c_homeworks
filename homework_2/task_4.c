#include "../library/commonUtils/intArrayOperations.h"
#include "../library/commonUtils/numericOperations.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

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
    int number = 0;
    printf("Введите число: \n");
    scanf("%d", &number);
    int digitsInNumber = getNumberLength(number);
    int* generatedNumber = malloc(digitsInNumber * sizeof(int));
    generatedNumber = splitDigits(number, generatedNumber, digitsInNumber);
    mergeSort(generatedNumber, 0, digitsInNumber - 1);
    for (int i = 0; i < digitsInNumber; ++i)
        if (generatedNumber[i] != 0)
            printf("%d", generatedNumber[i]);
    free(generatedNumber);
    return 0;
}
