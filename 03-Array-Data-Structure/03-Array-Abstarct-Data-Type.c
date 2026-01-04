/* ADT(Abstarct-Data-Types): Representation of data and Operation on the data */

/* Here we choose to create the array dynamically, since it is more flexible to 
 * work with */

#include <stdio.h>
#include <stdlib.h>

#define C_RED       "\x1b[31m"
#define C_GREEN     "\x1b[32m"
#define C_YELLOW    "\x1b[33m"
#define C_RESET     "\x1b[0m"

typedef struct Array {
    /* Pointer to the array created in heap */
    int *A;
    /* Size of the array */
    int size;
    /* Elements inside the array */
    int length;
} Array;

void display(Array *arr) {
    if(arr->length == 0)
        printf(C_RED "Array is empty." C_RESET);
    else {
        for(int i = 0; i < arr->length; i++)
            printf("%d ", arr->A[i]);
    }
    printf("\n");
}

void append(Array *arr) {
    if(arr->length == arr->size)
        printf(C_RED "Array is full.\n" C_RESET);
    else {
        int element;
        printf(C_GREEN "element >> " C_RESET);
        scanf("%d", &element);
        arr->A[arr->length++] = element;
    }
}

void insert(Array *arr) {
    if(arr->length == arr->size)
        printf(C_RED "Array is full.\n" C_RESET);    
    else {
        int index;
        printf(C_GREEN "index >> " C_RESET);
        scanf("%d", &index);
        if(index < 0 || index >= arr->size)
            printf(C_RED "Index is not valid.\n" C_RESET);
        else if(index > arr->length)
            printf(C_YELLOW "We do not have a feature available for inserting "\
                   "out of length index. \n" C_RESET);
        else {
            /* Move the elements to their next index */
            for(int i = arr->length; i > index; i--)
                arr->A[i] = arr->A[i-1];
            /* Insert the element at required index */
            int element;
            printf(C_GREEN "element >> " C_RESET);
            scanf("%d", &element);
            arr->A[index] = element;
            arr->length++;
        }
    }
}

void delete(Array *arr) {
    if(arr->length == 0)
        printf(C_RED "Array is empty. Nothing to remove.\n" C_RESET);
    else {
        int index;
        printf(C_GREEN "index >> " C_RESET);
        scanf("%d", &index);
        if(index < 0 || index >= arr->length)
            printf(C_RED "Index is not valid.\n" C_RESET);
        else {
            /* Delete the element and occupy the free space by it's next element */
            for(int i = index; i < arr->length - 1; i++)
                arr->A[i] = arr->A[i+1];
            arr->length--;
        }

    }
}

void reverse(Array *arr) {
    int first_index = 0, last_index = arr->length - 1;
    while(first_index < last_index) {
        /* Swap element of first and last index */
        int temp = arr->A[first_index];
        arr->A[first_index] = arr->A[last_index];
        arr->A[last_index] = temp;

        /* Go for next indices */
        first_index ++, last_index--;
    }
}

int search(Array *arr) {
    /* Here we implement linear search:
     * In linear search we return the index of the unique element
     * or return the first index of duplicate element in an array */
    int element;
    printf(C_GREEN "element >> " C_RESET);
    scanf("%d", &element);

    for(int i = 0; i < arr->length; i++) {
        if(arr->A[i] == element)
            return i;
    }
    return -1;
}

int main() {
    Array arr;
    printf("Insert the size of the array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(sizeof(int) * arr.size);
    /* Initially there is no element */
    arr.length = 0;

    int user_input;
    while(1) {
        puts("\n===============: Choose the option from below :===============");
        printf("1. DISPLAY \t");
        printf("2. APPEND \t");
        printf("3. INSERT \t");
        printf("4. DELETE \n");
        printf("5. SEARCH \t");
        printf("6. REVERSE \t");
        printf("7. EXIT \t");
        printf(C_GREEN"\n\ninput >> "C_RESET);
        scanf("%d", &user_input);

        switch(user_input) {
            case 1:
                display(&arr);
                break;
            case 2:
                append(&arr);
                break;
            case 3:
                insert(&arr);
                break;
            case 4:
                delete(&arr);
                break;
            case 5:
                int index = search(&arr);
                if(index != -1)
                    printf("Element found at index %d\n", index);
                else
                    printf("Element in not found.\n");
                break;
            case 6:
                reverse(&arr);
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong input.");
        }
    } 
    return 0;
}
