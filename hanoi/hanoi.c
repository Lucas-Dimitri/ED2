#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void desenharTorre()
{
}

int main()
{
    stack *myStack = startStack();

    push(myStack, 3);
    top(myStack);
}