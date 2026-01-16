#include <stdio.h>

int main() {
    /* Computer stores the positive integer number as binary in 32 bits
     * 215 in binary -> 11010111 it actually stores in computer like
     * 0000...........11010111. 
     * Now we say the 32th bit as MSB(Most Significant Bit) & it stores sign.
     * O -> Positive and 1 -> Negative
     *
     * Now let's see how computer stores -215.
     * Step 1: First the number stores as binary ->       0000...........11010111 
     * Step 2: Take it's one complement(flip the bits) -> 1111...........00101000
     * Step 3: Add 1 (Called 2's complement)           -> 1111...........00101001 
     * So, from MSB computer decides it's a negative number and then take it's 2's
     * Complement then print it with sign. */

    /* Bitwise OR operator
     *
     * 29 = 11101, 21 = 10101 so, (11101 | 10101) = 11101 = 29 */
    printf("29 | 21 = %d\n", (29 | 21));


    /* Bitwise AND operator
     *
     * 29 = 11101, 21 = 10101 so, (11101 & 10101) = 10101 = 21 */
    printf("29 & 21 = %d\n", (29 & 21));


    /* Bitwise XOR operator
     *
     * 29 = 11101, 21 = 10101 so, (11101 ^ 10101) = 01000 = 8 */
    printf("29 ^ 21 = %d\n", (29 ^ 21));


    /* Bitwise NOT operator
     *
     * It first flip the bit, then check if negetive
     *
     * if -ve then store 2's complement and if positive then stops
     * 29 = 0000.....11101 so, ~0000.....11101 = 1111.....00010 
     * 1's complement of 1111.....00010 = 0000.....11101
     * 2's complement of 1111.....00010 = 0000.....11110 = 30 
     * So it prints -30 */
    printf("~29 = %d\n", ~29);

    /* Left shift operator
     * 
     * It shifts all bit to left and fill empty position with zero 
     * 
     * 29 << 3 = 11101 << 3 = 11101000 = 232 */
    printf("29 << 3 = %d\n", 29 << 3);
    /* We make the formula as N << k = N * 2^k */

    
    /* Right shift operator
     * 
     * It shifts all bit to right and fill empty position with zero 
     * 
     * 29 >> 3 = 11101 >> 3 = 00011 = 3 */
    printf("29 >> 3 = %d\n", 29 >> 3);
    /* We make the formula as N << k = N / 2^k */

    return 0;
}
