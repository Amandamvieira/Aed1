#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        // Converte caracteres para minúsculas
        char c1 = tolower(s[left]);
        char c2 = tolower(s[right]);
        
        // Ignora caracteres não alfanuméricos
        if (!isalnum(c1)) {
            left++;
            continue;
        }
        
        if (!isalnum(c2)) {
            right--;
            continue;
        }
        
        // Verifica se os caracteres são diferentes
        if (c1 != c2) {
            return false;
        }
        
        // Avança para o próximo par de caracteres
        left++;
        right--;
    }
    
    return true;
}

int main() {
    char s[] = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(s);
    
    if (result) {
        printf("É um palíndromo.\n");
    } else {
        printf("Não é um palíndromo.\n");
    }
    
    return 0;
} 