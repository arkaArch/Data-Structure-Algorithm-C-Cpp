#include <stdio.h>

int missing_element(int A[], int len) {
    /* This function finds a missing element inside an sorted sequence */
    /* Assume that the difference between each number of the sequence in 1 */
    /* Calculate difference between element and index */
    int diff = A[0];
    for(int i = 0; i < len; i++) {
        if(A[i] - i > diff) {
            /* Found a missing element */
            return A[i] - 1;
        }
    }
    return -1;
}

void missing_elements(int A[], int len) {
    /* This function finds multiple missing elements inside an sorted sequence */
    /* Assume that the difference between each number of the sequence in 1 */
    int diff = A[0];
    for(int i = 0; i < len; i++) {
        if(A[i] - i > diff) {
            while(diff < A[i] - i) {
                printf("%d ", i + diff);
                /* Increase the diff */
                diff++;
            }
        }
    }
    printf("\n");
}

int main() {
    int seq_1[] = {6, 7, 8, 9, 10, 11, 13, 14, 15};
    printf("Missing element: %d\n", missing_element(seq_1, sizeof(seq_1)/sizeof(int)));

    int seq_2[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18};
    printf("Missing elements: ");
    missing_elements(seq_2, sizeof(seq_2)/sizeof(int));

    return 0;
}
