#include <stdio.h>
#include <stdlib.h>

/* Diagonal_Matrix Matrix: 
 * A square matrix where all elements outside main diagonal are zero 
 * M[i,j] = 0 if i != j
 * | 1 0 0 0 |
 * | 0 2 0 0 |
 * | 0 0 3 0 |
 * | 0 0 0 4 |
 */

/* Now if we create a diagonal matrix with a 2D array of size n then it takes
 * [n^2 x sizeof(int)] space, which is a waste of space and processing. Rather
 * we store only diagonal elements. */

typedef struct Diagonal_Matrix {
    int *A;
    int n;  // number of row/column
} Diagonal_Matrix;

void Set(Diagonal_Matrix *M, int r, int c, int element) {
    /* Set the element of diagonal matrix */
    if(r == c)
        M->A[r] = element;
}

int Get(Diagonal_Matrix *M, int r, int c) {
    /* Get the element from diagonal matrix */
    if(r == c)
        return M->A[r];
    else
        return 0;
}

int main() {
    Diagonal_Matrix d;
    printf("Enter row/column number: ");
    scanf("%d", &d.n);
    d.A = (int *)malloc(d.n * sizeof(int));

    /* Set and Get functions are valuable for set or get a particular element
     * And those are most important. */ 

    printf("Enter %d integers(Only diagonal elements): ", d.n);
    for(int i = 0; i < d.n; i++)
       scanf("%d", &d.A[i]); 

    printf("\nDiagonal Matrix:\n");
    for(int i = 0; i < d.n; i++) {
        for(int j = 0; j < d.n; j++) {
            if(i == j)
                printf("%d ", d.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    free(d.A);
    return 0;
}
