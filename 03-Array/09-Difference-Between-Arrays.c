#include <stdio.h>

void difference_between_unsorted_arrays(int A[], int B[], int len_A, int len_B) {
    /* A - B -> Elements which are presents in A but not in B  */
    int diff_array[len_A];

    int j, k = 0;
    for(int i = 0; i < len_A; i++) {
        for(j = 0; j < len_B; j++) {
            if(A[i] == B[j])
               break;
        }
        if(j == len_B)
            diff_array[k++] = A[i];
    }
    
    /* print the union array */
    for(int i = 0; i < k; i++)
        printf("%d ", diff_array[i]);
    printf("\n");

    /* TIME-COMPLEXITY = O(N^2) */
}

void difference_between_sorted_arrays(int A[], int B[], int len_A, int len_B) {
    /* A - B -> Elements which are presents in A but not in B  */
    int diff_array[len_A];

    int i = 0, j = 0, k = 0;
    while(i < len_A && j < len_B) {
        if(A[i] < B[j])
            diff_array[k++] = A[i++];
        else if(A[i] > B[j])
            j++;
        else if(A[i] == B[j])
            i++, j++;
    }
    
    /* print the union array */
    for(int i = 0; i < k; i++)
        printf("%d ", diff_array[i]);
    printf("\n");

    /* TIME-COMPLEXITY = O(N^2) */
}

int main() {
    int a[] = {3, 5, 10, 6, 4};
    int b[] = {12, 4, 7, 2, 6};

    int sorted_a[] = {3, 4, 5, 6, 10};
    int sorted_b[] = {2, 4, 6, 7, 12};    

    int length_of_a = sizeof(a) / sizeof(int);
    int length_of_b = sizeof(b) / sizeof(int);

    difference_between_unsorted_arrays(a, b, length_of_a, length_of_b);
    difference_between_sorted_arrays(sorted_a, sorted_b, length_of_a, length_of_b);
    return 0;
}
