#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_DUP 50  // Assume maximum no of duplicate words are 50

bool is_present(char A[], int length, char key) {
    for(int i = 0; i < length; i++) {
        if(A[i] == key)
            return true;
    }
    return false;
}

char* duplicates(const char* str) {
    /* There are 26 alphates in english
     * Now here we take 32 bits(can't take specific 26 bits) and treat each bit as
     * hash array. And when we find any duplicates we set the bit. */
    int hash = 0;
    char* dup_words = (char*)malloc(sizeof(char) * MAX_DUP);
    int index = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if((hash & (1 << str[i])) != 0) {     // Bit is set
            /* Check if the duplicate already present in dup_arr */
            if(!is_present(dup_words, index, str[i]))
                /* store the duplicates */
                dup_words[index++] = str[i];
        } else { // set the bit
            hash = hash | (1 << str[i]);
        }
    }
    dup_words[index] = '\0';
    return dup_words;
}

int main() {
    char* dw = duplicates("independence");
    for(int i = 0; dw[i] != '\0'; i++)
        printf("%c ", dw[i]);
    printf("\n");

    return 0;
}
