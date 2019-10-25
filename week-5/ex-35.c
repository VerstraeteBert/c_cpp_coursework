#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const size_t MAX_SENT_SIZE = 10;
const size_t MAX_SENTS = 6;

char * lees() {
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

char ** lees_meerdere() {
    char * s_temp [MAX_SENTS];
    int num_read = 0;
    char * temp_read = lees();
    while (num_read < MAX_SENTS && strcmp(temp_read, "STOP") != 0) {
        s_temp[num_read] = temp_read;
        num_read++;
        temp_read = lees();
    }
    if (strcmp(temp_read, "STOP") == 0) {
        free(temp_read);
    }
    char ** strings = malloc(num_read * sizeof(char*) + 1);
    int i;
    for (i = 0; i < num_read; i++) {
        strings[i] = s_temp[i];
    }
    return strings;
}

void plaats_ptr_op_str(char *** haystack, char needle) {
    while (haystack != NULL && **haystack[0] != needle) {
        (*haystack)++;
    }
}

int main(){
    char ** strings = lees_meerdere();
    int i = 0;
    plaats_ptr_op_str(&strings, 'b');
    if (strings != NULL) {
        printf("%s\n", *strings);
    }
    while(strings[i] != NULL) {
        printf("Ik las ***%s*** \n", strings[i]);
        free(strings[i]);
        i++;
    }
    free(strings);
    return 0;
}
