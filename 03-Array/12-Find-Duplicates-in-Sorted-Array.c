#include <stdio.h>

/* input: 3, 6, 8, 8, 10, 12, 15, 15, 15, 20, 20
 * output: 8 appears 2 times 
 *         15 appears 3 times 
 *         20 appears 2 times */

void find_duplicates(int A[], int length) {
    for(int i = 0; i < length - 1; i++) {
        if(A[i] == A[i + 1]) {
            int duplicate = A[i];
            int count = 0;
            while(duplicate == A[i]) {
                i += 1;
                count += 1;
            }
            printf("%d appears %d times.\n", duplicate, count);
            /* Set i to its original position, i.e one index back */
            i -= 1;
        }
    }
    /* Time Complexity: O(N) */
}

int main() {
    int input[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20, 20};
    find_duplicates(input, sizeof(input)/sizeof(int));

    return 0;
}
