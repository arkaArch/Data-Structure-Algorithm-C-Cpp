#include <stdio.h>

/* We see the implementation of left rotation in LED display board
 * i.e like moving text msg in LED board */

void left_rotate(int A[], int n, int d) {
    /* If an array is rotated by its 'size' time, it will be same.
     * So, if a 5-sized array will rotate 8 times it will be same
     * as if it is rotated by 3 times, i.e 5 % 8 times. */
    d %= n;
    
    /* Repeat the process d times */
    for(int p = 0; p < d; p++) {
        int first_element = A[0];
        /* Left shift the array by one */
        for(int i = 0; i < n-1; i++)
            A[i] = A[i+1];
        /* Replace last item with first item */
        A[n-1] = first_element;
    }
    
    /* TIME-COMPLEXITY = O(N^2) and AUXILIARY-SPACE = O(1) */
}

void left_rotate_better(int A[], int n, int d) {
    /* Handle the case when d > n */
    d %= n;
    
    /* Create an temporary array of size n */
    int temp[n];
    
    /* Copy last n-d elements of A to the front of temp */
    for(int i = 0; i < n-d; i++)
        temp[i] = A[d + i];

    /* Copy first d elements of A to the back of temp */
    for(int i = 0; i < d; i++)
        temp[n - d + i] = A[i];

    /* Copy all elements from temp to A */
    for(int i = 0; i < n; i++)
        A[i] = temp[i];

    /* TIME-COMPLEXITY = O(N) but AUXILIARY-SPACE = O(N) */
}

void reverse_array(int A[], int start_index, int end_index) {
    while(start_index < end_index) {
        int temp = A[start_index];
        A[start_index] = A[end_index];
        A[end_index] = temp;
        start_index++, end_index--;
    }
}


void left_rotate_best(int A[], int n, int d) {
    /* Handle the case when d > n */
    d %= n;

    /* We can achieve the roation by three reverse processes */

    /* ROTATION-1: Reverse the subarray containing the first d elements */
    reverse_array(A, 0, d - 1);

    /* ROTATION-2: Reverse the subarray containing the last n-d elements */
    reverse_array(A, d, n - 1);

    /* ROTATION-1: Reverse the whole array */
    reverse_array(A, 0, n - 1);
    
    /* TIME-COMPLEXITY = O(N) and AUXILIARY-SPACE = O(1) */
}

void print_array(int A[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    puts("");
}

int main() {
    int arr[] = {12, 14, 38, 19, 45, 23, 73};
    int n = sizeof(arr) / sizeof(int);
    int d = 10;
    printf("Before rotation: \t");
    print_array(arr, n);

    printf("After rotate by %d: \t", d);
    left_rotate_best(arr, n, d);
    print_array(arr, n);

    return 0;
}
