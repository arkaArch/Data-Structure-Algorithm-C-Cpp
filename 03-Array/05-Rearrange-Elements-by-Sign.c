#include <stdio.h>

void arrange_negative_and_positive(int A[], int length) {
    int i = 0, j = length - 1;
    while(i < j) {
        /* If A[i] is positive then stop */
        while(A[i] < 0) { i++; }
        /* If A[j] is negative then stop */
        while(A[j] >= 0) { j--; }
        if(i < j) {
            /* Swap them */
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}

int main() {
    int arr[] = {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2};
    int n = sizeof(arr) / sizeof(int);
    arrange_negative_and_positive(arr, n);
    /* Print the array */
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
