#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* It is not technically "wrong" to declare a string in C using char* str = "Hello", 
 * but it is deprecated and generally considered poor practice for several important 
 * reasons related to memory safety and the C standard.
 * 
 * The main issue is that string literals in C (like "Hello") are stored in a read-only
 * memory segment. When you use char*, you're declaring a pointer that could 
 * theoretically be used to modify the contents of the string, which results in 
 * undefined behavior at runtime if you try to modify it
 * 
 * Use the const keyword to explicitly tell the compiler and other programmers that 
 * this string should not be modified. This is the safest approach when you are working 
 * with a string literal.
 *
 * If you need to change the contents of the string (e.g., in-place modification), 
 * you must declare it as an array of characters. This copies the string literal into a
 * modifiable memory area (usually the stack). */


/* Changing string from lower_case to upper_case */
char* to_upper(const char* str) {
    int size = strlen(str);
    char* new_str = (char *)malloc(size + 1);   // Take 1 extra for '\0' character
    if (new_str == NULL) return NULL;

    int i = 0;
    while(str[i] != '\0') {
        /* Check if the words are actually belongs to alphabet */
        if(str[i] >= 'a' && str[i] <= 'z')
            /* In ascii a = 97 and A = 65 */
            new_str[i] = str[i] - 32;
        else
            new_str[i] = str[i];
        i++;
    }
    return new_str;
}

/* Changing string from upper_case to lower_case */
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

int main() {
    char *str_upper = to_upper("Hello (World)!");
    char *str_lower = to_lower("hAVE - a + NIcE -- DAY.");
    if(str_upper != NULL) {
        printf("%s\n", str_upper);
        free(str_upper);
    }
    if(str_lower != NULL) {
        printf("%s\n", str_lower);
        free(str_lower);
    }
    return 0;
}
