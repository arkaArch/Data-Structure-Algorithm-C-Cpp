#include <stdio.h>

#define MIN(a, b) ((a < b) ? a : b)

void intersection_in_unsorted_array(int A[], int B[], int len_A, int len_B) {
    int intersection_array[MIN(len_A, len_B)];

    /* Copy those element which present in both of array */
    int k = 0;
    for(int i = 0; i < len_A; i++) {
        for(int j = 0; j < len_B; j++) {
            if(A[i] == B[j]) {
                intersection_array[k++] = A[i];
                break;
            }
        }
    }

    /* print the union array */
    for(int i = 0; i < k; i++)
        printf("%d ", intersection_array[i]);
    printf("\n");

    /* TIME-COMPLEXITY = O(N^2) */
}

void intersection_in_sorted_array(int A[], int B[], int len_A, int len_B) {
    int intersection_array[MIN(len_A, len_B)];
    
    int i = 0, j = 0, k = 0;

    while(i < len_A && j < len_B) {
        if(A[i] == B[j]) {
            intersection_array[k] = A[i];
            i++, j++, k++;
        } else if (A[i] < B[j]) 
            i++;
        else
            j++;
    }

    /* print the intersection array */
    for(int i = 0; i < k; i++)
        printf("%d ", intersection_array[i]);
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

    intersection_in_unsorted_array(a, b, length_of_a, length_of_b);
    intersection_in_sorted_array(sorted_a, sorted_b, length_of_a, length_of_b);

    return 0;
}
