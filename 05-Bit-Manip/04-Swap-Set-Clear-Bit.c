#include <stdio.h>
#include <stdbool.h>


/* PROBLEM: SWAP TWO NUMBERS 
 * DESCRIPTION: Here we're swaping value of the numbers without using third variable */
void swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;      // y = (x ^ y) ^ y = x
    *x = *x ^ *y;      // x = (x ^ y) ^ x = y
}



/* PROBLEM 2: CHECK THE i'th BIT SET OR NOT 
 * DESCRIPTION: Check if a certain bit of a number is 1(set) or 0(not) */

/* Process 1: Checking with left shift operation */
bool check_bit_l(int num, int bit_no) {    
    /* Let's say number is 29 and we're checking its 3rd bit(counting from zero)
     * 29 = 0000....11101 
     * If we take 1 and left shift it by 3, then it will be 0000....1000 
     * Now (0000....11101 & 0000....01000) = 0000....01000 != 0
     * And if the bit was zero then '&' operation gives zero */
    if((num & (1 << bit_no)) != 0)
        return true;
    return false;
}

/* Process 2: Checking with right shift operation */
bool check_bit_r(int num, int bit_no) {
    /* Let's say number is 29 and we're checking its 3rd bit(counting from zero)
     * 29 = 0000....11101 
     * If we take right shift it by 3, then it will be 0000....00011 
     * Now (0000....00011 & 0000....00001) = 0000....00000 != 0
     * And if the bit was zero then '&' operation gives zero */
    if(((num >> bit_no) & 1) != 0)
        return true;
    return false;
}



/* PROBLEM 3: SET THE i'th BIT
 * DESCRIPTIONc: Change the i'th bit to 1, whatever it is, 0 or 1 */
int set_bit(int N, int i) {
    /* Example: If N = 9, and i = 2 
     * N = 1001, after set the second bit(counting from zero) to 1 it become 1101 = 13 
     *
     * So, if we take 1, left shift it by i'th position and then perform bitwise OR
     * operation with the actual number then we got the desire result. */
    
    return (N | (1 << i));
}



/* PROBLEM 4: CLEAR THE i'th BIT
 * DESCRIPTION: Set the i'th bit to 0, whatever it is, 0 or 1 */
int clear_bit(int N, int i) {
    /* Example: If N = 13, and i = 3
     * N = 1101, after set the third bit(counting from 0) to 0 it becomes 101 = 5 
     * If N = 13, and i = 1
     * N = 1101, after set the first bit(counting from 0) to 0 it remain same. 
     *
     * So, if we take 1, left shift it by i'th position and then perform NOT upon it.  
     * And then perform a bitwise AND operation with the actual number then we got the 
     * result. */
    return (N & ~(1 << i));
}

/* PROBLEM 4: Toggle THE i'th BIT 
 * DESCRIPTION: Set the i'th bit to 0, if it is 1, and set to 1 if it is 0 */
int toggle_bit(int N, int i) {
    /* Example: if N = 13, i = 2; N = 1101 & it becomes 1001 = 9
     *          if N = 13, i = 1; N = 1101 & it becomes 1111 = 15 
     *
     * So, if we take 1, left shift it by i'th position and then perform bitwise XOR  
     * operation with the actual number then we got the result. */
    return (N ^ (1 << i));
}

/* PROBLEM 4: CLEAR THE LAST SET BIT 
 * DESCRIPTION: Set the last set bit(1) to 0 */
int clear_last_set_bit(int N) {
    /* Example: if N = 13, N = 1101 & it becomes 1100 = 12
     *          if N = 12, N = 1100 & it becomes 1000 = 8
     *          if N = 16, N = 10000 & it becomes 00000 = 0 
     *
     * Now, 16 = 10000,                         15 = 01111
     *      16 = 2^4 + 0 + 0 + 0                15 = 2^3 + 2^2 + 2 + 1
     *      40 = 101000,                        39 = 100111
     *      40 = 2^5 + 0 + 2^3 + 0 + 0 + 0      39 = 2^5 + 0 + 2^2 + 2 + 1 
     * So, when I do, (N - 1), the last set bit become zero and all the remaining 
     * bits after it become 1.
     * Now if we do bitwise AND operation between N and N-1 we got the result. */
    return (N & (N - 1));
}


int main() {
    puts("PROBLEM 1:");
    int x = 10, y = 20;
    printf("Before swap -> x = %d, y = %d \n", x, y);
    swap(&x, &y);
    printf("After swap -> x = %d, y = %d \n", x, y);


    puts("\nPROBLEM 2:");
    printf("Bit no %d of %d is %s\n", 3, 29, check_bit_l(29, 3) ? "ON" : "OFF");
    printf("Bit no %d of %d is %s\n", 1, 29, check_bit_l(29, 1) ? "ON" : "OFF");
    printf("Bit no %d of %d is %s\n", 3, 29, check_bit_r(29, 3) ? "ON" : "OFF");
    printf("Bit no %d of %d is %s\n", 1, 29, check_bit_r(29, 1) ? "ON" : "OFF");


    puts("\nPROBLEM 3:");
    printf("After set the bit no %d of %d -> %d\n", 2, 9, set_bit(9, 2));

    puts("\nPROBLEM 4:");
    printf("After clear the bit no %d of %d -> %d\n", 3, 13, clear_bit(13, 3));
    printf("After clear the bit no %d of %d -> %d\n", 1, 13, clear_bit(13, 1));

    puts("\nPROBLEM 5:");
    printf("After toggle the bit no %d of %d -> %d\n", 2, 13, toggle_bit(13, 2));
    printf("After toggle the bit no %d of %d -> %d\n", 1, 13, toggle_bit(13, 1));

    puts("\nPROBLEM 6:");
    printf("After clearing the last set bit of %d -> %d\n", 13, clear_last_set_bit(13));
    printf("After clearing the last set bit of %d -> %d\n", 12, clear_last_set_bit(12));
    printf("After clearing the last set bit of %d -> %d\n", 16, clear_last_set_bit(16));

    return 0;
}
