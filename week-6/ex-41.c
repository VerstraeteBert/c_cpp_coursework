#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    if (!head) {
        printf("X");
    }
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void free_list(node ** pList) {
    node *pTemp;
    while (*pList) {
        pTemp = (*pList)->next;
        free(*pList);
        *pList = pTemp;
    }
}

node * create_list(int size, int upper_bound) {
    node * l = NULL;
    int i;
    int curr = upper_bound;
    for (i = 0; i < size; i++) {
        add_front(curr, &l);
        curr -= rand() % 3;
    }
    return l;
}

void delete_dups(node * p_node) {
    while (p_node && p_node->next) {
        if (p_node->value == p_node->next->value) {
            node * to_delete = p_node->next;
            p_node->next = p_node->next->next;
            free(to_delete);
        }
        p_node = p_node->next;
    }
}

int main() {
    srand(time(NULL));
    node * pList = create_list(10, 100);
    print_list(pList);
    printf("nu worden dubbels verwijderd: \n");
    delete_dups(pList);
    printf("na verwijderen van dubbels: \n");
    print_list(pList);
    free_list(&pList);
    print_list(pList);
    return 0;
}
