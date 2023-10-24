#include <stdio.h>
#include <stdlib.h>

#include "node_struct.h"

struct node {
    struct node node;
    struct node* pNext;
};

struct node* init(const struct node* fnode);
struct node* add_node(struct node* elem, struct node node);
struct node* find_node(int node_id, struct node* root);
struct node* remove_node(const struct node* elem, struct node* root);
void destroy(struct node* root);
void printList(struct node* root);
void printNode(struct node* Node);

void add_node_test(struct node* root);
void remove_node_test(struct node* root, struct node* elem);