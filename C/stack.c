#include "stack.h"

int main() {
    struct stack stack;

    struct node *fnode = malloc(sizeof(struct node));
    fnode->id = 2;
    fnode->status = 1;

    init_st(&stack, fnode);

    stack_test(&stack);

    free(fnode);
    destroy_st(&stack);
}

void init_st(struct stack *stk, struct node *node) {
    stk->id_top = 0;
    stk->nodes[0] = init(node);
}

void push(struct stack *stk, struct node *node) {
    int flag = 1;
    if (stk->id_top == 19) {
        printf("Stek is full!");
        flag = 0;
    }
    if (flag) {
        stk->nodes[stk->id_top + 1] = add_node(stk->nodes[stk->id_top], *node);
        stk->id_top++;
    }
}

struct node pop(struct stack *stk) {
    struct node tmp = stk->nodes[stk->id_top]->node;

    remove_node(stk->nodes[stk->id_top], stk->nodes[0]);
    stk->id_top--;

    return tmp;
}

void destroy_st(struct stack *stk) { destroy(stk->nodes[0]); }

void printStack(struct stack *stk) {
    for (int i = 0; i <= stk->id_top; i++) {
        printf("i = %d\n", i);
        printf("ID of node[i] = %d\n", stk->nodes[i]->node.id);
        printf("Status of node[i] = %d\n\n", stk->nodes[i]->node.status);
    }
}