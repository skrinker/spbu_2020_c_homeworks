#include "stringOperations.h"
#include "../commonUtils/numericOperations.h"

#define SPACE 32
#define MULTIPLICATION 42
#define ADDITION 43
#define SUBTRACTION 45
#define DIVISION 47

bool isCharNumber(char symbol)
{
    return (symbol - '0' > -1) && (symbol - '0' < 10);
}

bool isCharOperand(char symbol)
{
    return (symbol == ADDITION) || (symbol == MULTIPLICATION) || (symbol == SUBTRACTION) || (symbol == DIVISION);
}

bool isCharSpace(char symbol)
{
    return (symbol == SPACE);
}

char* getString()
{
    int length = 0;
    int capacity = 1;
    char* string = (char*)malloc(capacity * sizeof(char));
    char symbol = getchar();
    while (symbol != '\n') {
        string[(length)++] = symbol;
        if (length >= capacity) {
            capacity *= 2;
            string = (char*)realloc(string, capacity * sizeof(char));
        }
        symbol = getchar();
    }
    string[length] = '\0';
    return string;
}

int getNumberFromString(char* string, int start, int end)
{
    int value = 0;
    for (int j = start; j <= end; ++j) {
        if (isdigit(string[j])) {
            value += (string[j] - '0') * binaryPow(end - j, 10);
        }
    }
    return value;
}

void convertWordToLowerCase(char* word)
{
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

bool isAlphabet(char symbol)
{
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}