#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const size_t MAX_SENT_SIZE = 10;
const size_t MAX_SENTS = 3;

char * read_single() {
    char s [MAX_SENT_SIZE];
    printf("Input line:\n");
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

char ** read_mult() {
    char * tmp_arr [MAX_SENTS];
    char * tmp_read = read_single();
    int num_read = 0;
    while (num_read < MAX_SENTS - 1 && strcmp(tmp_read, "STOP") != 0) {
        tmp_arr[num_read] = tmp_read;
        num_read++;
        tmp_read = read_single();
    }
    if (strcmp(tmp_read, "STOP") != 0) {
        tmp_arr[num_read] = tmp_read;
        num_read++;
    } else {
        free(tmp_read);
    }

    char ** strings = malloc((num_read + 1) * sizeof(char*));
    int i;
    for (i = 0; i < num_read; i++) {
        strings[i] = tmp_arr[i];
    }
    strings[i] = NULL;
    return strings;
}

void plaats_ptr_op_str(char *** haystack, char needle) {
    if (haystack == NULL) return;

    while (*haystack != NULL && **haystack != NULL && **haystack[0] != needle) {
        printf("%s", **haystack);
        (*haystack)++;
    }
}

int main(){
    char ** strings = read_mult();
    int i = 0;

    char ** cp_ptr = strings;
    plaats_ptr_op_str(&strings, 'b');
    if (*strings != NULL) {
        printf("Found in string: %s\n", *strings);
    }

    // cleanup
    while(cp_ptr[i] != NULL) {
        printf("I read ***%s***\n", cp_ptr[i]);
        free(cp_ptr[i]);
        i++;
    }

    return 0;
}
