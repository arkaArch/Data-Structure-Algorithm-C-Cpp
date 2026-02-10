#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* to_lower(const char* str) {
    int size = strlen(str);
    char* new_str = (char *)malloc(size + 1);
    if (new_str == NULL) return NULL;

    int i = 0;
    while(str[i] != '\0') {
        /* Check if the words are actually belongs to alphabet */
        if(str[i] >= 'A' && str[i] <= 'Z')
            new_str[i] = str[i] + 32;
        else
            new_str[i] = str[i];
        i++;
    }
    return new_str;
}

void find_duplicates(const char* str) {
    /* Copy to a mutable string */
    char str_lower[400];
    strcpy(str_lower, to_lower(str));
    for(int i = 0; str_lower[i] != '\0'; i++) {
        int count = 1;  // Letter appears for first time
        for(int j = i+1; str_lower[j] != '\0'; j++) {
            if(str_lower[i] == str_lower[j]) {
                /* Swap the duplicate character with the next position of i 
                 * i.e when we find a duplicate character store it contiguous 
                 * position to reduce search space */
                char temp = str_lower[i+1];
                str_lower[i+1] = str_lower[j];
                str_lower[j] = temp;
                i++, count++;
            }
        }
        if(count > 1)
            printf("%c appears %d times.\n", str_lower[i], count);
    }
    printf("................\n");
    /* Time complexity: O(N^2); Auxiliary space: O(1) */
}

void find_duplicates_hash(const char* str) {
    const char* str_lower = to_lower(str);
    /* Create a hash array of size 26(number of alphabet)
     * Try to represent 97 to 122 in hash array */
    int hash[26] = {0};
    for(int i = 0; i <= strlen(str_lower); i++)
       hash[str_lower[i] - 'a'] += 1;    // More readable than "str_lower[i] - 97"

    for(int i = 0; i < 26; i++) {
        if(hash[i] > 1)
            printf("%c appears %d times.\n", i + 'a', hash[i]);
    }
    /* Time complexity: O(N); Auxiliary space: O(N) */
}

int main() {
    const char* str = "Independence";
    find_duplicates(str);
    find_duplicates_hash(str);

    return 0;
}
