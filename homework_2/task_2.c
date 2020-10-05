#include "../library/commonUtils/numericOperations.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

bool isPreviousValuesEqual(int index, int array[])
{
    for (int i = 0; i < index; i++) {
        if (array[i] == array[index])
            return true;
    }
    return false;
}

void createNumber(int generatedNumber[], int digits)
{
    srand(time(NULL));
    int result = 0;
    int i = 0;
    while (i < digits) {
        generatedNumber[i] = rand() % 10;
        while (isPreviousValuesEqual(i, generatedNumber))
            generatedNumber[i] = rand() % 10;
        i++;
    }
}

int* splitDigits(int number, int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++) {
        array[i] = number / binPow(10, 3 - i) % 10;
    }
    return array;
}

void startGame()
{
    bool isGameOver = false;
    int digits = 0;
    printf("Enter how many numbers the game has: \n");
    scanf("%d", &digits);
    int* generatedNumber = malloc(digits * sizeof(int));
    createNumber(generatedNumber, digits);
    while (!isGameOver) {
        int inputValue = 0;
        printf("Enter %d-digit number: \n", digits);
        scanf("%d", &inputValue);
        int* numberDigits = malloc(digits * sizeof(int));
        numberDigits = splitDigits(inputValue, numberDigits, digits);
        int cows = 0;
        int bulls = 0;
        for (int i = 0; i < digits; i++) {
            if (numberDigits[i] == generatedNumber[i]) {
                bulls++;
            }
            for (int j = 0; j < digits; j++) {
                if (numberDigits[i] == generatedNumber[j] && i != j) {
                    cows++;
                }
            }
        }
        if (bulls == 4) {
            isGameOver = true;
            printf("WIN \n");
        } else {
            printf("Cows: %d, Bulls: %d \n\n", cows, bulls);
        }
    }
}

int main()
{
    startGame();
    return 0;
}
