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
    int row_num;
    int col_num;
    int value;
} Member;

typedef struct Sparse {
    int number_of_rows;
    int number_of_cols;
    int number_of_elements;
    Member *M;
} Sparse;

void create_sparse(Sparse *sp) {
    printf("Enter total number of rows and columns: ");
    scanf("%d %d", &sp->number_of_rows, &sp->number_of_cols);
    printf("Enter total number of non-zero elements: ");
    scanf("%d", &sp->number_of_elements);
    sp->M = (Member *)malloc(sp->number_of_elements * sizeof(Member));
    for(int i = 0; i < sp->number_of_elements; i++) {
        printf("Enter row number, column number(starting from zero) and element: ");
        scanf("%d %d %d", &sp->M[i].row_num, &sp->M[i].col_num, &sp->M[i].value);
    }
}

void display_sparse(Sparse *sp) {
    int k = 0;  // Index of Member array
    for(int i = 0; i < sp->number_of_rows; i++) {
        for(int j = 0; j < sp->number_of_cols; j++) {
            if(sp->M[k].row_num == i && sp->M[k].col_num == j)
                printf("%d ", sp->M[k++].value);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    Sparse sp;
    create_sparse(&sp);
    display_sparse(&sp);
    
    free(sp.M);
    return 0;
}




