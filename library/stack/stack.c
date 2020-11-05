#include "stack.h"
#include "stdlib.h"

struct Stack {
    struct StackElement* top;
    int size;
};

struct StackElement {
    double value;
    struct StackElement* next;
};

Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

StackElement* createStackElement(double value)
{
    StackElement* element = (StackElement*)malloc(sizeof(StackElement));
    element->value = value;
    element->next = NULL;
    return element;
}

void push(Stack* stack, StackElement* element)
{
    element->next = stack->top;
    stack->top = element;
    ++(stack->size);
}

bool isEmpty(Stack* stack)
{
    return (stack->size == 0);
}

StackElement* pop(Stack* stack)
{
    if (isEmpty(stack)) {
        return NULL;
    }
    StackElement* current = stack->top;
    stack->top = current->next;
    current->next = NULL;
    --(stack->size);
    return current;
}

double getValue(StackElement* element)
{
    return element->value;
}

void deleteStackElement(StackElement* stackElement)
{
    free(stackElement);
}

void deleteStack(Stack* stack)
{
    while (!isEmpty) {
        pop(stack);
    }

    free(stack);
}