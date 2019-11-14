#include <stdio.h>
#include <stdlib.h>
#include <ranlib.h>
#include <time.h>
#include <assert.h>

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

void add_value(int number, node ** p_node) {
    while (*p_node && (*p_node)->value < number) {
        p_node = &((*p_node)->next);
    }
    node * new_node = (node *) malloc(sizeof(node));
    new_node->value = number;
    new_node->next = *p_node;
    *p_node = new_node;
}
int main(){
    srand(time(NULL));
    node * m = create_list(10,1000);
    add_value(200, &m);
    add_value(190, &m);
    add_value(210, &m);
    add_value(50000, &m);
    printf("LIJST m:\n"); print_list(m);
    free_list(&m);
    return 0;
}
