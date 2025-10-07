#include "calc.h"
#include "abacus.h"

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: REMOVE
void calc_print_input(struct calc_input* in)
{
        printf("k = %zu\n"
               "operator: %s\n"
               "operands: ",
               in->k, in->operator);
        for (size_t i = 0; i < in->k; ++i) {
                printf("%g ", in->operands[i]);
        }
        putchar('\n');
}

struct calc_input* calc_input_create()
{
        return malloc(sizeof(struct calc_input));
}

void calc_input_init(size_t n, struct calc_input* in)
{
        *in = (struct calc_input){
                .k = n,
                .operands = malloc(sizeof(double[n])),
                .result = NAN,
                .operator = 0,
        };
}

void calc_input_destroy(struct calc_input* input)
{
        free(input->operands);
        *input = (struct calc_input){ 0 };
        free(input);
}

/**
 * calc_parse parses and stores every number present in command line input
 * passed to the function. Supports either infix or polish notation and an
 * arbitrary number of operands.
 *
 * size_t n indicates the length of the args array.
 *
 * struct calc_input* res must be a valid pointer to a calc_input object that
 * has been created and initialized.
 */
void calc_parse(size_t n, char** args, struct calc_input* res)
{
        double* operands = res->operands;
        char* pos;
        char* op;

        /* Handle case of polish notation by checking if the first entry in args
         * is a valid double or not; if it is not it is the operator. */
        size_t i = 1;
        double currNum = strtod(args[i], &pos);
        if (pos == args[i]) {
                op = args[i];
                ++i;
        }
        operands[i] = currNum;
        ++i;

        /* Parse remaining numbers */
        for (; i < n; ++i) {
                currNum = strtod(args[i], &pos);
                /* Any conversion that does not yield a double must be an
                 * operator; if there is more than one operator present, use the
                 * most recently-encountered one */
                if (pos == args[i]) {
                        op = args[i];
                        continue;
                }
                operands[i] = currNum;
        }

        /* op may be null if input is composed solely of doubles */
        if (!op) {
                fprintf(stderr, "calc (FATAL): no operator\n");
                errno = 1;
                return;
        }
        res->operator = op;
}

/* Performs the actual calculation and returns the result */
double calc_compute(struct calc_input* in)
{
        switch (*in->operator) {
        case '+':
                return abacus_sum(in->k, in->operands);
        case '-':
                return abacus_difference(in->k, in->operands);
        case '/':
                return abacus_quotient(in->k, in->operands);
        case '*':
                return abacus_product(in->k, in->operands);
        default:
                fprintf(stderr, "operation unknown: %s", in->operator);
                return NAN;
        }
}
