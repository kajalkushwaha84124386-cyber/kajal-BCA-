#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    int negative = (dividend < 0) != (divisor < 0);

    // Negative values use karo taaki INT_MIN safely handle ho.
    if (dividend > 0) dividend = -dividend;
    if (divisor > 0) divisor = -divisor;

    int result = 0;

    while (dividend <= divisor) {
        int value = divisor;
        int count = -1;

        while (value >= (INT_MIN >> 1) &&
               dividend <= value + value) {
            value += value;
            count += count;
        }

        dividend -= value;
        result += count;
    }

    return negative ? result : -result;
}