#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const size_t MAX_SENT_SIZE = 10;
const size_t MAX_SENTS = 6;

char * read_single() {
    char s [MAX_SENT_SIZE];
    printf("Geef tekst in:\n");
    fgets(s, MAX_SENT_SIZE, stdin);
    fflush(stdin);
    size_t len_str = strlen(s);
    if (s[len_str - 1] == '\n')  {
        s[len_str - 1] = '\0';
    }
    char * read = (char *) malloc(len_str);
    strcpy(read, s);
    return read;
}

char ** read_multi() {
    char * temp_sents [MAX_SENTS];
    int read = 0;
    char * temp = read_single();
    while (read < MAX_SENTS - 1 && strcmp(temp, "STOP") != 0) {
        temp_sents[read] = temp;
        read++;
        temp = read_single();
    }
    if (strcmp(temp, "STOP") == 0) {
        free(temp);
    }
    char ** sents = (char **) malloc(read + 1 * sizeof(char *));
    int i;
    for (i = 0; i < read; i++) {
        sents[i] = temp_sents[i];
    }
    sents[i] = NULL;
    return sents;
}

int main(){
    char ** strings = read_multi();
    int i = 0;
    while(strings[i] != NULL) {
        printf("Ik las ***%s*** \n", strings[i]);
        free(strings[i]);
        i++;
    }
    free(strings);
    return 0;
}
