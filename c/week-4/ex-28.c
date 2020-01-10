#include "stdio.h"

const size_t SIZE_INPUT = 100;

void wis (char * s) {
    char * loper = s;
    while (*loper) {
        if (isspace(*loper) || islower(*loper)) {
            *s = *loper;
            s++;
        }
        loper++;
    }
    *s = '\0';
}

int main (void) {
    char s [SIZE_INPUT];
    fgets(s, SIZE_INPUT, stdin);
    wis(s);
    printf("%s", s);
    return 0;
}
