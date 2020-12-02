#ifndef SPBU_2020_C_DFA_H
#define SPBU_2020_C_DFA_H

#include "stdbool.h"

typedef struct DFAState DFAState;
typedef struct DFA DFA;

DFA* createDFA(DFAState** states, int statesCount);
DFAState* createDFAState(bool isFinal);
void addTransition(DFAState* firstState, char value, DFAState* secondState);
bool isCorrect(char* string, DFA* dfa);
void destroyDFAState(DFAState* dfaState);
void destroyDFA(DFA* dfa);

#endif
