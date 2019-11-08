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
}

void free_list(node ** pList) {
    node *pTemp;
    while (*pList) {
        pTemp = (*pList)->next;
        free(*pList);
        *pList = pTemp;
    }
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

void delete_duplicates(node * pNode) {
    node * to_delete = NULL;
    while(pNode != NULL) {
        while(pNode->next != NULL && pNode->value == pNode->next->value) {
            to_delete = pNode->next;
            pNode->next = pNode->next->next;
            free(to_delete);
        }
        pNode = pNode->next;
    }
}

int main() {
    srand(time(NULL));
    node * pList = create_list(10, 100);
    print_list(pList);
    printf("\nnu worden dubbels verwijderd: \n");
    delete_duplicates(pList);
    printf("\nna verwijderen van dubbels: \n\n");
    print_list(pList);
    free_list(&pList);
    return 0;
}
