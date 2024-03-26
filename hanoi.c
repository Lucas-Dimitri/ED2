#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int value;
};

typedef struct node node;

struct pilha
{
    node *top;
};

typedef struct pilha pilha;

void top(pilha *minhaPilha) { printf("o valor do topo da pilha eh: %d", minhaPilha->top->value); }

pilha *pop(pilha *minhaPilha)
{
    node *aux = minhaPilha->top;
    minhaPilha->top = minhaPilha->top->next;
    free(aux);
    return minhaPilha;
}

pilha *push(pilha *minhaPilha, int new_value)
{
    node *new = (node *)malloc(sizeof(node) * 1);
    new->value = new_value;

    if (minhaPilha->top == NULL)
    {
        minhaPilha->top = new;
        new->next = NULL;
        return minhaPilha;
    }

    new->next = minhaPilha->top;
    minhaPilha->top = new->next;
    return minhaPilha;
}

pilha *start_pilha()
{
    pilha *mPilha = (pilha *)malloc(sizeof(pilha));
    mPilha->top = NULL;
    return mPilha;
}

void desenharTorre()
{
}

int main()
{
    pilha *minhaPilha = startPilha();
}