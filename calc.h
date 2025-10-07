#ifndef CALC_H_2025_10_03_191544
#define CALC_H_2025_10_03_191544 1

#include <stdlib.h>

/* A calc_input object is initialized with NaN */
struct calc_input {
        size_t k; // number of operands
        double* operands;
        double result;
        const char* operator;
};

// TODO: REMOVE
void calc_print_input(struct calc_input* in);

/**
 * calc_input_create: allocates a new calc_input object and returns a pointer
 * to it.
 */
struct calc_input* calc_input_create();

/**
 * calc_input_init: initializes a calc_input object.
 *
 * Operands and result are initialized to NaN. This is to ensure that it is
 * possible to check whether or not a calc_input object has been provided with
 * valid data.
 */
void calc_input_init(size_t n, struct calc_input* in);

/**
 * calc_input_destroy: destroy calc_input data, free internal objects and free
 * memory allocated for the referenced calc_input object
 */
void calc_input_destroy(struct calc_input* input);

/**
 * calc_parse: parses calculator input from command line arguments.
 */
void calc_parse(size_t n, char** args, struct calc_input* res);

/**
 * calc_compute: computes the operation indicated by the provided calc_input.
 */
double calc_compute(struct calc_input* in);

#endif
