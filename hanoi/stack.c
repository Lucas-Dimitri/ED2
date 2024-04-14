#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int top(stack *myStack) { return myStack->top->value; }

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

void freeStack(stack *myStack)
{
    node *current = myStack->top;
    node *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(myStack);
}

int stackLength(stack *myStack)
{
    node *aux = myStack->top;
    int i = 0;
    while(aux != NULL)
    {
        i++;
        aux = aux->next;
    }
    return i;
}