#include "../library/commonUtils/stringOperations.h"
#include "../library/dfa/dfa.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char SWAP_SYMBOL = 'd';

void deleteStates(DFAState** states, int stateCount)
{
    for (int i = 0; i < stateCount; ++i) {
        destroyDFAState(states[i]);
    }
    free(states);
}

DFAState** createTransitionsAndStates()
{
    int statesCount = 8;
    DFAState** states = (DFAState**)malloc(sizeof(DFAState*) * statesCount);
    DFAState* initialState = createDFAState(0, false);
    states[0] = initialState;
    DFAState* intPartSign = createDFAState(1, false);
    states[1] = intPartSign;
    DFAState* intPartDigit = createDFAState(2, true);
    states[2] = intPartDigit;
    DFAState* decimalPoint = createDFAState(3, false);
    states[3] = decimalPoint;
    DFAState* fractionalPartDigit = createDFAState(4, true);
    states[4] = fractionalPartDigit;
    DFAState* exponent = createDFAState(5, false);
    states[5] = exponent;
    DFAState* exponentSign = createDFAState(6, false);
    states[6] = exponentSign;
    DFAState* exponentDigit = createDFAState(7, true);
    states[7] = exponentDigit;

    addTransition(initialState, '+', intPartSign);
    addTransition(initialState, '-', intPartSign);
    addTransition(intPartDigit, '.', decimalPoint);
    addTransition(intPartDigit, 'E', exponent);
    addTransition(fractionalPartDigit, 'E', exponent);
    addTransition(exponent, '+', exponentSign);
    addTransition(exponent, '-', exponentSign);

    addTransition(initialState, SWAP_SYMBOL, intPartDigit);
    addTransition(intPartSign, SWAP_SYMBOL, intPartDigit);
    addTransition(intPartDigit, SWAP_SYMBOL, intPartDigit);
    addTransition(decimalPoint, SWAP_SYMBOL, fractionalPartDigit);
    addTransition(fractionalPartDigit, SWAP_SYMBOL, fractionalPartDigit);
    addTransition(exponent, SWAP_SYMBOL, exponentDigit);
    addTransition(exponentDigit, SWAP_SYMBOL, exponentDigit);
    addTransition(exponentSign, SWAP_SYMBOL, exponentDigit);

    return states;
}

void changeAllDigitsToSymbol(char* inputString, char symbol)
{
    for (int i = 0; i < strlen(inputString); ++i)
        inputString[i] = isCharNumber(inputString[i]) ? symbol : inputString[i];
}

int main()
{
    char* inputString = NULL;
    inputString = getString();

    changeAllDigitsToSymbol(inputString, SWAP_SYMBOL);

    int statesCount = 8;

    DFAState** states = createTransitionsAndStates();
    DFA* dfa = createDFA(states[0]);

    printf("Input string %scorrect. \n", isStringCorrect(inputString, dfa) ? "" : "in");

    destroyDFA(dfa);
    free(inputString);
    deleteStates(states, 8);

    return 0;
}