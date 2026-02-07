#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Input: Live on evasions? No, I save no evil. 
 * Output: True */

bool is_alphabet(char ch) {
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
        return true;
    return false;
}

char* str_reverse(const char* str) {
    /* Make a mutable string of 'str' to make it reverse */
    int size = strlen(str);
    char* copy_str = (char *)malloc(size + 1);
    if (copy_str == NULL) return NULL;
    strcpy(copy_str, str);
    
    int i = 0, j = strlen(copy_str) - 1;
    while(i < j) {
        /* If characters are both alphabets, swap them and move indeces */
        if(is_alphabet(copy_str[i]) && is_alphabet(copy_str[j])) {
            char temp = copy_str[i];
            copy_str[i] = copy_str[j];
            copy_str[j] = temp;
            i++, j--;
        } 
        /* If a character is non-alphabet, move index of this particular character */
        else if(is_alphabet(copy_str[i]) && !is_alphabet(copy_str[j]))
            j--;
        else if(is_alphabet(copy_str[j]) && !is_alphabet(copy_str[i]))
            i++;
        /* If both are non-alphabets, move both indeces */
        else
            i++, j--;
    } 
    return copy_str;
}



char* to_lower(const char* str) {
    int size = strlen(str);
    char* new_str = (char *)malloc(size + 1);   // Take 1 extra for '\0' character
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

bool is_palindrome(const char* str) {
    /* first change the string into lower case and then compare */
    char* str_lower = to_lower(str);
    char* str_rev = str_reverse(str_lower);
    if(strcmp(str_lower, str_rev) == 0)
        return true;
    return false;
}

int main() {
    char *const str_arr[] = { 
        "Hello", 
        "Civic", 
        "Are you happy?",
        "Live on evasions? No, I save no evil.",
        "Marge, let's \"went.\" I await news telegram."
    };

    for(int i = 0; i < sizeof(str_arr)/sizeof(str_arr[0]); i++) {
        printf("Reverse of (%s): %s\n", str_arr[i], str_reverse(str_arr[i]));
        printf("Palindrome check(%s): %s\n", 
               str_arr[i], is_palindrome(str_arr[i]) ? "True" : "False");
        printf("\n");
    }

    return 0;
}
