#include <stdio.h>
#include <string.h>

void greet_name(char * name) {
    printf("Hi %s!\n", name);
}

void ex_initcap(char * s) {
    if (s[0] >= 97 && s[0] <= 122) {
        s[0] -= 32;
    }
    size_t i;
    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
    }
}

void greet(char ** names, size_t size) {
    if (size == 1) {
        greet_name("everyone");
        return;
    }

    size_t i;
    for (i = 1; i < size; i++) {
        ex_initcap(names[i]);
        greet_name(names[i]);
    }
}

int main(int argc, char** argv) {
    greet(argv, argc);
    return 0;
}
