#include "calc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: REMOVE
void calc_print_input(struct calc_input* in)
{
        printf("operand1: %g\n"
               "operand2: %g\n"
               "operator: %s\n",
               in->operand1, in->operand2, in->operator);
}

struct calc_input calc_input_init()
{
        return (struct calc_input){
                .operand1 = NAN,
                .operand2 = NAN,
                .result = NAN,
                .operator = 0,
        };
}

/* This implementation assumes that input is exclusively infix notation with
   two operands */
void calc_parse(char** args, struct calc_input* res)
{
        double num1 = 0.0;
        double num2 = 0.0;

        // Parse first number
        char* pos;
        num1 = strtod(args[1], &pos);
        if (pos == args[1]) {
                fprintf(stderr, "calc error: cannot parse %s\n", args[1]);
                return;
        }

        // Operator
        char* op = args[2];

        // Second number
        num2 = strtod(args[3], &pos);
        if (pos == args[3]) {
                fprintf(stderr, "calc error: cannot parse %s\n", args[3]);
                return;
        }

        // Populate data of passed struct calc_input*
        res->operand1 = num1;
        res->operand2 = num2;
        res->operator = op;
}

/* Performs the actual calculation and returns the result */
double calc_compute(struct calc_input* in)
{
        switch (*in->operator) {
        case '+':
                return in->operand1 + in->operand2;
        case '-':
                return in->operand1 - in->operand2;
        case '/':
                return in->operand1 / in->operand2;
        case '*':
                return in->operand1 * in->operand2;
        default:
                fprintf(stderr, "operation unknown: %s", in->operator);
                return NAN;
        }
}
