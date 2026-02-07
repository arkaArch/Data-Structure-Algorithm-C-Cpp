#include <stdio.h>

int power(int num, int power) {
    int result = 1;
    while (power > 0) {
        result *= num;
        power--;
    }
    return result;
}

int binary_to_decimal(long long binary) {
    int decimal = 0, power_of_2 = 0;
    while(binary > 0) {
        int rem = binary % 10;
        decimal += rem * power(2, power_of_2);
        power_of_2++;
        binary /= 10;
    }
    return decimal;
}

int main() {
    long long binary;
    printf("Enter binary: ");
    scanf("%lld", &binary);
    printf("Decimal: %d\n", binary_to_decimal(binary));
    return 0;
}
