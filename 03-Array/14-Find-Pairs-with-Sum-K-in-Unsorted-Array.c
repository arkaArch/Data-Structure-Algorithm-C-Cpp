#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Input: {6, 3, 1, 8, 10, 16, 7, 5, 2, 9, 14}, 10 
 * Output:  3 7 
 *          1 9
 *          8 2 */

void find_pairs_with_sum_k_space_opt(int A[], int length, int k) {
    for(int i = 0; i < length; i++) {
        for(int j = i+1; j < length; j++) {
            if(A[i] + A[j] == k)
                printf("%d %d\n", A[i], A[j]);
        }
    }
    /* Time Complexity: O(N^2), Auxiliary Space: O(1) */
}

void find_pairs_with_sum_k_time_opt(int A[], int length, int k) {
    /* Assume that the array have only non-zero positive numbers */
    /* First we will create an array hash array with size of max-of-the-array */
    int max = INT_MIN, min = INT_MAX;
    for(int i = 0; i < length; i++) {
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    int hash_arr_len = (max - min) + 1;
    int *hash = (int *)calloc(hash_arr_len, sizeof(int));

    
    for(int i = 0; i < length; i++) {
        /* We're representing each element of A with index of 
         * {(element-of-A) - (min-of-A)} into hash array */
        if(hash[(k - A[i]) - min] == -1)    // found a pair
            printf("%d %d\n", A[i], k - A[i]);
        else
            hash[A[i] - min] = -1;
    }
    free(hash);
    hash = NULL;
    /* Time Complexity: O(N), Auxiliary Space: O(N) */
}

int main() {
    int a[] = {6, 3, 1, 8, 10, 16, 7, 5, 2, 9, 14};
    find_pairs_with_sum_k_space_opt(a, sizeof(a)/sizeof(int), 10);
    puts("............................");
    find_pairs_with_sum_k_time_opt(a,sizeof(a)/sizeof(int), 10);
    return 0;
}
