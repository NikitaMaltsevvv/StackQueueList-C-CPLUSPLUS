#include "stack.h"

void stack_test(struct stack *stk) {
    printf("\tDefault stack after init:\n");
    printStack(stk);

    struct node *secnode = malloc(sizeof(struct node));
    secnode->id = 5;
    secnode->status = 0;

    push(stk, secnode);

    printf("\tStack after push:\n");
    printStack(stk);

    struct node popnode = pop(stk);

    printf("\tnode after pop:\nID = %d\nStatus = %d\n", popnode.id, popnode.status);

    printf("\tStack after pop:\n");
    printStack(stk);

    free(secnode);
}