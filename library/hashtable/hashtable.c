#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CellType { empty,
    used,
    deleted };

struct HashElement {
    int value;
    char* key;
};

struct HashTable {
    HashElement** hashTable;
    HashFunction getHash;
    enum CellType* types;
    int bucketCount;
    int polynomFactor;
    int elementCount;
};

const float maxLoadFactor = 0.7;

float getLoadFactor(HashTable* hashTable)
{
    return (float)hashTable->elementCount / (float)hashTable->bucketCount;
}

HashElement* createHashElement(char* key, int value)
{
    HashElement* newElement = (HashElement*)malloc(sizeof(HashElement));
    int keySize = strlen(key);
    newElement->key = (char*)malloc(sizeof(char) * keySize);
    strcpy(newElement->key, key);

    newElement->value = value;

    return newElement;
}

HashTable* createHashTableWithSize(int polynomFactor, int size, HashFunction* getHash)
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

HashTable* createHashTable(int polynomFactor, HashFunction* getHash)
{
    return createHashTableWithSize(polynomFactor, 1, getHash);
}

void destroyHashTable(HashTable* table)
{
    for (int i = 0; i < table->bucketCount; ++i) {
        free(table->hashTable[i]);
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
        add(table, element->key, element->value);
    }

    free(oldElements);
    free(oldTypes);
}

bool add(HashTable* table, char* key, int value)
{
    int startIndex = table->getHash(key, table->polynomFactor, table->bucketCount);
    HashElement* newElement = createHashElement(key, value);
    int currentIndex = startIndex;
    while (table->types[currentIndex] == used) {
        currentIndex = (currentIndex + 1) % table->bucketCount;
        if (currentIndex == startIndex) {
            return false;
        }
    }
    table->hashTable[currentIndex] = newElement;
    table->types[currentIndex] = used;
    table->elementCount++;

    if (getLoadFactor(table) > maxLoadFactor)
        expandTable(table);

    return true;
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
