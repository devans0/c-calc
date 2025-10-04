#ifndef CALC_H_2025_10_03_191544
#define CALC_H_2025_10_03_191544 1

/* A calc_input object is initialized with NaN */
struct calc_input {
        double operand1;
        double operand2;
        double result;
        const char* operator;
};

// TODO: REMOVE
void calc_print_input(struct calc_input* in);

/**
 * calc_input_init: initializes a calc_input object.
 *
 * Operands and result are initialized to NaN. This is to ensure that it is
 * possible to check whether or not a calc_input object has been provided with
 * valid data.
 */
struct calc_input calc_input_init();

/**
 * calc_parse: parses calculator input from command line arguments.
 */
void calc_parse(char** args, struct calc_input* res);

/**
 * calc_compute: computes the operation indicated by the provided calc_input.
 */
double calc_compute(struct calc_input* in);

#endif
