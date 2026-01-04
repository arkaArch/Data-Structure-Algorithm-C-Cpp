#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 4

int main() {

    /* ------------------- CREATED TOTALLY IN STACK ------------------- */
    /* In stack 2D array stored in linear form. Though compiler allow us 
     * to access the array as [row][column] format. */
    int arr_1[ROW][COLUMN] = {
        {3, 6, 9, 12},
        {4, 8, 12, 16},
        {5, 10, 15, 20}
    };

    /* print the array */
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++)
            printf("%d ", arr_1[i][j]);
        /* Print a new line after printing a row */
        printf("\n");
    }

    /* --------- CREATED PARTIALLY IN STACK AND PARTIALLY IN HEAP --------- */
    /* The idea here is that, we will create a pointer array of "ROW" size 
     * inside stack. And create ROW number of arrays of COLUMN size inside 
     * heap. And store the addresses of those array inside the stack. */

    /* Creating a pointer array of ROW size inside stack */
    int *arr_2[ROW];

    /* Creating ROW number of arrays with COLUMN size inside heap */
    for (int i = 0; i < ROW; i++) {
        arr_2[i] = (int *)malloc(sizeof(int) * COLUMN);
        if(arr_2[i] == NULL) {
            printf("Memory allocation for arr_2[%d] is failed. \n", i);
            return 1;
        }
    }

    int value, increment;
    /* Assign value to every array created inside heap */
    for (int i = 0; i < ROW; i++) {
        if(i == 0)
            value = 3, increment = 3;
        else if(i == 1)
            value = 4, increment = 4;
        else
            value = 5, increment = 5;
        for (int j = 0; j < COLUMN; j++) {
            arr_2[i][j] = value;
            value += increment;
        }
    }
    printf("\n");
 
    /* print the array */
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++)
            printf("%d ", arr_2[i][j]);
        /* Print a new line after printing a row */
        printf("\n");
    }

    /* Free those array created inside heap */
    for (int i = 0; i < ROW; i++)
        free(arr_2[i]);

    /* --------------------- CREATED TOTALLY IN HEAP --------------------- */
    /* The idea here is to create a pointer that store an adderess of a 
     * pointer array which stores the adresses of other arrays */

    int **arr_3 = (int **)malloc(sizeof(int *) * ROW);
    if(arr_3 == NULL) {
        printf("Memory allocation for arr_3 is failed. \n");
        return 1;
    }

    for(int i = 0; i < ROW; i++) {
        arr_3[i] = (int *)malloc(sizeof(int *) * COLUMN);
        if(arr_3[i] == NULL) {
            printf("Memory allocation for arr_3[%d] is failed. \n", i);
            return 1;
        }
    }

    /* Assign value of each element of first array with 10,  
     *                                 second array with 20 and
     *                                 third array with 30 */
    for(int i = 0, value = 10; i < ROW; i++, value += 10) {
        for(int j = 0; j < COLUMN; j++)
            arr_3[i][j] = value;
    }

    /* print the array */
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++)
            printf("%d ", arr_3[i][j]);
        /* Print a new line after printing a row */
        printf("\n");
    }

    /* Free the memory accupied by 2D-array */
    free(arr_3);
    
    return 0;
}
