#include <stdio.h>
#include <stdlib.h>

void print_array(int A[], int arr_size) {
    /* Remember: Array is always passed by reference inside a function, it can't
     * passed by value. We can write the parameter of array as "*A" or "A[]" but
     * in both case they called the array argument by their adderess. For array
     * "A[]" is more specific as it can only points to an array. */
    for (int i = 0; i < arr_size; i++)
        printf("%d ", A[i]);
}

/* Here we return an pointer of an array */
int *create_an_array(int n) {
    int *p;
    p = (int *)malloc(sizeof(int) * n);

    for (int i = 10, count = 0; count < n; i *= 5, count += 1) {
        p[count] = i;
    }
    return p;
}

int main() {
    int arr[5] = {3, 6, 8, 9, 10};
    print_array(arr, 5);
    puts("");

    int *A = create_an_array(5);
    print_array(A, 5);
    puts("");

    return 0;
}
