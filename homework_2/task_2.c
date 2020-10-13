#include "../library/commonUtils/numericOperations.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

bool isPreviousValuesEqual(int index, int array[])
{
    for (int i = 0; i < index; ++i) {
        if (array[i] == array[index])
            return true;
    }
    return false;
}

bool checkResult(int* numberDigits, int* generatedNumber, int digitsInGame)
{
    int cows = 0;
    int bulls = 0;
    for (int i = 0; i < digitsInGame; ++i) {
        if (numberDigits[i] == generatedNumber[i])
            bulls++;

        for (int j = 0; j < digitsInGame; ++j)
            if (numberDigits[i] == generatedNumber[j] && i != j)
                cows++;
    }

    if (bulls == digitsInGame) {
        printf("WIN \n");
        free(generatedNumber);
        return true;
    }

    printf("Cows: %d, Bulls: %d \n\n", cows, bulls);
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

void startGame(int numberDigits[], int digitsInGame)
{
    bool isGameOver = false;
    int* generatedNumber = malloc(digitsInGame * sizeof(int));
    createNumber(generatedNumber, digitsInGame);

    while (!isGameOver) {
        int inputValue = 0;
        printf("Enter %d-digit number: \n", digitsInGame);
        scanf("%d", &inputValue);
        splitDigits(inputValue, numberDigits, digitsInGame);
        isGameOver = checkResult(numberDigits, generatedNumber, digitsInGame);
    }
}

int main()
{
    int digitsInGame = 0;
    printf("Enter how many digits the game has: \n");
    scanf("%d", &digitsInGame);
    int* numberDigits = malloc(digitsInGame * sizeof(int));
    startGame(numberDigits, digitsInGame);

    free(numberDigits);
    return 0;
}
