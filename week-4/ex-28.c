#include <ctype.h>
#include <stdio.h>

const size_t INPUT_SIZE = 100;

void wis(char * s, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        // is \n "whitespace" ?
        if ((!islower(s[i]) && !isspace(s[i]))) {
            s[i] = ' ';
        }
    }
}

void write(const char * s) {
    printf("%s", s);
}

int main() {
    char input [100];
    fgets(input, INPUT_SIZE, stdin);
    wis(input, INPUT_SIZE);
    write(input);

    char test [] = "8d’a7!<t-)>+. -)4h&!e9)b*( )j’(e)!4\n8g|'92o!43e5d/.’ 2 3g*(e(’d22a’(a25n’(";
    wis(test, sizeof(test) / sizeof(char));
    write(test);
    return 0;
}
