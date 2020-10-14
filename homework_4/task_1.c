#include "../library/stack/stack.c"
#include "stdio.h"
#include "string.h"

int main()
{
    int stringSize = 0;
    printf("input string size");
    scanf("%d", &stringSize);

    char* string = malloc(stringSize * sizeof(char));
    evaluatePostfix(stringSize, string);
    return 0;
}

int evaluatePostfix(int stringSize, char* string)
{
    int length = 0;
    int capacity = 1;
    char symbol = getchar();
    while (stringSize > 1) {
        string[(length)++] = symbol;
        symbol = getchar();
        --stringSize;
    }
    string[length] = '\0';
    return 0;
}