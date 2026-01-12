#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* input: 8, 6, 8, 3, 15, 15, 20, 12, 15, 20, 10 
 * output: 8 appears 2 times 
 *         15 appears 3 times 
 *         20 appears 2 times */

/* Assume that the difference between each number of the sequence is 1. */

void find_duplicates(int A[], int length) {
    for(int i = 0; i < length; i++) {
        int first_pos = i;
        for(int j = i + 1; j < length; j++) {
            if(A[i] == A[j]) {
                /* Swap the duplicate element with the next position of i 
                 * i.e when we find a duplicate element store it contiguous 
                 * position to reduce search space */
                int temp = A[i+1];
                A[i+1] = A[j];
                A[j] = temp;
                /* Now we can increase the i */
                i ++;
            }
        }
        if((i - first_pos) + 1 > 1)
            printf("%d appears %d times. \n", A[first_pos], (i - first_pos) + 1);
    }
    /* Time Complexity: O(N^2) */
}

int *max_min_of_array(int A[], int length) {
    int *max_min = (int *)malloc(sizeof(int) * 2); 
    int max = 0, min = INT_MAX;
    for(int i = 0; i < length; i++) {
        if(A[i] > max)
            max = A[i];
        if(A[i] < min)
            min = A[i];
    }
    max_min[0] = max;
    max_min[1] = min;
    return max_min;
}

void find_duplicates_opt(int A[], int length) {
    int max = max_min_of_array(A, length)[0];
    int min = max_min_of_array(A, length)[1];
    
    int len = (max - min) + 1;
    int *hash = (int *)calloc(len, sizeof(int));
    
    /* we are trying to indicate index 0 of 'hash' array with first element of 'seq' 
     *                           index 1 of 'hash' array with second element of 'seq'
     *                           and so on.
     * and for every repeatation add 1 */
    for(int i = 0; i < length; i++)
        hash[A[i] - min] += 1;

    for(int i = 0; i < len; i++) {
        if(hash[i] > 1)
            printf("%d appears %d times. \n", i + min, hash[i]);
    }
    /* Time Complexity: O(N), Auxiliary space: O(N) */
}

int main() {
    int input[] = {8, 6, 8, 3, 15, 15, 20, 12, 15, 20, 10};
    find_duplicates(input, sizeof(input)/sizeof(int));
    puts("..........................");
    find_duplicates(input, sizeof(input)/sizeof(int));

    return 0;
}
