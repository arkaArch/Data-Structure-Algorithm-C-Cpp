#include <stdio.h>
#include <stdlib.h>

/* Lower Triangular Matrix:
 * A square matrix where all entries above the main diagonal are zero
 *
 * M[i,j] = 0 if i < j 
 * 
 * | 1 0 0 0 |
 * | 2 3 0 0 |
 * | 4 5 6 0 |
 * | 7 8 9 2 |
 * 
 * Number of non-zero elements = [n(n+1) / 2]
 *
 * Here we're also storing the non-zero elements in a single dimension array.
 * A[(4x5)/2] = A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2}
 * Now to access the array we need some formula. Let's take row major formula
 * M[2,1] = A[(1+2) + 1] = A[4] = 5
 * M[3,3] = A[(1+2+3) + 3] = A[9] = 2 
 * M[i,j] = A[(i*(i+1)/2) + j] */

typedef struct Lower_Triangular {
    int *A;
    int n;  // number of row/column
} Lower_Triangular;

void Set(Lower_Triangular *M, int r, int c, int element) {
    /* Set the element of lower triangular matrix */
    if(r >= c)
        M->A[r * (r + 1) / 2 + c] = element;
}

int Get(Lower_Triangular *M, int r, int c) {
    /* Get the element from diagonal matrix */
    if(r >= c)
        return M->A[r * (r + 1) / 2 + c];
    else
        return 0;
}

void Display(Lower_Triangular *M) {
    for(int i = 0; i < M->n; i++) {
        for(int j = 0; j < M->n; j++)
           printf("%d ", Get(M, i, j));
        printf("\n");
    }
}

int main() {
    Lower_Triangular lt;
    printf("Enter row/column number: ");
    scanf("%d", &lt.n);
    lt.A = (int *)malloc((lt.n * (lt.n + 1) / 2) * sizeof(int));
    
    int val;
    printf("Enter all elements: \n");
    for(int i = 0; i < lt.n; i++) {
        for(int j = 0; j < lt.n; j++) {
            scanf("%d", &val);
            Set(&lt, i, j, val);
        }
    }
    /* Paste the input below & see the result: 
        For row/column number: 4
        1 2 3 4
        6 7 8 9
        5 4 3 2
        9 8 7 6
    */

    printf("\nLower Triangular Matrix:\n");
    Display(&lt);

    free(lt.A);
    return 0;
}
