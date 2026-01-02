#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 4

/* Print 2D array in matrix format */
void print_array(int A[ROW][COLUMN]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++)
            printf("%d ", A[i][j]);
        /* Print a new line after printing a row */
        printf("\n");
    }
}

int main() {
    /* We're creating this array totally inside stack. In stack 2D array stored
     * in linear form. Though compiler allow us to access the array as
     * [row][column] format. */
    int arr_1[ROW][COLUMN] = {
        {3, 6, 9, 12},
        {4, 8, 12, 16},
        {5, 10, 15, 20},
    };
    print_array(arr_1);

    /* Next we can intitalize an 2D array partially in heap and partially in
     * stack. The idea here is that, we will create a pointer array of "ROW"
     * size inside stack. And create ROW number of arrays of COLUMN size inside
     * heap. And store the addresses of those array inside the stack. */

    /* Creating a pointer array of ROW size inside stack */
    int *arr_2[ROW];
    for (int i = 0; i < ROW; i++)
        arr_2[i] = (int *)malloc(sizeof(int) * COLUMN);

    return 0;
}
