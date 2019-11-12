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

void add_value(int value, node ** pNode) {
    while (*pNode && (*pNode)->value < value) {
        pNode = &((*pNode)->next);
    }

    node * temp = *pNode;

    *pNode = (node *) malloc(sizeof(node));
    (*pNode)->value = value;
    (*pNode)->next = temp;
}

void print_list(const node * head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
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

void free_rec(int x, node **pNode) {
    if (*pNode == NULL) return;
    if ((*pNode)->value == x) {
        node * temp = *pNode;
        *pNode = (*pNode)->next;
        free(temp);
    } else {
        delete_rec(x, &((*pNode)->next));
    }
}

//void delete(int x, node **pNode) {
//    while (*pNode && (*pNode)->value < x) {
//        pNode = &((*pNode)->next);
//    }
//
//    if (*pNode && (*pNode)->value == x) {
//        node * temp = *pNode;
//        (*pNode) = (*pNode)->next;
//        free(temp);
//    }
//}
//

int main() {
    srand(time(NULL));
    node * pList = create_list(10, 100);
    add_value(20, &pList);
    add_value(50, &pList);
    add_value(120, &pList);
    print_list(pList);
    delete_rec(50, &pList);
    delete_rec(120, &pList);
    delete_rec(20, &pList);
    print_list(pList);
    free_rec(&pList);
    return 0;
}
