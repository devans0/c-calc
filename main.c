#include "calc.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1])
{
        if (argc < 2) {
                printf("usage: %s <operand> <+-/*> <operand>\n", argv[0]);
                return EXIT_FAILURE;
        }

        // Create calc_input object and parse user input
        struct calc_input in = calc_input_init();
        calc_parse(argv, &in);

        printf("result: %g\n", calc_compute(&in));

        return EXIT_SUCCESS;
}
