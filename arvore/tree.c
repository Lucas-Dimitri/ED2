#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct tree *left;
    struct tree *right;
    char value;
} node;

typedef struct tree
{
    node *raiz;
    int height;
} tree;

node *createNode(char value, tree *trL, tree *trR)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    newNode->left = trL;
    newNode->right = trR;
}

tree *createTree(char value, tree *trL, tree *trR)
{
    tree *newTree = (tree *)malloc(sizeof(tree));
    newTree->raiz = createNode(value, trL, trR);
    return newTree;
}

tree *createEmptyTree()
{
    //node *newNode = (node *) malloc(sizeof(node));
    return NULL;
}

void printPreOrderTree(tree *myTree)
{
    if(myTree != NULL)
    {
        printf("%c ", myTree->raiz->value);
        printPreOrderTree(myTree->raiz->left);
        printPreOrderTree(myTree->raiz->right);
    }
}

void printOrderTree(tree *myTree)
{
    if (myTree != NULL)
    {
        printOrderTree(myTree->raiz->left);
        printf("%c ", myTree->raiz->value);
        printOrderTree(myTree->raiz->right);
    }
}

void printPosOrderTree(tree *myTree)
{
    if (myTree != NULL)
    {
        printPosOrderTree(myTree->raiz->left);
        printPosOrderTree(myTree->raiz->right);
        printf("%c ", myTree->raiz->value);
    }
}

int emptyTree(tree *t) { return (t == NULL); }

int main()
{
    tree *t1 = createTree('d', createEmptyTree(), createEmptyTree());
    tree *t2 = createTree('b', createEmptyTree(), t1);
    tree *t3 = createTree('e', createEmptyTree(), createEmptyTree());
    tree *t4 = createTree('f', createEmptyTree(), createEmptyTree());
    tree *t5 = createTree('c', t3, t4);
    tree *t = createTree('a', t2, t5);
    printPreOrderTree(t);
    printf("\n");
    printOrderTree(t);
    printf("\n");
    printPosOrderTree(t);
    printf("\n");
}

