#ifndef SPBU_2020_C_IO_H
#define SPBU_2020_C_IO_H

#include "../commonUtils/stringOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readNumberFromFile(FILE* inputFile);
char* readWordFromFile(FILE* inputFile);

#endif //SPBU_2020_C_IO_H