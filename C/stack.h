#include "list.h"

struct stack {
    int id_top;
    struct node *nodes[20];
};

void init_st(struct stack *stk, struct node *node);
void push(struct stack *stk, struct node *node);
struct node pop(struct stack *stk);
void destroy_st(struct stack *stk);

void printStack(struct stack *stk);
void stack_test(struct stack *stk);
