#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CellType { empty,
    used,
    deleted };

typedef struct HashElement {
    int value;
    char* key;
    int numberOfProbes;
} HashElement;

struct HashTable {
    HashElement** hashTable;
    HashFunction getHash;
    enum CellType* types;
    int bucketCount;
    int polynomFactor;
    int elementCount;
};

const float maxLoadFactor = 0.7;

void deleteHashElement(HashElement* element);
HashElement* createHashElement(char* key, int value, int numberOfProbes);

int getCurrentIndex(HashTable* table, int hash, int currentNumberOfProbes)
{
    return (hash + ((currentNumberOfProbes - 1) * currentNumberOfProbes) / 2) % table->bucketCount;
}

float getLoadFactor(HashTable* hashTable)
{
    return (float)hashTable->elementCount / (float)hashTable->bucketCount;
}

int getBucketCount(HashTable* table)
{
    return table->bucketCount;
}

int getElementCount(HashTable* table)
{
    return table->elementCount;
}

HashElement* createHashElement(char* key, int value, int numberOfProbes)
{
    HashElement* newElement = (HashElement*)malloc(sizeof(HashElement));
    int keySize = strlen(key);
    newElement->key = (char*)malloc(sizeof(char) * (keySize + 1));
    strcpy(newElement->key, key);
    newElement->numberOfProbes = numberOfProbes;
    newElement->value = value;

    return newElement;
}

HashTable* createHashTableWithSize(int polynomFactor, int size, HashFunction getHash)
{
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->hashTable = (HashElement**)malloc(sizeof(HashElement*) * size);
    newTable->types = (enum CellType*)malloc(sizeof(enum CellType) * size);
    memset(newTable->types, (int)empty, size * sizeof(enum CellType));
    newTable->bucketCount = size;
    memset(newTable->hashTable, 0, size * sizeof(HashElement*));
    newTable->elementCount = 0;
    newTable->polynomFactor = polynomFactor;
    newTable->getHash = getHash;
    return newTable;
}

HashTable* createHashTable(int polynomFactor, HashFunction getHash)
{
    return createHashTableWithSize(polynomFactor, 1, getHash);
}

void destroyHashTable(HashTable* table)
{
    for (int i = 0; i < table->bucketCount; ++i) {
        deleteHashElement(table->hashTable[i]);
    }
    free(table->hashTable);
    free(table->types);
    free(table);
}

void expandTable(HashTable* table)
{
    HashElement** oldElements = table->hashTable;
    enum CellType* oldTypes = table->types;

    int oldSize = table->bucketCount;
    int size = table->bucketCount * 2;

    table->hashTable = (HashElement**)malloc(sizeof(HashElement*) * size);
    table->types = (enum CellType*)malloc(sizeof(enum CellType) * size);
    memset(table->hashTable, 0, size * sizeof(HashElement*));
    memset(table->types, (int)empty, size * sizeof(enum CellType));
    table->bucketCount = size;
    table->elementCount = 0;

    for (int i = 0; i < oldSize; ++i) {
        if (oldTypes[i] != used)
            continue;
        HashElement* element = oldElements[i];
        addValue(table, element->key, element->value, 1);
        deleteHashElement(element);
    }

    free(oldElements);
    free(oldTypes);
}

bool addValue(HashTable* table, char* key, int value, int numberOfProbes)
{
    int hash = getHash(key, table->polynomFactor, table->bucketCount);
    int startIndex = getCurrentIndex(table, hash, 1);
    int currentIndex = startIndex;
    int currentNumberOfProbes = 1;
    while (table->types[currentIndex] == used) {
        if (strcmp(key, table->hashTable[currentIndex]->key) == 0) {
            table->hashTable[currentIndex]->value += value;
            if (currentNumberOfProbes > table->hashTable[currentIndex]->numberOfProbes) {
                table->hashTable[currentIndex]->numberOfProbes = currentNumberOfProbes;
            }
            return true;
        }
        currentIndex = getCurrentIndex(table, hash, currentNumberOfProbes);
        ++currentNumberOfProbes;
    }

    HashElement* newElement = createHashElement(key, value, numberOfProbes);
    newElement->numberOfProbes = currentNumberOfProbes;
    table->hashTable[currentIndex] = newElement;
    table->types[currentIndex] = used;
    table->elementCount++;

    if (getLoadFactor(table) > maxLoadFactor)
        expandTable(table);

    return true;
}

