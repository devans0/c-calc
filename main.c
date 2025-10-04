#include "calc.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1])
{
        if (argc < 2) {
                printf("usage: %s <operand> <+-/*> <operand>\n", argv[0]);
                return EXIT_FAILURE;
        }
        struct calc_input in = calc_input_init();
        calc_parse(argv, &in);
        calc_print_input(&in);
        return EXIT_SUCCESS;
}
