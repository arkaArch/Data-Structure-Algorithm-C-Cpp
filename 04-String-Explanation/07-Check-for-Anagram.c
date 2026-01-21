#include <stdio.h>
#include <stdbool.h>

bool is_anagram(const char* str1, const char* str2) {
    /* An anagram string is a word or phrase formed by rearranging the letters of 
     * another, meaning both have the exact same characters with the exact same 
     * frequency, just in a different order */

    /* Now take a hash array, count character occurrences in the first string, 
     * then decrease counts while scanning the second; if all counts end at zero, 
     * they are anagrams. */
    int hash[26] = {0};
    for(int i = 0; str1[i] != '\0'; i++) {
        if(str1[i] >= 'A' && str1[i] <= 'Z')        // For capital letter
            hash[(str1[i] + 32) - 'a'] += 1;
        else if(str1[i] >= 'a' && str1[i] <= 'z')   // For small letter
            hash[str1[i] - 'a'] += 1;
    }

    for(int i = 0; str2[i] != '\0'; i++) {
        if(str2[i] >= 'A' && str2[i] <= 'Z')        // For capital letter
            hash[(str2[i] + 32) - 'a'] -= 1;
        else if(str2[i] >= 'a' && str2[i] <= 'z')   // For small letter
            hash[str2[i] - 'a'] -= 1;
    }

    for(int i = 0; i < 26; i++) {
        if(hash[i] != 0)
            return false;
    }
    return true;
}

int main() {
    printf("%s and %s are anagram? %s\n", "heaart", "earrth", 
            is_anagram("heaart", "earrth") ? "Yes" : "No");
    printf("%s and %s are anagram? %s\n", "Desserts", "Stressed", 
            is_anagram("Desserts", "Stressed") ? "Yes" : "No");
    printf("%s and %s are anagram? %s\n", "decinal", "medical", 
            is_anagram("decinal", "medical") ? "Yes" : "No");
    printf("%s and %s are anagram? %s\n", "triangle", "integral", 
            is_anagram("triangle", "integral") ? "Yes" : "No");
    printf("\"%s\" and \"%s\" are anagram? %s\n", "A Gentleman", "Elegant Man",
            is_anagram("A Gentleman", "Elegant Man") ? "Yes" : "No");
    return 0;
}
