#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector {
    int* array;
    int size;
};

Vector* createVector(int* array, int size)
{
    Vector* vector = malloc(sizeof(Vector));
    vector->array = array;
    vector->size = size;
    return vector;
}

bool isEqualSize(Vector* vector1, Vector* vector2)
{
    return vector1->size == vector2->size;
}

int multiplyScalar(Vector* vector1, Vector* vector2)
{
    int result = 0;
    for (int i = 0; i < vector1->size; ++i) {
        result += vector1->array[i] * vector2->array[i];
    }
    return result;
}

Vector* subtract(Vector* vector1, Vector* vector2)
{
    int* array = (int*)malloc(sizeof(int) * vector1->size);
    memset(array, 0, sizeof(int) * vector1->size);
    for (int i = 0; i < vector1->size; ++i) {
        array[i] = vector1->array[i] - vector2->array[i];
    }
    return createVector(array, vector1->size);
}

Vector* add(Vector* vector1, Vector* vector2)
{
    int* array = (int*)malloc(sizeof(int) * vector1->size);
    memset(array, 0, sizeof(int) * vector1->size);
    for (int i = 0; i < vector1->size; ++i) {
        array[i] = vector1->array[i] + vector2->array[i];
    }
    return createVector(array, vector1->size);
}

void printVector(Vector* vector)
{
    printf("%s", "{ ");
    for (int i = 0; i < vector->size - 1; ++i) {
        printf("%d, ", vector->array[i]);
    }
    printf("%d } \n", vector->array[vector->size - 1]);
}

void destroyVector(Vector* vector)
{
    free(vector->array);
    free(vector);
}
