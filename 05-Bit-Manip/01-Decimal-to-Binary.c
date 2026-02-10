#include <stdio.h>
#include <stdlib.h>

char* reverse(char* str, int start_index, int end_index) {
    /* This function reverse the character array inside a particular range */
    while (start_index < end_index) {
        char temp = str[start_index];
        str[start_index] = str[end_index];
        str[end_index] = temp;
        start_index ++;
        end_index --;
    }
    return str;
}

char* decimal_to_binary(int decimal) {
    int no_of_bits = sizeof(int) * 8;
    char *binary = (char *)malloc(no_of_bits * sizeof(char));
    int index = 0;
    if(decimal == 0) {
        binary[index++] = '0';
    } else {
        while(decimal > 0) {
            char bit = decimal % 2;
            binary[index++] = '0' + bit;    // transfer 1 & 0 to character
            decimal /= 2;
        }
    }
    binary[index] = '\0';
    reverse(binary, 0, index - 1);
    return binary;
}

int main() {
    int decimal;
    printf("Enter decimal: ");
    scanf("%d", &decimal);
    char* binary = decimal_to_binary(decimal);
    for(int i = 0; binary[i] != '\0'; i++)
        printf("%c", binary[i]);
    printf("\n");
    free(binary);
    return 0;
}
