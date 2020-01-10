#include <stdio.h>
#include <string.h>

void my_tupper(char * s) {
    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] = 'A' +  (s[0] - 'a');
    }
    int i = 1;
    while (s[i]) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'a' + (s[i] - 'A');
        }
        i++;
    }
}

const char * alfab_kleinste(const char * const * p_strings, size_t aant) {
    const char * smallest = p_strings[1];
    size_t i;
    for (i = 2; i < aant; i++) {
        if (strcmp(smallest, p_strings[i]) > 0) {
            smallest = p_strings[i];
        }
    }
    return smallest;
}

int main(int argc, char * argv []) {
    int i;
    const char * kleinste;
    if (argc == 1) {
        printf("Dag allemaal!\n");
    } else {
        for (i = 1; i < argc; i++) {
            my_tupper(argv[i]);
        }
        kleinste = alfab_kleinste((const char * const *) argv + 1, argc - 1);
        printf("Dag %s!", kleinste);
    }
}
