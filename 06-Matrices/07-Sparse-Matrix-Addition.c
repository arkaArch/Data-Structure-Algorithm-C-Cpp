/* A sparse matrix is a matrix where most elements are zero in contrast of Dense Matrix
 * where most elements are non-zero 
 *
 * | 0 0 7 0 0 |
 * | 2 0 0 5 0 |
 * | 9 0 0 0 0 |
 * | 0 0 0 0 4 |
 *
 * We can represent the sparse matrix by two methods:
 *
 * 1. Coordinate list/3-column-representation: 
 *      Row, column, element in a tuples. 
 *      First tuple is: 
 *          [total number of rows in matrix, 
 *          total number of columns in matrix, 
 *          total number of non-zero elements in matrix]
 *      Second tuple is: 
 *          [row number of first non-zero element,
 *          column nummber of first non-zero element,
 *          value of first non-zero element]
 *      Third tuple is:
 *          [row number of second non-zero element,
 *          column nummber of second non-zero element,
 *          value of second non-zero element]
 *      ... and so on
 *
 * 
 * 2. Compressed sparse row:
 *      First array: Values of non-zero elements.
 *          [7, 2, 5, 9, 4]
 *      Second array: Cumulative number of elemnts in each row starting form zero.
 *          [0, 1, 3, 4, 5]
 *      Third array: Column number of non-zero elemnts.     
 *          [2, 0, 3, 0, 4] 
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct Member {
    int rn;    // number of rows
    int cn;    // number of columns
    int vl;    // value of non-zero elements
} Member;

typedef struct Sparse {
    int ROWS;        // Total number of rows
    int COLS;        // Total number of columns
    int ELEMENTS;    // Total number of non-zero elements
    Member *M;       // Member array
} Sparse;

void create_sparse(Sparse *sp) {
    printf("Enter total number of rows and columns: ");
    scanf("%d %d", &sp->ROWS, &sp->COLS);
    printf("Enter total number of non-zero elements: ");
    scanf("%d", &sp->ELEMENTS);
    sp->M = (Member *)malloc(sp->ELEMENTS * sizeof(Member));
    for(int i = 0; i < sp->ELEMENTS; i++) {
        printf("Enter row number, column number(starting from zero) and element: ");
        scanf("%d %d %d", &sp->M[i].rn, &sp->M[i].cn, &sp->M[i].vl);
    }
}

Sparse *add_sparse(Sparse *sp1, Sparse *sp2) {
    if(sp1->ROWS != sp2->ROWS && sp1->COLS != sp2->COLS)
        return NULL;
    
    Sparse *sum = (Sparse *)malloc(sizeof(Sparse));
    /* If we do addition between two sparse matrix the maximum number of elements in
     * result matrix will be the sum of elements of two sparse matrices. */
    sum->M = (Member *)malloc((sp1->ELEMENTS + sp2->ELEMENTS) * sizeof(Member));
    
    int i, j, k;
    i = j = k = 0;

    while(i < sp1->ELEMENTS && j < sp2->ELEMENTS) {
        if(sp1->M[i].rn < sp2->M[j].rn)
            sum->M[k++] = sp1->M[i++];
        if(sp2->M[j].rn < sp1->M[i].rn)
            sum->M[k++] = sp2->M[j++];
        else {    // both row are equals so check columns
            if(sp1->M[i].cn < sp2->M[j].cn)
                sum->M[k++] = sp1->M[i++];
            else if(sp2->M[j].cn < sp1->M[i].cn)
                sum->M[k++] = sp2->M[j++];
            else {      // both row and column are equal so add them
                sum->M[k].rn = sp1->M[i].rn;
                sum->M[k].cn = sp1->M[i].cn;
                sum->M[k++].vl = sp1->M[i++].vl + sp2->M[j++].vl;
            }
        }
    }
    
    /* Now just copy from remaining matrix into sum matrix */
    while(i < sp1->ELEMENTS)
        sum->M[k++] = sp1->M[i++];
    while(j < sp2->ELEMENTS)
        sum->M[k++] = sp2->M[j++];

    sum->ROWS = sp1->ROWS;
    sum->COLS = sp2->COLS;
    sum->ELEMENTS = k;

    return sum;
}

void display_sparse(Sparse *sp) {
    int k = 0;  // Index of Member array
    for(int i = 0; i < sp->ROWS; i++) {
        for(int j = 0; j < sp->COLS; j++) {
            if(sp->M[k].rn == i && sp->M[k].cn == j)
                printf("%d ", sp->M[k++].vl);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    Sparse sp1, sp2, *sp3;
    create_sparse(&sp1);
    create_sparse(&sp2);
    
    sp3 = add_sparse(&sp1, &sp2);
    
    printf("First Matrix: \n");
    display_sparse(&sp1);
    printf("Second Matrix: \n");
    display_sparse(&sp1);
    printf("SUM Matrix: \n");
    display_sparse(sp3);   

    free(sp1.M);
    free(sp2.M);
    free(sp3->M);
    return 0;
}




