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

node * merge(node ** a, node ** b){
    node * dest_list;
    node * dest_node;

    // a is leeg
    if (!(*a)) {
        dest_list = *b;
        *b = NULL;
        return dest_list;
    }
    // b is leeg
    if (*b == NULL) {
        dest_list = *a;
        *b = NULL;
        return dest_list;
    }

    // zelfde lijsten
    if (&(*a) == &(*b)) {
        dest_list = *a;
        *b = NULL;
        *a = NULL;
        return dest_list;
    }
    //
    if ((*a)->value < (*b)->value) {
        dest_node = *a;
        *a = (*a)->next;
    } else {
        dest_node = *b;
        *b = (*b)->next;
    }

    dest_list = dest_node;

    while(*a && *b){
        if((*a)->value < (*b)->value){
            dest_node->next = (*a);
            *a = (*a)->next;
        }
        else{
            dest_node->next = (*b);
            (*b) = (*b)->next;
        }
        dest_node = dest_node->next;
    }

    while((*a) != 0){
        dest_node->next = *a;
        dest_node = dest_node->next;
        *a = (*a)->next;
    }
    while((*b) != 0){
        dest_node->next = *b;
        dest_node = dest_node->next;
        *b = (*b)->next;
    }

    return dest_list;
}

int main(){
    srand(time(NULL));
    node * m = create_list(10,1000);
    node * n = create_list(5,1000);
    printf("\nLIJST m:\n"); print_list(m);
    printf("\nLIJST n:\n"); print_list(n);
    printf("\nDeze worden gemerged. \n\n");
    node * res = merge(&m, &m);
    printf("\nLIJST m: \n"); print_list(m);
    printf("\nLIJST n: \n"); print_list(n);
    printf("\nRESULTAAT: \n"); print_list(res);

    free_list(&res);

    return 0;
}