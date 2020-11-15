#include "../library/IO/io.h"
#include "../library/commonUtils/stringOperations.h"
#include "../library/hashTable/hashTable.h"
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

int getCurrentIndex(HashTable* table, int hash, int currentNumberOfProbes)
{
    return (hash + ((currentNumberOfProbes - 1) * currentNumberOfProbes) / 2) % getBucketCount(table);
}

int main()
{
    HashTable* table = createHashTable(2, getHash, getCurrentIndex);

    FILE* inputFile = fopen("/home/skrinker/spbu_2020_c_homeworks/homework_6/test.txt", "r");
    char* word = NULL;

    if (inputFile == NULL) {
        printf("Cannot open file.\n");
        return 0;
    }

    while (word = readWordFromFile((FILE*)inputFile)) {
        convertWordToLowerCase(word);
        if (word[0] != '\0')
            addValue(table, word, 1, 1);
        free(word);
    }

    printInfo(table, 10);

    destroyHashTable(table);
    free(word);
    fclose(inputFile);

    return 0;
}
