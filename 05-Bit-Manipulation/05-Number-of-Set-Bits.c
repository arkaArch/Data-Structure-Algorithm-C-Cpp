#include <stdio.h>
#include <stdbool.h>

/* PROBLEM 1: CHECK IF A NUMBER IS POWER OF 2 OR NOT */
bool is_power_of_2(int N) {
    /* 2^4 = 16 = 10000        15 = 1111
     * 2^5 = 32 = 100000       31 = 11111 
     * 2^6 = 64 = 1000000      63 = 111111 
     *
     * So if we perform bitwise AND operator between N and N-1 it become 0 */
    if((N & (N - 1)) == 0)
        return true;
    else
        return false;
}

/* PROBLEM 2: COUNT THE NUMBER OF SET BITS IN A NUMBER */
int number_of_set_bits(int N) {
    int count = 0;
    
    while(N > 0) {
        // if(N % 2 == 1)
        /* Here we are checking for odd
         * Now: 8 = 1000, 9 = 1001, 10 = 1010, 11 = 1011, 12 = 1100, 13 = 1101 ... 
         * So, we can see that the last bit of an odd number is 1 and even number
         * is 0. So we can write:
         * if((N & 1) == 1) to check odd and 
         * if((N & 1) == 0) to check even. */

        /* Since we increase counter by 1 if it's odd and also (N & 1) = 1 if N is
         * odd we can compose the code as */
        count += N & 1;
        
        // N = N / 2;
        /* We can also overwrite divide operation of 2^k with right shift operation */
        N = N >> 1;
    }
    return count;
}

int number_of_set_bits_alt(int N) {
    /* We can do this by clear the last set bit again & again.
     * So number of set bits = number of operation to clear all set bits i.e 0 
     * and we clear the last bit by doing (N & (N - 1)) */
    int count = 0;
    while(N  > 0) {
        N = N & (N - 1);
        count++;
    }
    return count;
}

int main() {
    puts("PROBLEM 1:");
    printf("%d is %s\n", 32, is_power_of_2(32) ? "power of 2" : "not a power of 2");
    printf("%d is %s\n", 24, is_power_of_2(24) ? "power of 2" : "not a power of 2");
    printf("%d is %s\n", 53, is_power_of_2(53) ? "power of 2" : "not a power of 2");
    printf("%d is %s\n", 64, is_power_of_2(64) ? "power of 2" : "not a power of 2");

    puts("\nPROBLEM 2:");
    printf("Number of set bits in %d is %d\n", 64, number_of_set_bits(64));
    printf("Number of set bits in %d is %d\n", 63, number_of_set_bits(63));
    printf("Number of set bits in %d is %d\n", 219, number_of_set_bits_alt(219));
    return 0;
}

