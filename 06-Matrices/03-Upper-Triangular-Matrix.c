#include <stdio.h>
#include <stdlib.h>

/* Lower Triangular Matrix:
 * A lower triangular matrix is a square matrix where all entries below the main 
 * diagonal are zero
 * 
 * M[i,j] = 0 if i > j 
 *
 * | 1 2 3 4 |
 * | 0 5 6 7 |
 * | 0 0 8 9 |
 * | 0 0 0 2 |
 *
 * Number of non-zero elements = [n(n+1) / 2]
 *
 * Here we're also storing the non-zero elements in a single dimension array. 
 * A[(4x5)/2] = A[10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 2]
 * 
 * Now to access the array we need some formula. Let's take row major formula
 * Column major formular is same as row major formula of lower triangular matrix
 * M[2,3] = A[(3+2) + 3] = A[8] = 9
 * M[3,3] = A[(3+2+1) + 3] = A[9] = 2 
 * M[i,j] = A[(n + (n-1) + (n-2) + ... + (n-i)) + j]
 *
 * Now we know in A.P sum = n/2[2a + (n-1)d]
 * Here a = n-i, d = 1, number_of_terms = (n - (n-i))+1 = i+1
 * and, n + (n-1) + (n-2) + ... + (n-i) = (i+1)/2 * [2(n-i) + (i+1-1)] = (i+1)*(2n-i)/2
 * So M[i,j] = A[(i+1)/2 * (2n-i) + j] */

typedef struct Upper_Triangular {
    int *A;
    int n;  // number of row/column
} Upper_Triangular;

void Set(Upper_Triangular *M, int r, int c, int element) {
    /* Set the element of lower triangular matrix */
    if(r <= c)
        M->A[(r + 1) * (2 * M->n - r) / 2 + c] = element;
}

int Get(Upper_Triangular *M, int r, int c) {
    /* Get the element from diagonal matrix */
    if(r <= c)
        return M->A[(r + 1) * (2 * M->n - r) / 2 + c];
    else
        return 0;
}

void Display(Upper_Triangular *M) {
    for(int i = 0; i < M->n; i++) {
        for(int j = 0; j < M->n; j++)
           printf("%d ", Get(M, i, j));
        printf("\n");
    }
}

int main() {
    Upper_Triangular ut;
    printf("Enter row/column number: ");
    scanf("%d", &ut.n);
    ut.A = (int *)malloc((ut.n * (ut.n + 1) / 2)  * sizeof(int));
    
    int val;
    printf("Enter all elements: \n");
    for(int i = 0; i < ut.n; i++) {
        for(int j = 0; j < ut.n; j++) {
            scanf("%d", &val);
            Set(&ut, i, j, val);
        }
    }
    /* Paste the input below & see the result: 
        For row/column number: 4
        1 2 3 4
        6 7 8 9
        5 4 3 2
        9 8 7 6
    */

    printf("\nUpper Triangular Matrix:\n");
    Display(&ut);

    free(ut.A);
    return 0;
}
