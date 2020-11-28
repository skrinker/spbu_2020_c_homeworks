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
        for (int i = length; i < capacity; ++i) {
            word[i] = '0';
        }
        symbol = fgetc(inputFile);
    }
    word[length] = '\0';
    return word;
}