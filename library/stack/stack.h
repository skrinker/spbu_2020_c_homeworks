#include "stdbool.h"

#ifndef SPBU_2020_C_HOMEWORKS_STACK
#define SPBU_2020_C_HOMEWORKS_STACK

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

#endif