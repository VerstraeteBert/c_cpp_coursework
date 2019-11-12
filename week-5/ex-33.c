#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_SIZE = 1000;

char * lees () {
    char read [MAX_SIZE];
    fgets(read, MAX_SIZE, stdin);
    fflush(stdin);
    char * p_str = (char *) malloc(strlen(read) + 1);
    if (p_str == NULL) return NULL;
    strcpy(p_str, read);
    return p_str;
}

int main () {
    int i;
    for (i = 0; i < 5; i++) {
        char * tekst = lees();
        printf("%s", tekst);
        free(tekst);
    }
}