void deleteHashElement(HashElement* element)
{
    if (element == NULL)
        return;
    if (element->key != NULL) {
        free(element->key);
    }
    free(element);
}

bool removeValue(HashTable* table, char* key)
{
    if (table->elementCount == 0)
        return false;
    int startIndex = getHash(key, table->polynomFactor, table->bucketCount);
    int currentIndex = startIndex;
    int currentNumberOfProbes = 1;
    while (table->types[currentIndex] == used) {
        if (strcmp(key, table->hashTable[currentIndex]->key) == 0) {
            table->types[currentIndex] = deleted;
            deleteHashElement(table->hashTable[currentIndex]);
            --(table->elementCount);
            return true;
        }
        currentIndex = getCurrentIndex(table, currentIndex, currentNumberOfProbes);
        ++currentNumberOfProbes;
        if (currentIndex == startIndex)
            break;
    }
    return false;
}

int getValue(HashTable* table, char* key)
{
    int startIndex = table->getHash(key, table->polynomFactor, table->bucketCount);
    int currentIndex = startIndex;
    while (table->types[currentIndex] != empty) {
        if (strcmp(table->hashTable[currentIndex]->key, key) == 0)
            return table->hashTable[currentIndex]->value;
        currentIndex = (currentIndex + 1) % table->bucketCount;
        if (currentIndex == startIndex) {
            return -1;
        }
    }
    return -1;
}

double getAverageNumberOfProbes(HashTable* table)
{
    int numberOfProbes = 0;
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used)
            numberOfProbes += table->hashTable[i]->numberOfProbes;
    }
    if (table->elementCount == 0)
        return 0;
    return 1.0 * numberOfProbes / table->elementCount;
}

int getMaximumProbes(HashTable* table)
{
    int maximumNumberOfProbes = 0;
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used && table->hashTable[i]->numberOfProbes > maximumNumberOfProbes)
            maximumNumberOfProbes = table->hashTable[i]->numberOfProbes;
    }
    return maximumNumberOfProbes;
}

void printKeysWithValues(HashTable* table)
{
    if (table->elementCount == 0) {
        printf("table is empty");
        return;
    }
    for (int i = 0; i < table->bucketCount; i++) {
        if (table->types[i] == used) {
            printf("%s: %d \n", table->hashTable[i]->key, table->hashTable[i]->value);
        }
    }
}

void printMaximumNumberOfRepeats(HashTable* table, int number)
{
    bool* counted = malloc(sizeof(bool) * table->bucketCount);
    memset(counted, false, sizeof(bool) * table->bucketCount);
    number = (number > table->elementCount) ? table->elementCount : number;
    for (int j = 0; j < number; ++j) {
        int maximum = 0;
        int maximumIndex = 0;
        for (int i = 0; i < table->bucketCount; ++i) {
            if (table->types[i] == used && !counted[i] && table->hashTable[i]->value > maximum) {
                maximum = table->hashTable[i]->value;
                maximumIndex = i;
            }
            counted[maximumIndex] = true;
        }
        printf("%s: %d \n", table->hashTable[maximumIndex]->key, table->hashTable[maximumIndex]->value);
    }
    free(counted);
}

void printInfo(HashTable* table)
{
    printf("Load factor: %f \n", getLoadFactor(table));
    printf("Average number of probes: %f \n", getAverageNumberOfProbes(table));
    printf("Maximum number of probes: %d \n", getMaximumProbes(table));
    printf("Keys with values: \n");
    printKeysWithValues(table);
    printf("Top 10 values: \n");
    printMaximumNumberOfRepeats(table, 10);
    printf("Number of added words: %d \n", getElementCount(table));
    printf("Number of empty buckets: %d \n", getBucketCount(table) - getElementCount(table));
}