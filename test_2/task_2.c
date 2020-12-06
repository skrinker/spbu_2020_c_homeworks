#include <stdio.h>
#include <stdlib.h>

enum Comment {
    line,
    multyline
};

int main()
{
    char* buffer = malloc(sizeof(char) * 2048);
    FILE* inputFile = fopen("./test_2/test.txt", "re");
    char symbol = '0';
    char next = '0';
    int pointer = -1;
    while (symbol != EOF) {
        switch (pointer) {
        case line:
            printf("//");
            symbol = fgetc(inputFile);
            while (symbol != EOF && symbol != '\n') {
                printf("%c", symbol);
                symbol = fgetc(inputFile);
            }
            pointer = -1;
            break;

        case multyline: {
            int index = 0;
            while (symbol != EOF) {
                next = fgetc(inputFile);
                if (symbol == '/' && next == '/') {
                    buffer[index] = '/';
                    buffer[++index] = '/';
                    while (symbol != EOF && symbol != '\n') {
                        buffer[++index] = symbol;
                        symbol = next;
                        next = fgetc(inputFile);
                    }
                }
                if (symbol == '*' && next == '/' && fgetc(inputFile) != '/') {
                    pointer = -1;
                    break;
                }
                symbol = next;
            }
            if (symbol == EOF) {
                printf("%s", buffer);
            }
        } break;

        default:
            next = fgetc(inputFile);
            if (symbol == '/' && next == '/') {
                pointer = line;
            }
            if (symbol == '/' && next == '*') {
                pointer = multyline;
            }
            symbol = next;
            break;
        }
    }
}