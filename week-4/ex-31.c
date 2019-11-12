#include <stdio.h>

void greet(char * names [], int size);
void greet_printer(const char * name);
void initcap(char * str);

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

void greet_printer(const char * name) {
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
        greet_printer(names[i]);
    }
}
