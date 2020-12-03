#include "../library/commonUtils/stringOperations.h"
#include "../library/dfa/dfa.h"
#include "stdio.h"

int main()
{
    char* inputString = NULL;
    inputString = getString();
    printf("%s", inputString);
    return 0;
}