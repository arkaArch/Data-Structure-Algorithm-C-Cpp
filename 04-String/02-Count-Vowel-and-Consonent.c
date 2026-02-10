#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_vowel(char c) {
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
    c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int number_of_vowel(const char* str) {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(is_vowel(str[i]))
            count++;
    }
    return count;
}

int number_of_consonent(const char* str) {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            if(!is_vowel(str[i]))
                count++;
    }
    return count;
}

int number_of_word(const char* str) {
    int count = 1;  // You have to pass a word as a input of the function
    for(int i = 0; str[i] != 0; i++) {
        if(str[i] == ' ')
            count++;
    }
    return count;
}


int number_of_word_II(char const *str) {
    /* Since string literals are usually stored in read-only memory, so passing it 
     * directly to strtok(), where strtok() tries to modify it and then the function 
     * will behave incorrectly and can give "segmentation fault (core dumped)" error. */
    char *duplicate_str = strdup(str);
    char *token = strtok(duplicate_str, " ");
    int count = 0;
    while(token != NULL) {
        count ++;
        // Get the next token by passing NULL as the first argument
        token = strtok(NULL, " ");
    }
    return count;
}

int main() {
    const char* msg = "How are you?";
    printf("Number of vowel and consonent: %d, %d\n", number_of_vowel(msg), 
           number_of_consonent(msg));
    printf("Number of word: %d\n", number_of_word(msg));
    printf("Number of word: %d\n", number_of_word(msg));
    return 0;
}

