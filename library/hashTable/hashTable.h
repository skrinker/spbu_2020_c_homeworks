#ifndef __SPBU_2020_C_HOMEWORKS_LIBRARY_HASHTABLE_HASHTABLE_H__
#define __SPBU_2020_C_HOMEWORKS_LIBRARY_HASHTABLE_HASHTABLE_H__

#include <stdbool.h>

typedef struct HashTable HashTable;
typedef int (*HashFunction)(char* key, int polynomFactor, int module);
typedef int (*GetIndexFunction)(int hash, int currentNumberOfProbes, int module);

bool addValue(HashTable* table, char* key, int value, int numberOfProbes);
bool removeValue(HashTable* table, char* key);
void printInfo(HashTable* table, int number);
HashTable* createHashTable(int polynomFactor, HashFunction getHash, GetIndexFunction getCurrentIndex);
void destroyHashTable(HashTable* table);
int getElementCount(HashTable* table);
void printKeysWithValuesByIncreasing(HashTable* table);

#endif
