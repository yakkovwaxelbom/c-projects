#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"

void decrease(char** a);
void increase(char** a);
void Loops(char** input, void (*func)(char**), char same, char notSame );
void interpretBrainfuck(char* input);

#define SIZE_OF_OUTPUT 30000


void decrease(char** a);
void increase(char** a);
void Loops(char** input, void (*func)(char**), char same, char notSame);


void interpretBrainfuck(char* input) {
    char* output = (char*)malloc(SIZE_OF_OUTPUT * sizeof(char));
    while (*input != '\0') {
        switch (*input) {
            case '<':
                --output;
                break;
            case '>':
                ++output;
                break;
            case '+':
                ++*output;
                break;
            case '-':
                --*output;
                break;
            case ',':
                *output = getchar();
                break;
            case '.':
                printf("%c", *output);
                break;
            case '[':
                if (*output == 0) {
                    Loops(&input, increase, '[', ']');
                }
                break;
            case ']':
                if (*output != 0) {
                    Loops(&input, decrease, ']', '[');
                }
                break;
            default:
                break;
        }
        ++input;
    }
    free(output);
}


void decrease(char** a) {
    --*a;
}

void increase(char** a) {
    ++*a;
}

void Loops(char** input, void (*func)(char**), char same, char notSame) {
    int count = 1;
    do {
        func(input);
        if (**input == same) ++count;
        else if (**input == notSame) --count;
    } while (count != 0);
}








