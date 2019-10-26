#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const size_t MAX_SIZE = 10;

char * lees() {
    char s [MAX_SIZE];
    printf("Geef tekst in:\n");
    fgets(s, MAX_SIZE, stdin);
    fflush(stdin);
    size_t len_str = strlen(s);
    char * read = (char *) malloc(len_str - 1);
    strcpy(read, s);
    return read;
}

int main(){
    int i;
    for(i=0; i<5; i++){
        char * tekst = lees();
        printf("Ik las ***%s*** \n",tekst);
        free(tekst);
    }
    return 0;
}
