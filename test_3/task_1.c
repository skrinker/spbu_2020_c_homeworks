#include "../library/hashTable/hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHash(char* key, int polynomFactor, int module)
{
    int size = (int)strlen(key);
    int currentHash = 0;
    for (int i = 0; i < size; ++i) {
        currentHash = ((currentHash * polynomFactor) + (key[i] - '0')) % module;
    }
    return currentHash < 0 ? (-1) * currentHash : currentHash;
}

int getCurrentIndex(int hash, int currentNumberOfProbes, int module)
{
    int index = (hash + ((currentNumberOfProbes - 1) * currentNumberOfProbes) / 2) % module;
    return index < 0 ? (-1) * index : index;
}

int main()
{
    HashTable* table = createHashTable(2, getHash, getCurrentIndex);
    printf("input numbers: \n");
    char* number = malloc(32 * sizeof(char));
    scanf("%s", number);
    while (number[0] != '0') {
        addValue(table, number, 1, 1);
        scanf("%s", number);
    }

    printKeysWithValuesByIncreasing(table);

    destroyHashTable(table);

    return 0;
}