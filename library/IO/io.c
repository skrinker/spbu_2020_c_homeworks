#include "io.h"

char* readWordFromFile(FILE* inputFile)
{
    int length = 0;
    int capacity = 1;
    char* word = (char*)malloc(sizeof(char) * capacity);
    word[0] = '0';
    char symbol = fgetc(inputFile);
    if (symbol == EOF) {
        free(word);
        return NULL;
    }
    while (isAlphabet(symbol)) {
        word[length] = symbol;
        ++length;
        if (length >= capacity) {
            capacity *= 2;
            word = (char*)realloc(word, capacity * sizeof(char));
        }
        symbol = fgetc(inputFile);
    }
    if (length >= capacity) {
        capacity *= 2;
        word = (char*)realloc(word, capacity * sizeof(char));
    }
    word[length] = '\0';
    return word;
}

int readNumberFromFile(FILE* inputFile)
{
    int result = -1;
    int length = 0;
    int capacity = 1;
    char* number = (char*)malloc(sizeof(char) * capacity);
    number[0] = '0';
    char symbol = fgetc(inputFile);
    if (symbol == EOF) {
        free(number);
        return number;
    }
    while (isCharNumber(symbol)) {
        number[length] = symbol;
        ++length;
        if (length >= capacity) {
            capacity *= 2;
            number = (char*)realloc(number, capacity * sizeof(char));
        }
        symbol = fgetc(inputFile);
    }
    if (length >= capacity) {
        capacity *= 2;
        number = (char*)realloc(number, capacity * sizeof(char));
    }
    number[length] = '\0';
    if (number[0] != '\0') {
        result = getNumberFromString(number, 0, strlen(number) - 1);
    }
    free(number);
    return result;
}