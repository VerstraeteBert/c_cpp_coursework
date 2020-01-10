#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const size_t MAX_SENT_SIZE = 10;
const size_t MAX_SENTS = 6;

char * read_single() {
    char temp [MAX_SENT_SIZE + 1];
    fgets(temp, MAX_SENT_SIZE + 1, stdin);
    size_t len = strlen(temp);
    if (temp[len - 1] == '\n') {
        temp[len - 1] = '\0';
        len--;
    }
    char * word = (char *) malloc((len + 1) * sizeof(char));
    strcpy(word, temp);
    return word;
}

char ** read_multi() {
    char * temp_sents[MAX_SENTS];
    int words_read = 0;
    char * temp = read_single();
    while (words_read < MAX_SENTS - 1 && strcmp("STOP", temp) != 0) {
        temp_sents[words_read] = temp;
        words_read++;
        temp = read_single();
    }

    if (words_read == MAX_SENTS - 1 && strcmp("STOP", temp) != 0) {
        temp_sents[words_read] = temp;
        words_read++;

    } else {
        free(temp);
    }

    char ** sents = (char **) malloc((words_read + 1) * sizeof(char*));
    int i;
    for (i = 0; i < words_read; i++) {
        sents[i] = temp_sents[i];
    }
    sents[i] = NULL;
    return sents;
}

int main(){
    char ** strings = read_multi();
    int i = 0;
    while(strings[i]) {
        printf("Ik las ***%s*** \n", strings[i]);
        free(strings[i]);
        i++;
    }
    free(strings);
    return 0;
}
