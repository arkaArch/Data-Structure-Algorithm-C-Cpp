/* A program can access code and stack section of memory directly but it can't
 * access heap section of memory, to access this we need pointers. Also to
 * pointers. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 20;
    int *p = &a;
    printf("%d\n", *p);

    /* Creating an array of integer of size 5 in heap (dynamically created:
     * Since it created during runtime instead of compile time.) */
    int *arr = (int *)malloc(5 * sizeof(int));
    arr[0] = 10, arr[1] = 20, arr[2] = 30, arr[3] = 40, arr[4] = 50;

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    /* Free the memory (though the memory is automatically deleted after
     * programs finished it's execution, but it's a good practice and must do
     * for big programs to prevent memory leak) */
    free(arr);

    return 0;
}
