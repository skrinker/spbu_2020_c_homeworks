#include <stdbool.h>

#ifndef SPBU_2020_C_VECTOR_H
#define SPBU_2020_C_VECTOR_H

typedef struct Vector Vector;

bool isEqualSize(Vector* vector1, Vector* vector2);
Vector* createVector(int* array, int size);
int multiplyScalar(Vector* vector1, Vector* vector2);
Vector* subtract(Vector* vector1, Vector* vector2);
Vector* add(Vector* vector1, Vector* vector2);
void printVector(Vector* vector);
void destroyVector(Vector* vector);

#endif