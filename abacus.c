#include <stdarg.h>
#include <stdlib.h>

double abacus_sum(size_t numArgs, double n1, ...)
{
        double result = n1;
        va_list args;
        va_start(args, n1);
        for (size_t i = 1; i < numArgs; ++i) {
                result += va_arg(args, double);
        }
        va_end(args);
        return result;
}

double abacus_difference(size_t n, double n1, ...)
{
        double result = n1;
        va_list args;
        va_start(args, n1);
        for (size_t i = 1; i < n; ++i) {
                result -= va_arg(args, double);
        }
        va_end(args);
        return result;
}

double abacus_quotient(size_t n, double n1, ...)
{
        double result = n1;
        va_list args;
        va_start(args, n1);
        for (size_t i = 1; i < n; ++i) {
                result /= va_arg(args, double);
        }
        va_end(args);
        return result;
}

double abacus_product(size_t numArgs, double n1, ...)
{
        double result = n1;
        va_list args;
        va_start(args, n1);
        for (size_t i = 1; i < numArgs; ++i) {
                result *= va_arg(args, double);
        }
        va_end(args);
        return result;
}
