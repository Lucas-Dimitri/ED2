#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void top(stack *myStack) { printf("The value at the top of the stack is: %d\n", myStack->top->value); }

stack *pop(stack *myStack)
{
    node *aux = myStack->top;
    myStack->top = myStack->top->next;
    free(aux);
    return myStack;
}

stack *push(stack *myStack, int newValue)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = newValue;

    if (myStack->top == NULL)
    {
        myStack->top = newNode;
        newNode->next = NULL;
        return myStack;
    }

    newNode->next = myStack->top;
    myStack->top = newNode;
    return myStack;
}

stack *startStack()
{
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->top = NULL;
    return newStack;
}
