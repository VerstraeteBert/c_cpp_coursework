#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    node * next;
    char * data;
};

const int MAX_WORD_SIZE = 80;

char * read_word();
node ** return_array_of_lists(size_t);
void append_word_to_tail(char *, node **);
void free_lists(node ** list);

int main() {
    node ** heads = return_array_of_lists(3);
    int i;
    for (i = 0; i < 3; i++) {
        while (heads[i]) {
            printf("%s ", heads[i]->data);
            heads[i] = heads[i]->next;
        }
        printf("\n");
    }
}

node ** return_array_of_lists(size_t num) {
    node * head_arr[num];
    node * tail_arr[num];
    size_t i;
    for (i = 0; i < num; i++) {
        node dummy;
        head_arr[i] = &dummy;
        tail_arr[i] = head_arr[i];
        printf("%p\n", (void*) &dummy);
    }

    i = 0;
    char * word = read_word();
    while (strcmp(word, "STOP") != 0) {
        append_word_to_tail(word, &(tail_arr[i % num]));
        word = read_word();
    }

    for (i = 0; i < num; i++) {
        head_arr[i] = (head_arr[i])->next;
        tail_arr[i] = NULL;
    }
    return head_arr;
}

void append_word_to_tail(char * word, node ** curr_tail) {
    node * new_tail = (node *) malloc(sizeof(node));
    new_tail->data = word;
    (*curr_tail)->next = new_tail;
    (*curr_tail) = (*curr_tail)->next;
}

char * read_word() {
    char word_temp [MAX_WORD_SIZE];
    fgets(word_temp, MAX_WORD_SIZE, stdin);
    fflush(stdin);
    size_t len_str = strlen(word_temp);
    if (word_temp[len_str - 1] == '\n')  {
        word_temp[len_str - 1] = '\0';
    }
    char * read = (char *) malloc(len_str);
    strcpy(read, word_temp);
    return read;
}
