#include "../library/stack/stack.h"
#include "../library/stringUtils/stringOperations.h"
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
    case '*':
        return value2 * value1;
    }
}

void calculatePostfixOperation(char symbol, Stack* stack)
{
    double value1 = pop(stack);
    double value2 = pop(stack);
    double result = calculateOperation(value1, value2, symbol);
    push(stack, createStackElement(result));
}

void addNumberToPostfix(int lastNonSpaceIndex, int index, Stack* stack, char expression[])
{
    int value = getNumberFromString(expression, lastNonSpaceIndex, index - 1);
    push(stack, createStackElement(value));
}

double evaluatePostfix(char* expression, Stack* stack)
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
    return pop(stack);
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
