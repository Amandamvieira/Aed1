#include <stdio.h>
#include <stdlib.h>

int getInt(char *s, int *i) {
    int j = ++(*i);
    while (s[*i] == ' ' || (s[*i] >= '0' && s[*i] <= '9')) {
        ++(*i);
    }
    return atoi(s + j);
}

int calculate(char *s) {
    int i = -1, res = 0, temp = getInt(s, &i);
    while (s[i]) {
        if (s[i] == '*') {
            temp *= getInt(s, &i);
        } else if (s[i] == '/') {
            temp /= getInt(s, &i);
        } else if (s[i] == '+') {
            res += temp;
            temp = getInt(s, &i);
        } else if (s[i] == '-') {
            res += temp;
            temp = -getInt(s, &i);
        }
    }
    return res + temp;
}

int main() {
    char expression[] = "2 + 3 * 4 - 6 / 2";
    int result = calculate(expression);
    printf("Result: %d\n", result);
    return 0;
}