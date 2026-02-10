#include <stdio.h>
#include <stdlib.h>

int* merge_array(int A[], int B[], int m, int n) {
    /* m: Length of array A
     * n: Length of array B */
    
    /* Creating an array to store the merged array */
    int *merged_array = (int *)malloc(sizeof(int) * (m + n));

    int i = 0, j = 0, k = 0;
    /* i -> To track index of array A 
     * j -> To track index of array B
     * k -> To track index of merged_array */
    
    while(i < m && j < n) {
        if(A[i] < B[j])
            /* Copy the item into new array */
            merged_array[k++] = A[i++];
        else
            merged_array[k++] = B[j++];
    } 

    /* If there is element remaining elements in array A, copy them */
    for(; i < m; i++)
        merged_array[k++] = A[i];
    /* If there is element remaining elements in array B, copy them */
    for(; j < n; j++)
        merged_array[k++] = B[j];

    return merged_array;
}

int main() {
    int arr1[] = {4, 10, 12, 22, 23};
    int arr2[] = {3, 8, 16, 20, 25, 27};
    
    int m = sizeof(arr1)/sizeof(int);
    int n = sizeof(arr2)/sizeof(int);
    
    int *merged_array = merge_array(arr1, arr2, m, n);

    /* Print the new array */
    for(int i = 0; i < m + n; i++)
        printf("%d ", merged_array[i]);
    printf("\n");

    return 0;
}
