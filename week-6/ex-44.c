#include <stdio.h>
#include <stdlib.h>
#include <ranlib.h>
#include <time.h>

typedef struct node node;

struct node {
    int value;
    node * next;
};

void add_front(const int value, node ** head) {
    node * new_node = (node *) malloc(sizeof(node));
    new_node->value = value;
    node * prev_head = *head;
    *head = new_node;
    (*head)->next = prev_head;
}

void print_list(const node * head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void free_list_rec(node ** pList) {
    if ((*pList)->next) {
        free_list_rec(&((*pList)->next));
    }
    printf("Freeing: %d\n", (*pList)->value);
    free(*pList);
}

node * create_list(const int num, const int upper_bound) {
    node * head = NULL;
    int i;
    int curr_val = upper_bound;
    for (i = 0; i < num; i++) {
        curr_val -= rand() % 3;
        add_front(curr_val, &head);
    }
    return head;
}

void free_rec(node ** pNode) {
    if ((*pNode)->next) {
        free_rec(&((*pNode)->next));
    }
    free(*pNode);
    *pNode = NULL;
}

int main() {
    srand(time(NULL));
    node * pList = create_list(10, 100);
    print_list(pList);
    free_list_rec(&pList);
    return 0;
}
