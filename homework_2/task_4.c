#include "../library/commonUtils/intArrayOperations.h"
#include "../library/commonUtils/numericOperations.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

int getNumberLength(unsigned long long number)
{
    int digitsInNumber = 0;
    while (number > 0) {
        number /= 10;
        ++digitsInNumber;
    }
    return digitsInNumber;
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

int main()
{
    unsigned long long number = 0;
    printf("Введите число: \n");
    scanf("%llu", &number);
    int digitsInNumber = getNumberLength(number);
    int* generatedNumber = malloc(digitsInNumber * sizeof(int));
    generatedNumber = splitDigits(number, generatedNumber, digitsInNumber);

    qsort(generatedNumber, digitsInNumber, sizeof(int), compare);
    bool isFirstPrint = false;
    int minNoneZeroIndex = -1;
    for (int i = 0; i < digitsInNumber; ++i) {
        if (generatedNumber[i] != 0 && !isFirstPrint) {
            printf("%d", generatedNumber[i]);
            isFirstPrint = true;
            minNoneZeroIndex = i;
            i = 0;
        }
        if (isFirstPrint && minNoneZeroIndex != i) {
            printf("%d", generatedNumber[i]);
        }
    }

    free(generatedNumber);
    return 0;
}
