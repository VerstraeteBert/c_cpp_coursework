#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
    int value;
    node * next;
};

void add_front(const int value, node ** head) {
    node * temp = *head;
    node * new_node = (node *) malloc(sizeof(node));
    new_node->value = value;
    new_node->next = temp;
    *head = new_node;
}

void print_list(const node * head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
}

void free_list(node ** pList) {
    node *pTemp;
    while (*pList != NULL) {
        pTemp = (*pList)->next;
        free(*pList);
        *pList = pTemp;
    }
}

int main() {
    node * head = NULL;
    add_front(7, &head);
    add_front(24, &head);
    print_list(head);
    free_list(&head);
    print_list(head);
}
