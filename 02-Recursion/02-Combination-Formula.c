/* Combination formula -> nCr/C(n,r) = n!/{r!(n-r)!} */
#include <stdio.h>

int fact(int n) {
    int result = 1;
    for (int i = n; i >= 1; i--)
        result *= i;
    return result;
}

int nCr(int n, int r) {
    if (r > n) {
        printf("Selection can't be greater than total item.");
        return -1;
    }
    return fact(n) / (fact(r) * fact(n - r));
}

/* We can calculate the value of C(n, r) by pure recursion with the help of
 * Pascal's Triangle */
int CPascle(int n, int r) {
    if (r == 0 || n == r)
        return 1;
    return CPascle(n - 1, r - 1) + CPascle(n - 1, r);
}

int main() {
    printf("C(5, 3) = %d\n", nCr(5, 3));
    printf("C(12, 5) = %d\n", nCr(12, 5));

    printf("C(5, 3) = %d\n", CPascle(5, 3));
    printf("C(12, 5) = %d\n", CPascle(12, 5));
    return 0;
}
