#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) (a < b ? a : b)

/* Symmetric Matrix:
 * A square matrix that equals its own transpose 
 * 
 * M[i,j] = M[j,i] 
 * 
 * | 5 5 5 5 |
 * | 5 9 9 9 |
 * | 5 9 2 2 |
 * | 5 9 2 8 |
 * 
 * Number of unique element is n 
 * 
 * A[4] = {5, 9, 2, 8}
 * M[2, 3] = A[MIN(2, 3)] = A[2] = 2
 * M[3, 1] = A[MIN(3, 1)] = A[1] = 9 */

typedef struct Square_Matrix {
    int *A;
    int n;
} Square_Matrix;

void Set(Square_Matrix *M, int r, int c, int element) {
    if(r == c)
        M->A[r] = element;
}

int Get(Square_Matrix *M, int r, int c) {
   return M->A[MIN(r, c)];
}

int main() {
    Square_Matrix s;
    printf("Enter row/column number: ");
    scanf("%d", &s.n);
    s.A = (int *)malloc(s.n * sizeof(int));
    
    /* Set and Get functions are valuable for set or get a particular element
     * And those are most important. */

    printf("Enter %d integers(Only diagonal elements): ", s.n);
    for(int i = 0; i < s.n; i++)
       scanf("%d", &s.A[i]); 
    
    printf("\nSquare Matrix:\n");
    for(int i = 0; i < s.n; i++) {
        for(int j = 0; j < s.n; j++)
            printf("%d ", s.A[MIN(i, j)]);
        printf("\n");
    }

    free(s.A);
    return 0;

}
