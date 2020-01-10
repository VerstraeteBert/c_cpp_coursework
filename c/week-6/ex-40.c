#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node {
    int data;
    node * next;
};

void voeg_vooraan_toe(int data, node ** p_node) {
    node * temp = *p_node;
    *p_node = (node *) malloc(sizeof(node));
    (*p_node)->next = temp;
    (*p_node)->data = data;
}

void print_lijst(const node * p_node) {
    while (p_node) {
        printf("%d ", p_node->data);
        p_node = p_node->next;
    }
    printf("\n");
}

void print_lijst_rec(const node * p_node) {
    if (p_node) {
        printf("%d ", p_node->data);
        print_lijst_rec(p_node->next);
    } else {
        printf("x\n");
    }
}

void free_lijst(node ** p_node) {
    node * temp_del;
    while (*p_node) {
        temp_del = *p_node;
        *p_node = temp_del->next;
        printf("Freeing %d\n", temp_del->data);
        free(temp_del);
    }
}

void free_lijst_rec(node ** p_node) {
    if (!*p_node) return;
    free_lijst_rec(&((*p_node)->next));
    printf("Freeing %d\n", (*p_node)->data);
    free(*p_node);
}

int main() {
    node * h = 0;
    voeg_vooraan_toe(7, &h);
    voeg_vooraan_toe(3, &h);
    print_lijst_rec(h);
    free_lijst_rec(&h);
    return 0;
}
