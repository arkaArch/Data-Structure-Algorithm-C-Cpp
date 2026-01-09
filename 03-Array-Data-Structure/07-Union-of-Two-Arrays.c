#include <stdio.h>

void union_in_unsorted_array(int A[], int B[], int len_A, int len_B) {
    int union_array[len_A + len_B];

    /* First copy all elements of array A inside union_array */
    int len = 0;
    for(len = 0; len < len_A; len++)
        union_array[len] = A[len];
    
    /* Copy non-duplicating element of array B in union_array */
    int j;
    for(int i = 0; i < len_B; i++) {
        for(j = 0; j < len_A; j++) {
            if (B[i] == A[j])
                break;
        }
        if(j == len_A)
            union_array[len++] = B[i];
    }

    /* print the union array */
    for(int i = 0; i < len; i++)
        printf("%d ", union_array[i]);
    printf("\n");

    /* TIME-COMPLEXITY = O(N^2) */
}

void union_in_sorted_array(int A[], int B[], int len_A, int len_B) {
    int union_array[len_A + len_B];

    int i = 0, j = 0, k = 0;
    while(i < len_A && j < len_B) {
        if(A[i] < B[j])
            union_array[k++] = A[i++];
        else if(A[i] > B[j])
            union_array[k++] = B[j++];
        else {
            /* If two items are equal then copy from 
             * any array and move both indices */
            union_array[k++] = A[i++];
            j++;
        }
    }

    /* Copy left-over element from either array */
    for(; i < len_A; i++)
        union_array[k++] = A[i];
    for(; j < len_B; j++)
        union_array[k++] = B[j];
    /* print the union array */
    for(int i = 0; i < k; i++)
        printf("%d ", union_array[i]);
    printf("\n");

    /* TIME-COMPLEXITY = O(N) */
}



int main() {
    int a[] = {3, 5, 10, 6, 4};
    int b[] = {12, 4, 7, 2, 6};

    int sorted_a[] = {3, 4, 5, 6, 10};
    int sorted_b[] = {2, 4, 6, 7, 12};    

    int length_of_a = sizeof(a) / sizeof(int);
    int length_of_b = sizeof(b) / sizeof(int);

    union_in_unsorted_array(a, b, length_of_a, length_of_b);
    union_in_sorted_array(sorted_a, sorted_b, length_of_a, length_of_b);

    return 0;
}
