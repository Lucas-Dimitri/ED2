#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct hanoi
{
    stack *stack1;
    stack *stack2;
    stack *stack3;
}hanoi;

hanoi *startHanoi()
{
    hanoi *tower = (hanoi *) malloc(sizeof(hanoi));

    tower->stack1 = startStack();
    tower->stack2 = startStack();
    tower->stack3 = startStack();

    push(tower->stack1, 3);
    push(tower->stack1, 2);
    push(tower->stack1, 1);

    return tower;
}

void freeHanoi(hanoi *tower)
{
    freeStack(tower->stack1);
    freeStack(tower->stack2);
    freeStack(tower->stack3);
    free(tower);
}

void printHanoi(hanoi *tower)
{
    int length1 = stackLength(tower->stack1);
    int length2 = stackLength(tower->stack2);
    int length3 = stackLength(tower->stack3);

    if (length1 == 3)
        printf("   #   ");
    else
        printf("    |    ");
    if (length2 == 3)
        printf("   #   ");
    else
        printf("    |    ");
    if (length3 == 3)
        printf("   #   ");
    else
        printf("    |    ");
    printf("\n");



    if (length1 > 1)
        printf("  ###  ");
    else
        printf("    |    ");
    if (length2 > 1)
        printf("  ###  ");
    else
        printf("    |    ");
    if (length3 > 1)
        printf("  ###  ");
    else
        printf("    |    ");
    printf("\n");



    if (length1 > 0)
        printf(" ##### ");
    else
        printf("    |    ");
    if (length2 > 0)
        printf(" ##### ");
    else
        printf("    |    ");
    if (length3 > 0)
        printf(" ##### ");
    else
        printf("    |    ");
    printf("\n");
}

int main()
{
    hanoi *tower = startHanoi();
    top(tower->stack1);

    printf("the stack lenght is: %i\n", stackLength(tower->stack1));

    printHanoi(tower);

    pop(tower->stack1);
    push(tower->stack2, 1);

    printHanoi(tower);







    free(tower);
}