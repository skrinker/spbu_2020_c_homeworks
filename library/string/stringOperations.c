#include "stringOperations.h"
#include "../commonUtils/numericOperations.c"

bool isCharNumber(char symbol)
{
    return (symbol - '0' > -1) && (symbol - '0' < 10);
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
        value += (string[j] - '0') * binPow(10, end - j);
    }
    return value;
}