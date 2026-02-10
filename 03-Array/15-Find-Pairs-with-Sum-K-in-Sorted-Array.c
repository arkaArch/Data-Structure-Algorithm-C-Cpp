#include <stdio.h>

/* Input: {1, 2, 3, 5, 6, 7, 8, 9, 10, 14, 16}, 10 
 * Output:  1 9 
 *          2 8
 *          3 7 */

void find_pairs_with_sum_k(int A[], int length, int k) {
    int i = 0, j = length - 1;
    while(i < j) {
        if(A[i] + A[j] == k) {
            printf("%d %d\n", A[i], A[j]);
            i++, j--;
        }
        else if(A[i] + A[j] > 10)
            /* Pair lies left */
    j--;
        else if(A[i] + A[j] < 10)
            /* Pair lies right */
            i++;
    }
    /* Time Complexity: O(N) */
}

int main() {
    int a[] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 14, 16};
    find_pairs_with_sum_k(a, sizeof(a)/sizeof(int), 10);
    return 0;
}

