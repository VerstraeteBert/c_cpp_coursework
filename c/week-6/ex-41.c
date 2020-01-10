#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node node;
struct node {
    int data;
    node * next;
};

node * maak_gesorteerde_lijst_automatisch(int, int);
void print_lijst(node *);
void free_lijst(node **);
void voeg_vooraan_toe(int, node **);
void verwijder_dubbels(node *);

int main(void) {
    srand(time(NULL));
    node * h = maak_gesorteerde_lijst_automatisch(7, 30);
    print_lijst(h);
    verwijder_dubbels(h);
    print_lijst(h);
    free_lijst(&h);
    return 0;
}

void voeg_vooraan_toe(int data, node ** p_node) {
    node * temp = *p_node;
    *p_node = (node *) malloc(sizeof(node));
    (*p_node)->next = temp;
    (*p_node)->data = data;
}

void free_lijst(node ** h) {
    node * temp;
    while (*h) {
        temp = *h;
        *h = (*h)->next;
        printf("Freeing %d\n", temp->data);
    }
}

void print_lijst(node * h) {
    while(h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

node * maak_gesorteerde_lijst_automatisch(int aantal, int boven) {
    node * head = NULL;
    size_t i;
    int curr_num = boven;
    for (i = 0; i < aantal; i++) {
        curr_num -= rand() % 3;
        printf("adding: %d\n",curr_num);
        voeg_vooraan_toe(curr_num, &(head));
    }
    return head;
}

void verwijder_dubbels(node * p_node) {
    while (p_node) {
        while (p_node->next && p_node->next->data == p_node->data) {
            node * temp = p_node->next;
            p_node->next = temp->next;
            free(temp);
        }
        p_node = p_node->next;
    }
}
