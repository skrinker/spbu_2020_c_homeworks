#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#ifndef SPBU_2020_C_STRINGOPERATIONS_H
#define SPBU_2020_C_STRINGOPERATIONS_H

bool isCharOperand(char symbol);
bool isCharSpace(char symbol);
bool isCharNumber(char symbol);
char* getString();
int getNumberFromString(char* string, int start, int end);

#endif