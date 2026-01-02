#include <stdio.h>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

/* Now if we trace the recusive function, say for fib(5), we can see that
 * We are calling same function multiple times, like for fib(5), we call
 * fib(3) two times and fib(2) three times, this is called EXCESSIVE
 * RECURSION. But we store the functions value inside an array we can
 * save a lot of computation. This is called MEMOIZATION */

/* Declare an array of size n and initialize with a value of -1 */
int F[100];
int mfib(int n) {
    if (n <= 1) {
        F[n] = n;
        return n;
    } else {
        /* Check if value presents inside array, else assign */
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        F[n] = F[n - 1] + F[n - 2];
        return F[n];
    }
}

int main() {
    printf("20th number of fibonacci series: %d\n", fib(20));

    for (int i = 0; i < 100; i++)
        F[i] = -1;

    printf("20th number of fibonacci series: %d\n", mfib(20));

    return 0;
}