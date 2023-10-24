#include "list.h"

#ifndef STACK
int main() {
    struct node* fnode = malloc(sizeof(struct node));
    fnode->id = 1;
    fnode->status = 0;

    struct node* fnode = init(fnode);
    printList(fnode);

#ifdef TESTS
    add_node_test(fnode);
    remove_node_test(fnode, fnode->pNext);
#endif

    printf("node with ID 1: %p", &(*(find_node(1, fnode))));

    destroy(fnode);
    free(fnode);
}
#endif

struct node* remove_node(const struct node* elem, struct node* root) {
    int flag = 1;
    struct node* result = NULL;
    if (root == NULL || elem == NULL) {
        flag = 0;
    }

    if (flag) {
        struct node* tmp = root;
        struct node* tmp_pred = root;

        while (tmp != elem) {
            tmp_pred = tmp;
            tmp = tmp->pNext;
        }
        tmp_pred->pNext = tmp->pNext;
        result = tmp->pNext;

        free(tmp);
    }

    return result;
}

struct node* add_node(struct node* elem, struct node node) {
    struct node* tmp = elem->pNext;
    struct node* new_node = malloc(sizeof(struct node));

    new_node->node = node;

    new_node->pNext = tmp;
    elem->pNext = new_node;

    return new_node;
}

struct node* init(const struct node* fnode) {
    struct node* fnode = malloc(sizeof(struct node));
    fnode->node = *fnode;
    fnode->pNext = NULL;

    return fnode;
}

void printList(struct node* root) {
    struct node* tmp = root;
    while (tmp) {
        printNode(tmp);
        tmp = tmp->pNext;
    }
}

void printNode(struct node* Node) {
    printf("%p - address of this node\n", Node);
    printf("%d - ID of node\n", Node->node.id);
    printf("%d - Status of node\n", Node->node.status);
    printf("%p - address of next node\n\n", Node->pNext);
}

struct node* find_node(int node_id, struct node* root) {
    struct node* tmp = root;
    struct node* result = NULL;
    while (tmp->pNext != NULL) {
        if (tmp->node.id == node_id) result = tmp;
        tmp = tmp->pNext;
    }

    return result;
}

void destroy(struct node* root) {
    struct node* tmp1 = root;
    struct node* tmp2 = root;
    while (tmp1) {
        free(tmp2);

        tmp1 = tmp1->pNext;
        tmp2 = tmp1;
    }
}