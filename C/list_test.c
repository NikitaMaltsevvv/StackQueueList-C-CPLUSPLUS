#include "list.h"

void add_node_test(struct node* root) {
    printf("\tADD node TEST\n");

    struct node* secnode = malloc(sizeof(struct node));
    secnode->id = 2;
    secnode->status = 1;

    struct node* secnode = add_node(root, *secnode);

    struct node* thrnode = malloc(sizeof(struct node));
    thrnode->id = 3;
    thrnode->status = 0;

    add_node(secnode, *thrnode);

    printList(root);
    free(secnode);
    free(thrnode);
}

void remove_node_test(struct node* root, struct node* elem) {
    printf("\tREMOVE node TEST\n");

    remove_node(elem, root);

    printList(root);
}
