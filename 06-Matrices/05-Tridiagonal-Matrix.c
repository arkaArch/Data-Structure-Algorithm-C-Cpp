#include <stdio.h>
#include <stdlib.h>

/* Tridiagonal Matrix:
 * A square matrix where non-zero elements appear only on the main diagonal, the 
 * diagonal immediately above it (superdiagonal), and the diagonal immediately below 
 * it (subdiagonal), with all other entries being zero
 *
 * M[i,j] = non-zero if |i-j| <= 1
 *
 * | 8 9 0 0 0 |
 * | 5 4 3 0 0 |
 * | 0 2 3 4 0 |
 * | 0 0 4 5 6 |
 * | 0 0 0 8 9 |
 *
 * Number of non-zero elements: N + 2(n-1) = 3n - 2 
 * 
 * Now we can store them by diagonal 
 * A[3*5 - 2] = A[13] = {5, 2, 4, 8, 8, 4, 3, 5, 9, 9, 3, 4, 6} */

typedef struct Tridiagonal_Matrix {
    int *A;
    int n;
} Tridiagonal_Matrix;

void Set(Tridiagonal_Matrix *M, int r, int c, int element) {
    /* For lower diagonal */
    if(r - c == 1)
        M->A[r - 1] = element;
    /* For main diagonal */
    else if(r - c == 0)
        M->A[(M->n - 1) + r] = element;
    /* For upper diagonal */
    else if(r - c == -1)
        M->A[2 * M->n - 1 + r] = element;
}

int Get(Tridiagonal_Matrix *M, int r, int c) {
    /* For lower diagonal */
    if(r - c == 1)
        return M->A[r - 1];
    /* For main diagonal */
    else if(r - c == 0)
        return M->A[(M->n - 1) + r];
    /* For upper diagonal */
    else if(r - c == -1)
        return M->A[2 * M->n - 1 + r];
    return 0;
}

void Display(Tridiagonal_Matrix *M) {
    for(int i = 0; i < M->n; i++) {
        for(int j = 0; j < M->n; j++)
           printf("%d ", Get(M, i, j));
        printf("\n");
    }
}

int main() {
    Tridiagonal_Matrix t;
    printf("Enter row/column number: ");
    scanf("%d", &t.n);
    t.A = (int *)malloc((3 * t.n - 1) * sizeof(int));
    
    int val;
    printf("Enter all elements: \n");
    for(int i = 0; i < t.n; i++) {
        for(int j = 0; j < t.n; j++) {
            scanf("%d", &val);
            Set(&t, i, j, val);
        }
    }
    /* Paste the input below & see the result: 
        For row/column number: 5
        1 2 3 4 6
        6 7 8 9 8
        5 4 3 2 1
        9 8 7 6 5
    */

    printf("\nTridiagonal Matrix:\n");
    Display(&t);

    free(t.A);
    return 0;
}
