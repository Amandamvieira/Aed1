#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;
    char* result = longestCommonPrefix(strs, strsSize);
    printf("Longest common prefix: %s\n", result);
    free(result);
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 1) return strs[0];
    if (strlen(strs[0]) == 0) return strs[0];

    char* ans = (char*) malloc(200 * sizeof(char));
    int check = 0;
    int k = 0;
    for (int i = 0; strs[0][i] != '\0'; i++) {
        ans[k] = strs[0][i];
        k++;
        for (int j = 1; j < strsSize; j++) {
            if (ans[i] != strs[j][i]) {
                check = 1;
                k--;
                break;
            }
        }
        if (check) {
            break;
        }
    }   
    ans[k] = '\0';
    return ans;
}