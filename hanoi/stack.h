#ifndef PILHA_H
#define PILHA_H

typedef struct node
{
    struct node *next;
    int value;
} node;


typedef struct stack { node *top; } stack;

void top(stack *myStack);
stack *pop(stack *myStack);
stack *push(stack *myStack, int new_value);
stack *startStack();

#endif