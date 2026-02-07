#include <stdio.h>

int factorial_of(int n) {
    if (n == 0)
        return 1;
    return n * factorial_of(n - 1);
}

int power_of(int m, int n) {
    if (n == 0)
        return 1;
    return m * power_of(m, (n - 1));
}

/* Taylor series expansion of e^x =
 *                              1 + x/1 + x^2/2! + x^3/3! + x^4/4! + O(x^5) */

double E_v1(int x, int n) {
    double result = 1;
    if (n == 0)
        return 1;
    result = E_v1(x, n - 1);
    return result + ((double)power_of(x, n) / factorial_of(n));
}

double E_v2(int x, int n) {
    static double power_of_x = 1, factorial_n = 1;
    double result = 1;
    if (n == 0)
        return 1;

    result = E_v2(x, n - 1);
    power_of_x *= x;
    factorial_n *= n;
    return result + (power_of_x / factorial_n);
}

/* Now in the upper series the recursion goes like:
 * 1 + {x / 1} + {(x * x) / (2 * 1)} + {(x * x * x) / (3 * 2 * 1)}
 *                                   + {(x * x * x * x) / (4 * 3 * 2 * 1)} + ...
 *
 * But we can change the calculation as:
 * 1 + x [1 + x / 2 [1 + x / 3 [ 1 + x / 4 [...]]]]
 * This is Honer's Rule */

double E_v3(int x, int n) {
    static double result = 1;
    if (n == 0)
        return result;

    result = 1 + (((double)x / n) * result);
    return E_v3(x, n - 1);
}

int main() {
    printf("e^3 with accuracy 10: %lf\n", E_v1(3, 10));
    printf("e^3 with accuracy 10: %lf\n", E_v2(3, 10));
    printf("e^3 with accuracy 10: %lf\n", E_v3(3, 10));
    return 0;
}