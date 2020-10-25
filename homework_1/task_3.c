#include "../library/commonUtils/numericOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define primeNumber 13

int binaryPow(int a, int n)
{
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return binaryPow(a, n - 1) * a;
    } else {
        int c = binaryPow(a, n / 2);
        return c * c;
    }
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

int getRandomNumber(int number)
{
    return rand() % number;
}

int getCharNumber(char symbol)
{
    if (symbol == ' ')
        return 26;
    return symbol - 'a' + 1;
}

int getHash(int a, int b, char str[])
{
    int result = 0;
    for (int i = a; i < b; i++) {
        result += binaryPow(primeNumber, b - a - i - 1) * getCharNumber(str[i]);
    }
    return result;
}

int getNextSubstringHash(int buffHash, int patternLength, char text[], int index)
{
    return primeNumber * buffHash - binaryPow(primeNumber, patternLength) * getHash(index, index + 1, text)
        + getHash(index + patternLength, index + patternLength + 1, text);
}

int searchString(char pattern[], char text[])
{
    int n = 0;
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int patternHash = getHash(0, patternLength, pattern);
    int buffHash = getHash(0, patternLength, text);
    for (int i = 0; i < textLength - patternLength + 1; i++) {
        if (buffHash == patternHash) {
            int c = getRandomNumber(patternLength);
            if (text[i + c] == pattern[c]) {
                n++;
            }
        }
        buffHash = getNextSubstringHash(buffHash, patternLength, text, i);
    }
    return n;
}

int main()
{
    printf("input text:\n");
    char* text = getString();
    printf("enter the string to find:\n");
    char* searchStr = getString();
    printf("total occurrences: %d \n", searchString(searchStr, text));
    return 0;
}
