#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdbool.h>

typedef struct HashTable HashTable;
typedef int (*HashFunction)(char* key, int polynomFactor, int module);

HashTable* createHashTable(int polynomFactor, HashFunction getHash);
int getHash(char* key, int polynomFactor, int module);
float getLoadFactor(HashTable* hashTable);
bool addValue(HashTable* table, char* key, int value, int numberOfProbes);
bool removeValue(HashTable* table, char* key);
int getValue(HashTable* table, char* key);
double getAverageNumberOfProbes(HashTable* table);
char** getMostRepeatedKeys(HashTable* table, char** result, int number);
void destroyHashTable(HashTable* table);
int getBucketCount(HashTable* table);
int getElementCount(HashTable* table);
int getMaximumProbes(HashTable* table);
void printInfo(HashTable* table);
void printKeysWithValues(HashTable* table);
void printMaximumRepeats(HashTable* table);

#endif
