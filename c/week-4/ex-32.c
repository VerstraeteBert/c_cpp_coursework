#include <stdio.h>
#include <string.h>

void greet(char * names [], int size);
void greet_printer(char * name);
void initcap(char * str);
char * alpha_smallest(char * [], int);

int main (int argc, char * argv []) {
    if (argc < 1) {
        greet_printer("allemaal");
    } else {
        greet(argv + 1, argc - 1);
    }
    return 0;
}

void initcap(char * str) {
    if (str == NULL) return;

    size_t i = 0;
    if (str[i] && (str[i] >= 'a' && str[i] <= 'z')) {
        str[i] += ('A' - 'a');
    }
    i++;
    while(str[i]) {
        if (str[i] >= 'A' &&  str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
        i++;
    }
}

char * alpha_smallest(char * strings [], int size) {
    if (strings == NULL) return NULL;
    char * smallest = strings[0];
    int i;
    for (i = 1; i < size; i++) {
        if (strcmp(smallest, strings[i]) > 0) {
            smallest = strings[i];
        }
    }
    return smallest;
}

void greet_printer(char * name) {
    printf("Dag %s!\n", name);
}

void greet(char * names [], int size) {
    if (size == 0) {
        greet_printer("allemaal");
        return;
    }

    int i;
    for (i = 0; i < size; i++) {
        initcap(names[i]);
    }

    char * smallest = alpha_smallest(names, size);

    greet_printer(smallest);
}
