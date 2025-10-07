#ifndef ABACUS_H
#define ABACUS_2025_10_03_141018 1

#include <stdlib.h>

/**
 * abacus_add: adds two numbers together and returns the result
 */
double abacus_sum(size_t n, double n1, ...);

/**
 * abacus_subtract: subtracts two numbers together and returns the result
 */
double abacus_difference(size_t n, double n1, ...);

/**
 * abacus_mult: multiplies two numbers together and returns the result
 */
double abacus_product(size_t n, double n1, ...);

/**
 * abacus_div: divides two numbers together and returns the result
 *
 * Returns NaN in the case of a division by zero
 */
double abacus_quotient(size_t n, double n1, ...);

#endif
