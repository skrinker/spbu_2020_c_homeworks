#include "stdbool.h"

#ifndef SPBU_2020_C_STACK_H
#define SPBU_2020_C_STACK_H

typedef struct StackElement StackElement;
typedef struct Stack Stack;

StackElement* createStackElement(double storeElement);
Stack* createStack();
int size(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, StackElement* newElement);
StackElement* pop(Stack* stack);
void deleteStackElement(StackElement* stackElement);
void deleteStack(Stack* stack);
double getValue(StackElement* element);

#endif
