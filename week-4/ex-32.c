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

char * alpha_b_smallest(char** strings, size_t size) {
    if (size == 0) {
        return "";
    }

    size_t i; size_t j;
    size_t idx_smallest = 0;
    size_t len_compar;
    size_t highest_len = strlen(strings[idx_smallest]);

    for (i = 1; i < size; i++) {
        len_compar = strlen(strings[i]);
        highest_len =  highest_len < len_compar ? highest_len : len_compar;
        for (j = 0; j < highest_len; j++) {
            if (strings[idx_smallest][j] < strings[i][j]) {
                break;
            }
            if (strings[idx_smallest][j] > strings[i][j]) {
                idx_smallest = i;
                highest_len = strlen(strings[idx_smallest]);
                break;
            }
        }
    }
    return strings[idx_smallest];
}

void greet_alphab_smallest(char ** names, size_t size) {
    if (size == 0) {
        greet_name("everyone");
        return;
    }

    char * smallest = alpha_b_smallest(names, size);
    greet_name(smallest);
}

int main(int argc, char** argv) {
    greet_alphab_smallest(argv + 1, argc - 1);
    return 0;
}
