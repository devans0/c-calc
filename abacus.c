#include <stdarg.h>
#include <stdlib.h>

double abacus_sum(size_t n, double nums[n])
{
        double result = nums[0];
        for (size_t i = 1; i < n; ++i) {
                result += nums[i];
        }
        return result;
}

double abacus_difference(size_t n, double nums[n])
{
        double result = nums[0];
        for (size_t i = 1; i < n; ++i) {
                result -= nums[i];
        }
        return result;
}

double abacus_quotient(size_t n, double nums[n])
{

        double result = nums[0];
        for (size_t i = 1; i < n; ++i) {
                result /= nums[i];
        }
        return result;
}

double abacus_product(size_t n, double nums[n])
{
        double result = nums[0];
        for (size_t i = 1; i < n; ++i) {
                result *= nums[i];
        }
        return result;
}
