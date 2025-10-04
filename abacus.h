#ifndef ABACUS_H
#define ABACUS_2025_10_03_141018 1

/**
 * abacus_add: adds two numbers together and returns the result
 */
double abacus_sum(double x, double y);

/**
 * abacus_subtract: subtracts two numbers together and returns the result
 */
double abacus_difference(double x, double y);

/**
 * abacus_mult: multiplies two numbers together and returns the result
 */
double abacus_product(double x, double y);

/**
 * abacus_div: divides two numbers together and returns the result
 *
 * Returns NaN in the case of a division by zero
 */
double abacus_quotient(double x, double y);

#endif
