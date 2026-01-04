#include <stdio.h>

int binary_search(int A[], int size, int key) {
    /* The array must be sorted */
    int low = 0, high = size-1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(A[mid] == key)
            return mid;
        else if(A[mid] < key)
            /* Ignore left half */
            low = mid + 1;
        else
            /* Ignore right half */
            high = mid - 1;
    }
    return -1;
}

int recursive_binary_search(int A[], int low, int high, int key) {
    if(low <= high) {
        int mid = low + (high - low) / 2;
        if(A[mid] == key)
            return mid;
        else if(A[mid] < key)
            return recursive_binary_search(A, mid + 1, high, key);
        else
            return recursive_binary_search(A, low, mid - 1, key);
    }
    return -1;
}

int main() {
    int arr[] = {1, 4, 6, 7, 9, 12, 15, 19};
    int size = sizeof(arr) / sizeof(int);
    
    printf("%d is present in the index of %d \n", 9, binary_search(arr, size, 9));
    printf("%d is present in the index of %d \n", 12, binary_search(arr, size, 12));

    printf("%d is present in the index of %d \n", 19,\
                                        recursive_binary_search(arr, 0, size - 1, 19));
    printf("%d is present in the index of %d \n", 29,\
                                        recursive_binary_search(arr, 0, size - 1, 29));
    return 0;
}
