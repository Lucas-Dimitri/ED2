#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *dir;
    struct tree *esq;
    int value;
    int height;
} tree;

tree *create_tree(int value)
{
    tree *newTree = (tree *) malloc(sizeof(tree));
    newTree->dir = NULL;
    newTree->esq = NULL;
    newTree->value = value;
}

int main(void)
{
    
}