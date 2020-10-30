#include "../library/commonUtils/stringOperations.h"
#include "../library/stack/stack.h"
#include "stdio.h"
#include "string.h"

double calculateOperation(double value1, double value2, char symbol)
{
    switch (symbol) {
    case '+':
        return value2 + value1;
    case '-':
        return value2 - value1;
    case '/':
        return value2 / value1;
    case '8':
        return value2 * value1;
    }
}

void calculatePostfixOperation(char symbol, Stack* stack)
{
    StackElement* element1 = pop(stack);
    StackElement* element2 = pop(stack);
    double result = calculateOperation(getValue(element1), getValue(element2), symbol);
    deleteStackElement(element1);
    deleteStackElement(element2);
    push(stack, createStackElement(result));
}

void addNumberToPostfix(int lastNonSpaceIndex, int index, Stack* stack, char expression[])
{
    int value = getNumberFromString(expression, lastNonSpaceIndex, index - 1);
    push(stack, createStackElement(value));
}

void evaluatePostfix(char* expression, Stack* stack)
{
    int expressionSize = strlen(expression);
    int lastNonSpaceIndex = 0;
    for (int i = 0; i < expressionSize; ++i) {
        if (isCharOperand(expression[i])) {
            calculatePostfixOperation(expression[i], stack);
            continue;
        }
        if (isCharSpace(expression[i]) && !isCharOperand(expression[i - 1])) {
            addNumberToPostfix(lastNonSpaceIndex, i, stack, expression);
            lastNonSpaceIndex = i + 1;
            continue;
        }
    }
}

int main()
{
    printf("Please input postfix expression: \n");
    char* inputString = getString();
    Stack* stack = createStack();
    evaluatePostfix(inputString, stack);
    StackElement* result = pop(stack);
    printf("result: %f \n", getValue(result));
    printf("Thank you for using my calculator \n");
    deleteStack(stack);
    deleteStackElement(result);
    free(inputString);
    return 0;
}
