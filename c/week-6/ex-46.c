#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    node * next;
    char * data;
};

const int MAX_WORD_SIZE = 80;
const int NUM_LISTS = 3;

char * read_word();
node ** return_array_of_lists(size_t);
void append_word_to_tail(char *, node **);
void free_lists(node **, size_t);
void free_list(node **);

int main() {
    node ** heads = return_array_of_lists(NUM_LISTS);
    int i;
    for (i = 0; i < NUM_LISTS; i++) {
        while (heads[i]) {
            printf("%s ", heads[i]->data);
            heads[i] = heads[i]->next;
        }
        printf("\n");
    }
    free_lists(heads, NUM_LISTS);
}

node ** return_array_of_lists(size_t num) {
    node ** head_list = (node **) malloc(num * sizeof(node *));
    node ** tail_list = (node **) malloc(num * sizeof(node *));
    size_t i = 0;
    char * word = read_word();
    while (i < num && strcmp(word, "STOP") != 0) {
        head_list[i] = (node *) malloc(sizeof(node));
        (head_list[i])->data = word;
        tail_list[i] = head_list[i];
        word = read_word();
        i++;
    }

    i = 0;
    while (strcmp(word, "STOP") != 0) {
        append_word_to_tail(word, &(tail_list[i]));
        i = (i + 1) % num;
        word = read_word();
    }

    // clean up
    if (strcmp(word, "STOP") == 0) {
        free(word);
    }
    for (i = 0; i < num; i++) {
        free(tail_list[i]);
        tail_list[i] = NULL;
    }

    return head_list;
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
        len_str--;
        word_temp[len_str] = '\0';
    }
    char * read = (char *) malloc(len_str + 1);
    strcpy(read, word_temp);
    return read;
}

void free_list(node ** pList) {
    node *pTemp;
    while (*pList) {
        pTemp = (*pList)->next;
        free((*pList)->data);
        free(*pList);
        *pList = pTemp;
    }
}

void free_lists (node ** lists, size_t size) {
    if (lists == NULL) return;
    size_t i;
    for (i = 0; i < size; i++) {
        free_list(&(lists[i]));
        free(lists[i]);
    }
}
