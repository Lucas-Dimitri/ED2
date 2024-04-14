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
    node *aux1 = tower->stack1->top, *aux2 = tower->stack2->top, *aux3 = tower->stack3->top;

    if(aux1 == NULL || stackLength(tower->stack1) < 3) printf("       ");
    else if(stackLength(tower->stack1) == 3)
    {
        printf("   #   ");
        if(aux1 != NULL) aux1 = aux1->next;
    }
    if(aux2 == NULL|| stackLength(tower->stack2) < 3) printf("       ");
    else if(stackLength(tower->stack2) == 3)
    {
        printf("   #   ");
        if(aux2 != NULL) aux2 = aux2->next;
    }
    if(aux3 == NULL|| stackLength(tower->stack3) < 3) printf("       ");
    else if(stackLength(tower->stack3) == 3)
    {
        printf("   #   ");
        if(aux3 != NULL) aux3 = aux3->next;
    }
    printf("\n");

    if(aux1 == NULL || stackLength(tower->stack1) < 2) printf("       ");
    else if(stackLength(tower->stack1) >= 2 && aux1->value == 2)
    {
        printf("  ###  ");
        if(aux1 != NULL) aux1 = aux1->next;
    }
    else if(stackLength(tower->stack1) >= 2 && aux1->value == 1)
    {
        printf("   #   ");
        if(aux1 != NULL) aux1 = aux1->next;
    }
    if(aux2 == NULL || stackLength(tower->stack2) < 2) printf("       ");
    else if(stackLength(tower->stack2) >= 2 && aux2->value == 2)
    {
        printf("  ###  ");
        if(aux2 != NULL) aux2 = aux2->next;
    }
    else if(stackLength(tower->stack2) >= 2 && aux2->value == 1)
    {
        printf("   #   ");
        if(aux2 != NULL) aux2 = aux2->next;
    }
    if(aux3 == NULL || stackLength(tower->stack3) < 2) printf("       ");
    else if(stackLength(tower->stack3) >= 2 && aux3->value == 2)
    {
        printf("  ###  ");
        if(aux3 != NULL) aux3 = aux3->next;
    }
    else if(stackLength(tower->stack3) >= 2 && aux3->value == 1)
    {
        printf("   #   ");
        if(aux3 != NULL) aux3 = aux3->next;
    }
    printf("\n");

    if(aux1 == NULL) printf("       ");
    else if(stackLength(tower->stack1) >= 1 && aux1->value == 3) printf(" ##### ");
    else if(stackLength(tower->stack1) >= 1 && aux1->value == 2) printf("  ###  ");
    else if(stackLength(tower->stack1) >= 1 && aux1->value == 1) printf("   #   ");
    if(aux2 == NULL) printf("       ");
    else if(stackLength(tower->stack2) >= 1 && aux2->value == 3) printf(" ##### ");
    else if(stackLength(tower->stack2) >= 1 && aux2->value == 2) printf("  ###  ");
    else if(stackLength(tower->stack2) >= 1 && aux2->value == 1) printf("   #   ");
    if(aux3 == NULL) printf("       ");
    else if(stackLength(tower->stack3) >= 1 && aux3->value == 3) printf(" ##### ");
    else if(stackLength(tower->stack3) >= 1 && aux3->value == 2) printf("  ###  ");
    else if(stackLength(tower->stack3) >= 1 && aux3->value == 1) printf("   #   ");
    printf("\n");
}

void moveHanoi(hanoi *tower, int takeStack, int receiveStack)
{
    stack *aux1, *aux2;

    if (takeStack == receiveStack)
    {
        printf("Wrong move\n");
        return;
    }
    
    if(takeStack == 1)aux1 = tower->stack1;
    if(takeStack == 2)aux1 = tower->stack2;
    if(takeStack == 3)aux1 = tower->stack3;

    if(receiveStack == 1)aux2 = tower->stack1;
    if(receiveStack == 2)aux2 = tower->stack2;
    if(receiveStack == 3)aux2 = tower->stack3;
    
    if(aux1->top == NULL)
    {
        printf("Can't make that move\n");
        return;
    }
    if(aux2->top == NULL)
    {
        int valueToMove = aux1->top->value;
        pop(aux1);
        push(aux2, valueToMove);
        return;
    }
    if(aux1->top->value > aux2->top->value)
    {
        printf("Can't make that move\n");
        return;
    }
    if(aux1->top->value < aux2->top->value)
    {
        int valueToMove = aux1->top->value;
        pop(aux1);
        push(aux2, valueToMove);
        return;
    }
}

void playHanoi(hanoi *tower)
{
    printf("######### hanoi tower #########\n");
    int takeStack, receiveStack;
    printHanoi(tower);

    while(stackLength(tower->stack3) != 3)
    {
        printf("Write the number of the tower you want to remove a disk: ");
        scanf("%i", &takeStack);
        printf("Now write the number of the tower you want to put the disk: ");
        scanf("%i", &receiveStack);
        moveHanoi(tower, takeStack, receiveStack);
        printHanoi(tower);
        printf("\n");
    }

    printf("Congratulations, you won the game!\n");
}

int main()
{
    hanoi *tower = startHanoi();

    playHanoi(tower);

    free(tower);
}