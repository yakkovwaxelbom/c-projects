#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"

int main(int argc, char *argv[]) {
    char* input = argv[1]; 
    interpretBrainfuck(input);

    return 0;
}
