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

//node * merge(node ** a, node ** b){
//    node * dest_list;
//    node * i = *a;
//    node * j = *b;
//    node * dest_node;
//
//    if (*a == NULL) {
//        dest_list = *b;
//        return dest_list;
//    }
//    if (*b == NULL) {
//        dest_list = *a;
//        return dest_list;
//    }
//
//    if (&(*a) == &(*b)) {
//        dest_list = *a;
//        return dest_list;
//    }
//
//    if ((*a)->value < (*b)->value) {
//        dest_node = *a;
//        i = (*a)->next;
//
//    } else {
//        dest_node = *b;
//        j = (*b)->next;
//    }
//
//    dest_list = dest_node;
//
//    while(i != 0 && j != 0){
//        if(i->value < j->value){
//            dest_node->next = i;
//            i = i->next;
//        }
//        else{
//            dest_node->next = j;
//            j = j->next;
//        }
//        dest_node = dest_node->next;
//    }
//
//    while(i != 0){
//        dest_node->next = i;
//        dest_node = dest_node->next;
//        i = i->next;
//    }
//    while(j != 0){
//        dest_node->next = j;
//        dest_node = dest_node->next;
//        j = j->next;
//    }
////    *a = 0;
////    *b = 0;
//    return dest_list;
//}

void move_node(node** dest, node *** src)
{
    node * temp = **src;
    assert(temp != 0);
    **src = (**src)->next;
    temp->next = NULL;
    (*dest)->next = temp;
}

node * merge_sorted_lists(node** a, node** b) {
    assert(&(*a) != &(*b));
    assert(a && b);

    node dummy;
    node * tail = &dummy;

    while(*a != 0 && *b != 0) {
        if ((*a)->value < (*b)->value) {
            move_node(&tail, &a);
        } else {
            move_node(&tail, &b);
        }
        tail = tail->next;
    }

    if (*a != 0) {
        tail->next = *a;
        *a = 0;
    }

    if (*b != 0) {
        tail->next = *b;
        *b = 0;
    }

    return dummy.next;
}

int main(){
    srand(time(NULL));
    node * m = create_list(10,1000);
    node * n = create_list(5,1000);
    printf("\nLIJST m:\n"); print_list(m);
    printf("\nLIJST n:\n"); print_list(n);
    printf("\nDeze worden gemerged. \n\n");
    node * res = merge_sorted_lists(&n, &m);
    printf("\nLIJST m: \n"); print_list(m);
    printf("\nLIJST n: \n"); print_list(n);
    printf("\nRESULTAAT: \n"); print_list(res);

    free_list(&res);

    return 0;
}
