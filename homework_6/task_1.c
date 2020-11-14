#include "../library/hashtable/hashTable.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHash(char* key, int polynomFactor, int module)
{
    int size = strlen(key);
    int currentHash = 0;
    for (int i = 0; i < size; ++i) {
        currentHash = ((currentHash * polynomFactor) + (key[i] - 'a')) % module;
    }
    return currentHash;
}

char* convertWordToLowerCase(char* word)
{
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

void removeSpecialSymbols(char* word, char* specialSymbols)
{
    for (int i = 0; i < strlen(word); i++)
        for (int j = 0; j < strlen(specialSymbols); j++)
            if (word[i] == specialSymbols[j])
                memmove(&word[i], &word[i + 1], strlen(word) - i);
}

int main()
{
    HashTable* table = createHashTable(2, *getHash);

    FILE* inputFile = fopen("/home/skrinker/spbu_2020_c_homeworks/homework_6/test.txt", "r");
    char* buffer = malloc(500 * sizeof(char));
    char* word = NULL;
    char specialSymbols[] = { '!', '?', '(', ')', ';', '.', ',', '"', ':', '[', ']', '\n' };
    if (inputFile == NULL) {
        printf("Cannot open file.\n");
    }

    while (fgets(buffer, 255, (FILE*)inputFile) != NULL) {
        word = strtok(buffer, " -");
        while (word != NULL) {
            removeSpecialSymbols(word, specialSymbols);
            word = convertWordToLowerCase(word);
            addValue(table, word, 1, 1);
            word = strtok(NULL, " ");
        }
    }

    printInfo(table);

    destroyHashTable(table);
    free(word);
    fclose(inputFile);
    free(buffer);

    return 0;
}
