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

int is_sorted(Array *arr) {
    for(int i = 0; i < arr->length - 1; i++)
        if(arr->A[i] > arr->A[i + 1])
            return 0;
    return 1;
}

void insert_in_unsorted_array(Array *arr, int element) {
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
            arr->A[index] = element;
            arr->length++;
        }
    }
}

void insert_in_sorted_array(Array *arr, int element) {
    if(arr->length == arr->size) {
        puts(C_RED "Array is full. No insertion possible." C_RESET);
        return;
    }
    /* Check from the last index. If the element in array is greater than the new
     * element, move it to it's next position. And when the new element is greater
     * than the element of array, mark the index and put the new element into the
     * next index of the particular index. */
    int i = arr->length - 1;
    while(i >= 0 && arr->A[i] > element) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = element;
    /* Increase the length of the array by one */
    arr->length++ ;
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

int linear_search(Array *arr, int key) {
    /* In linear search we return the index of the unique element
     * or return the first index of duplicate element in an array */
    for(int i = 0; i < arr->length; i++) {
        if(arr->A[i] == key)
            return i;
    }
    return -1;
}

int binary_search(Array *arr, int key) {
    /* Only works for sorted array */
    int low = 0, high = arr->length-1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr->A[mid] == key)
            return mid;
        else if(arr->A[mid] < key)
            /* Ignore left half */
            low = mid + 1;
        else
            /* Ignore right half */
            high = mid - 1;
    }
    return -1;
}

int recursive_binary_search(Array *arr, int low, int high, int key) {
    if(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr->A[mid] == key)
            return mid;
        else if(arr->A[mid] < key)
            return recursive_binary_search(arr, mid + 1, high, key);
        else
            return recursive_binary_search(arr, low, mid - 1, key);
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
        printf("1. DISPLAY \t\t");
        printf("2. APPEND \t");
        printf("3. INSERT(SORTED) \n");
        printf("4. INSERT(UNSORTED) \t");
        printf("5. DELETE \t");
        printf("6. SEARCH \n");
        printf("7. REVERSE \t\t");
        printf("8. EXIT");

        printf(C_GREEN"\n\ninput >> "C_RESET);
        scanf("%d", &user_input);

        int x;
        switch(user_input) {
            case 1:
                display(&arr);
                break;
            case 2:
                append(&arr);
                break;
            
            case 3:
                /* Check if array is sorted */
                if(is_sorted(&arr) == 0)
                    printf(C_RED "Array is not sorted." C_RESET); 
                else {
                    printf(C_GREEN "element >> " C_RESET);
                    scanf("%d", &x);
                    insert_in_sorted_array(&arr, x);
                }
                break;

            case 4:
                printf(C_GREEN "element >> " C_RESET);
                scanf("%d", &x);
                insert_in_unsorted_array(&arr, x);
                break;
            
            case 5:
                delete(&arr);
                break;

            case 6:
                printf(C_GREEN "key >> " C_RESET);
                scanf("%d", &x);

                /* Check if array is sorted or not */
                int index;
                if(is_sorted(&arr) == 1) {
                    index = binary_search(&arr, x);
                    puts("By binary search...");
                }
                else {
                    index = linear_search(&arr, x);
                    puts("By linear search...");
                }
                if(index != -1)
                    printf("Element found at index %d\n", index);
                else
                    printf("Element is not found.\n");

                break;

            case 7:
                reverse(&arr);
                break;

            case 8:
                exit(0);

            default:
                printf("Wrong input.");
        }
    } 
    return 0;
}
