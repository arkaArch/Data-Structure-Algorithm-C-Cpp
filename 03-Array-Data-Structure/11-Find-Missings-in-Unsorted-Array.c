#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* input:  13, 7, 11, 10, 5, 14
 * output: 6, 8, 9, 12          */

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

void missing_elements(int seq[], int length) {
    /* Assume that the difference between each number of the sequence is 1. */
    /* Assume that the seq only contain non-zero positive numbers */
    int max = max_min_of_array(seq, length)[0];
    int min = max_min_of_array(seq, length)[1];

    /* Create a hash array */
    int hash_array_len = (max - min) + 1;
    /* Calloc initialize memeory block with 0 */
    int *hash = (int *)calloc(hash_array_len, sizeof(int));

    /* We're trying to indicate index 0 of 'hash' array with first element of 'seq' 
     *                          index 1 of 'hash' array with second element of 'seq'
     *                          and so on. */
    for(int i = 0; i < length; i++)
        hash[seq[i] - min] = -1;

    /* Retriving and printing the missing elements */
    for(int i = 0; i < hash_array_len; i++) {
        if(hash[i] == 0)
            printf("%d ", i + min);
    }
    printf("\n");

    free(hash);
    hash = NULL;
}

int main() {
    int input[] = {13, 7, 11, 10, 5, 14};
    missing_elements(input, sizeof(input)/sizeof(int));

    return 0;
}
