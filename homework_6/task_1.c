#include "../library/IO/io.h"
#include "../library/commonUtils/stringOperations.h"
#include "../library/hashTable/hashTable.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHash(char* key, int polynomFactor, int module)
{
    int size = (int)strlen(key);
    int currentHash = 0;
    for (int i = 0; i < size; ++i) {
        currentHash = ((currentHash * polynomFactor) + (key[i] - 'a')) % module;
    }
    return currentHash;
}

int getCurrentIndex(int hash, int currentNumberOfProbes, int module)
{
    return (hash + ((currentNumberOfProbes - 1) * currentNumberOfProbes) / 2) % module;
}

int main()
{
    HashTable* table = createHashTable(2, getHash, getCurrentIndex);

    FILE* inputFile = fopen("/home/skrinker/spbu_2020_c_homeworks/homework_6/test.txt", "re");
    char* word = NULL;

    if (inputFile == NULL) {
        printf("Cannot open file.\n");
        return 0;
    }

    word = readWordFromFile((FILE*)inputFile);
    while (word) {
        convertWordToLowerCase(word);
        if (word[0] != '\0')
            addValue(table, word, 1, 1);
        free(word);
        word = readWordFromFile((FILE*)inputFile);
    }

    removeValue(table, "two");

    printInfo(table, 10);

    destroyHashTable(table);
    free(word);
    fclose(inputFile);

    return 0;
}
