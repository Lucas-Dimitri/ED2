#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct tree *left;
    struct tree *right;
    int value;
} node;

typedef struct tree
{
    node *raiz;
    int height;
} tree;

node *arv_node_cria(int value, tree *trL, tree *trR)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    newNode->left = trL;
    newNode->right = trR;
}

tree *arv_cria(int value, tree *trL, tree *trR)
{
    tree *newTree = (tree *)malloc(sizeof(tree));
    newTree->raiz = arv_node_cria(value, trL, trR);
    return newTree;
}

tree *arv_cria_vazia() { return NULL; }

void arv_print_pre_order(tree *myTree)
{
    if(myTree != NULL)
    {
        printf("%c ", myTree->raiz->value);
        arv_print_pre_order(myTree->raiz->left);
        arv_print_pre_order(myTree->raiz->right);
    }
    printf("\n");
}

void arv_print_order(tree *myTree)
{
    if (myTree != NULL)
    {
        arv_print_order(myTree->raiz->left);
        printf("%c ", myTree->raiz->value);
        arv_print_order(myTree->raiz->right);
    }
    printf("\n");
}

void arv_print_pos_order(tree *myTree)
{
    if (myTree != NULL)
    {
        arv_print_pos_order(myTree->raiz->left);
        arv_print_pos_order(myTree->raiz->right);
        printf("%c ", myTree->raiz->value);
    }
    printf("\n");
}

int arv_vazia(tree *arv) {
    if(arv == NULL) return 0;
    else return 1;
}

int arv_pertence(tree *arv, int num)
{
    if (arv_vazia(arv)) return 0;
    else
    {
        return arv->raiz->value == num || arv_pertence(arv->raiz->left, num) || arv_pertence(arv->raiz->right, num);
    }
}

tree *arv_libera(tree *arv)
{
    if (arv_vazia(arv))
    {
        arv_libera(arv->raiz->left);
        arv_libera(arv->raiz->right);
        free(arv->raiz);
        free(arv);
    }
    return NULL;
}

int max_2_int(int a, int b) { return (a>b) ? a : b; }

int arv_altura(tree *arv)
{
    if(arv_vazia(arv)) return -1;
    else return 1 + max2(arv_altura(arv->raiz->left), arv_altura(arv->raiz->right));
}

tree *arv_busca(tree *arv, int num)
{
    if(num == NULL) return NULL;
    else if(num > arv->raiz->value) return arv_busca(arv->raiz->left, num);
    else if(num < arv->raiz->value) return arv_busca(arv->raiz->right, num);
    else return arv;
}

tree *arv_insere(tree *arv, int num)
{
    if(arv == NULL)
    {
        arv = (tree *) malloc(sizeof(tree));
        node *arvNode = (node *) malloc(sizeof(node));
        arv->raiz = arvNode;
        arv->raiz->left = arv->raiz->right = NULL;
        arv->height = arv_altura(arv);
    }
    else if(num < arv->raiz->value) arv->raiz->left;
    else if(num > arv->raiz->value) arv->raiz->right;
    return arv;
}

tree *arv_retira(tree *arv, int num)
{
    if(arv == NULL) return NULL;
    else if(arv->raiz->value > num) arv->raiz->left = retira(arv->raiz->left);
    else if(arv->raiz->value < num) arv->raiz->right = retira(arv->raiz->right);
    else
    {
        if(arv->raiz->left == NULL && arv->raiz->right == NULL)
        {
            free(arv->raiz);
            free(arv);
            arv = NULL;
        }
        else if(arv->raiz->left == NULL)
        {
            tree *t = arv;
            arv = arv->raiz->left;
            free(t->raiz);
            free(t);
        }
        else
        {
            tree *pai = arv;
            tree* filho = arv->raiz->left;
            while(filho->raiz->right != NULL)
            {
                pai = filho;
                filho = filho->raiz->right;
            }
            arv->raiz->value = filho->raiz->value;
            filho->raiz->value = num;
            arv->raiz->left = retira(arv->raiz->left, num);
        }
    }
    return arv;
}

int main()
{
    tree *t1 = arv_cria(4, arv_cria_vazia(), arv_cria_vazia());
    tree *t2 = arv_cria(2, arv_cria_vazia(), t1);
    tree *t3 = arv_cria(5, arv_cria_vazia(), arv_cria_vazia());
    tree *t4 = arv_cria(6, arv_cria_vazia(), arv_cria_vazia());
    tree *t5 = arv_cria(3, t3, t4);
    tree *t = arv_cria(1, t2, t5);
    arv_print_pre_order(t);
    arv_print_order(t);
    arv_print_pos_order(t);
}