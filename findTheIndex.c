//leetcode https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int i, j = 0, k = 0, m, f = 0;
    
    if (strlen(needle) == 0)
        return 0;
    
    if (strlen(haystack) < strlen(needle))
        return -1;
    
    for (i = 0; i < strlen(haystack) - strlen(needle) + 1; i++) {
        if (haystack[i] == needle[0]) {
            for (j = 1; j < strlen(needle); j++) {
                if (haystack[i + j] != needle[j]) {
                    f = 1;
                    break;
                }
            }
            if (f == 1)
                f = 0;
            else
                return i;
        }
    }
    return -1;
}

int main() {
    char haystack[] = "Hello, World!";
    char needle[] = "World";
    int result = strStr(haystack, needle);
    
    printf("Result: %d\n", result);
    
    return 0;
}