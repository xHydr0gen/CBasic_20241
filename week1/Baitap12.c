#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, count[26] = {0};
    char c = '\0';
    c = getchar();
    while (c != '\n' && c >= 0) {
        if (c <= 'z' && c >= 'a') count[c - 'a']++;
        if (c <= 'Z' && c >= 'A') count[c - 'A']++;
        c = getchar();
    }
    for (i = 0; i < 26; i++) {
        if (count[i] > 0) printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
    }
    return 0;
}
