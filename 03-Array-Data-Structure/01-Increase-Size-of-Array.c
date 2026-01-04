#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Create a array of size 5 inside heap */
    int arr_size = 5;
    int *arr = (int *)malloc(sizeof(int) * arr_size);
    /* Assigning value into the array */
    for (int i = 0, k = 5; i < arr_size; i++, k += 5)
        arr[i] = k;

    /* Create a new increased size array */
    int inc_size = 10;
    int *inc_arr = (int *)malloc(sizeof(int) * inc_size);
    /* Copy the element of old array inside new array */
    for (int i = 0; i < arr_size; i++)
        inc_arr[i] = arr[i];

    /* Assign zero at the remaining space of the new array */
    for (int i = arr_size; i < inc_size; i++)
        inc_arr[i] = 0;

    /* Delete the old array */
    free(arr);
    /* Link the old pointer to the new array */
    arr = inc_arr;
    /* Remove inc_arr pointer */
    inc_arr = NULL;

    /* Print the increased size array */
    for (int i = 0; i < inc_size; i++)
        printf("%d ", arr[i]);
    puts("");

    /* WHY THE SIZE OF AN ARRAY CAN NOT BE INCREASED DIRECTLY?
     * The memory for an array should be contiguous. Now we don't know the next
     * location after the address of the last element of an array is free or not
     * or how much contiguous memory is freely available, that's why we can't
     * increase the size of an array directly */

    return 0;
}