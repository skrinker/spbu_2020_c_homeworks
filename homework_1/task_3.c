#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString()
{
    int len = 0;
    int capacity = 1;
    char* s = (char*)malloc(capacity * sizeof(char));

    char c = getchar();

    while (c != '\n') {
        s[(len)++] = c;

        if (len >= capacity) {
            capacity *= 2;
            s = (char*)realloc(s, capacity * sizeof(char));
        }

        c = getchar();
    }

    s[len] = '\0';

    return s;
}

int randomNumber(int a)
{
    return rand() % a;
}

int getCharNumber(char a)
{
    if (a == ' ') {
        return 26;
    }
    return a - 'a' + 1;
}

int binPow(int a, int n)
{
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return binPow(a, n - 1) * a;
    } else {
        int c = binPow(a, n / 2);
        return c * c;
    }
}

int hash(int a, int b, char str[], int primeNumber)
{
    int i;
    int result = 0;
    for (i = a; i < b; i++) {
        result += binPow(primeNumber, b - a - i - 1) * getCharNumber(str[i]);
    }
    return result;
}

int search(char pattern[], char text[], int primeNumber)
{
    int i;
    int n = 0;
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int patternHash = hash(0, patternLength, pattern, primeNumber);
    int buffHash = hash(0, patternLength, text, primeNumber);
    for (i = 0; i < textLength - patternLength + 1; i++) {
        if (buffHash == patternHash) {
            int c = randomNumber(patternLength);
            if (text[i + c] == pattern[c]) {
                n++;
            }
        }
        buffHash = primeNumber * buffHash - binPow(primeNumber, patternLength) * hash(i, i + 1, text, primeNumber)
            + hash(i + patternLength, i + patternLength + 1, text, primeNumber);
    }
    return n;
}

int main()
{
    printf("input text:\n");
    char* text = getString();
    printf("enter the string to find:\n");
    char* searchString = getString();
    printf("total occurrences: %d \n", search(searchString, text, 13));
    return 0;
}
