#include <ctype.h>
#include <stdio.h>

const size_t INPUT_SIZE = 100;

void wis(char * p_str) {
    if (p_str == NULL) return;
    while (*p_str) {
        if (!isspace(*p_str) || !islower(*p_str)) {
            *p_str = ' ';
        }
        p_str++;
    }
}

void write(const char * s) {
    printf("%s", s);
}

int main() {
    char input [INPUT_SIZE];
    fgets(input, INPUT_SIZE, stdin);
    wis(input);
    write(input);

    char test [] = "8d’a7!<t-)>+. -)4h&!e9)b*( )j’(e)!4\n8g|'92o!43e5d/.’ 2 3g*(e(’d22a’(a25n’(";
    wis(test);
    write(test);
    return 0;
}
