/**
 * Teken de twee pointerslenk, en wat er precies gebeurt in bovenstaande code.  Is l gewijzigd?
 */
typedef struct node node;

struct node {
    int value;
    node * next;
};

int main() {
    node * l = 0;
    node * k = l;
    k = (node *) malloc(sizeof(node));
}