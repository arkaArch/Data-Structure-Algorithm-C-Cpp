#include <stdio.h>
#include <stdlib.h>

/* Toeplitz Matrix:
 * A Toeplitz matrix (or diagonal-constant matrix) is a matrix where each descending 
 * diagonal from left to right has constant, identical values.
 *
 * M[i,j] = M[i-1,j-1] for any element. 
 *
 * | 1  2  3  4 |
 * | 5  1  2  3 |
 * | 6  5  1  2 |
 * | 7  6  5  1 |
 * | 8  7  6  5 |
 *
 * Number of unique elements: Row + Col - 1
 *
 * Now we can store them as first store first row, then store first column
 * A[5 + 4 - 1] = A[8] = {1, 2, 3, 4, 5, 6, 7, 8} */

typedef struct Toeplitz_Matrix {
    int *A;
    int ROWS;
    int COLS;
} Toeplitz_Matrix;


void Set(Toeplitz_Matrix *M, int r, int c, int element) {
    if(r <= c)
        M->A[c - r] = element;
    else    // if(r > c)
        M->A[(M->ROWS + r) - (c + 1)] = element;
}

int Get(Toeplitz_Matrix *M, int r, int c) {
    if(r <= c)
        return M->A[c - r];
    else
        return M->A[(M->ROWS + r) - (c + 1)];
}

void Display(Toeplitz_Matrix *M) {
    for(int i = 0; i < M->ROWS; i++) {
        for(int j = 0; j < M->COLS; j++)
           printf("%d ", Get(M, i, j));
        printf("\n");
    }
}

int main() {
    Toeplitz_Matrix t;
    printf("Enter row and column size: ");
    scanf("%d %d", &t.ROWS, &t.COLS);
    t.A = (int *)malloc((t.ROWS + t.COLS - 1) * sizeof(int));

    /* Set and Get functions are valuable for set or get a particular element
     * And those are most important. */

    int val;
    printf("Enter the value of first row(%d elements): ", t.COLS);
    for(int i = 0; i < t.COLS; i++)
        scanf("%d", &t.A[i]);
    printf("Enter the value of first column(%d elements): ", t.ROWS - 1);
    for(int i = 1; i < t.ROWS; i++)
        scanf("%d", &t.A[t.COLS + i]);

    printf("\nToeplitz Matrix:\n");
    Display(&t);

   free(t.A);
   return 0;
}


