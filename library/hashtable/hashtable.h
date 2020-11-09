#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdbool.h>

typedef struct HashTable HashTable;
typedef struct HashElement HashElement;
typedef int (*HashFunction)(char* key, int polynomFactor, int module);

HashElement* createHashElement(char* key, int value);

HashTable* createHashTable(int polynomFactor, HashFunction* getHash);

int getHash(char* key, int polynomFactor, int module);

float getLoadFactor(HashTable* hashTable);

bool add(HashTable* table, char* key, int value);

int getValue(HashTable* table, char* key);

void destroyHashTable(HashTable* table);

#endif