#include "../library/stack/stack.c"
#include "../library/stringUtils/stringOperations.c"
#include "stdio.h"
#include "string.h"

#define SPACE 32
#define MULTIPLICATION 42
#define ADDITION 43
#define SUBTRACTION 45
#define DIVISION 47

double evaluatePostfix(char* expression, Stack* stack)
{
    int expressionSize = strlen(expression);
    int lastNonSpaceIndex = 0;
    for (int i = 0; i < expressionSize; ++i) {
        if (!isCharNumber(expression[i])) {
            switch (expression[i]) {
            case SPACE: {
                int value = getNumberFromString(expression, lastNonSpaceIndex, i - 1);
                push(stack, createStackElement(value));
                lastNonSpaceIndex = i + 1;
                break;
            }
            default: {
                double value1 = pop(stack)->value;
                double value2 = pop(stack)->value;
                switch (expression[i]) {
                case ADDITION:
                    push(stack, createStackElement(value1 + value2));
                    break;
                case DIVISION:
                    push(stack, createStackElement(value2 / value1));
                    break;
                case SUBTRACTION:
                    push(stack, createStackElement(value2 - value1));
                    break;
                case MULTIPLICATION:
                    push(stack, createStackElement(value1 * value2));
                    break;
                }
            }
            }
        }
    }
    return stack->top->value;
}

int main()
{
    printf("Please input postfix expression: \n");
    char* inputString = getString();
    Stack* stack = createStack();
    printf("result: %f \n", evaluatePostfix(inputString, stack));
    printf("Thank you for using my calculator \n");
    deleteStack(stack);
    free(inputString);
    return 0;
}
