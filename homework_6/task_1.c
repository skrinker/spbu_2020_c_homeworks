#include "../library/hashtable/hashtable.h"
#include <stdio.h>

int getHash(char* key, int polynomFactor, int module)
{
    int size = strlen(key);
    int currentHash = 0;
    for (int i = 0; i < size; ++i) {
        currentHash = ((currentHash * polynomFactor) + (key[i] - 'a')) % module;
    }
    return currentHash;
}

int main()
{
    HashTable* table = createHashTable(13, getHash);
    add(table, "aa", 1);
    add(table, "ss", 100);
    printf("%d", getValue(table, "aa"));
    printf("%d", getValue(table, "ss"));
    return 0;
}
