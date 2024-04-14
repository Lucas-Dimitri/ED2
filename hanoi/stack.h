#ifndef PILHA_H
#define PILHA_H

typedef struct node
{
    struct node *next;
    int value;
} node;


typedef struct stack { node *top; } stack;

int top(stack *myStack);
stack *pop(stack *myStack);
stack *push(stack *myStack, int new_value);
stack *startStack();
int stackLength(stack *myStack);
void freeStack(stack *myStack);

#endif