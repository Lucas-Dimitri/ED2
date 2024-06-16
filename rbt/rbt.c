/* Atividade de Red-Black*/

/* Foi incrementado nas funcoes de insert e remove um algoritmo para gravar quando um nodo eh adicionado ou removido para realizar o LOG*/
/* Funcoes exportToDOT & generateDOT sao responsaveis por gerar o arquivo DOT para a arvore red-black*/
/* Foram inseridos algoritmos adicionais nas funcoes insertFixup e deleteFixup, para atualizar o LOG quando houver rebalanceamento ou recolorimento da arvore red-black*/


/* red-black tree */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef int T; /* type of item to be stored */
#define compLT(a, b) (a < b)
#define compEQ(a, b) (a == b)

/* Red-Black tree description */
typedef enum
{
    BLACK,
    RED
} nodeColor;

typedef struct Node_
{
    struct Node_ *left;   /* left child */
    struct Node_ *right;  /* right child */
    struct Node_ *parent; /* parent */
    nodeColor color;      /* node color (BLACK, RED) */
    T data;               /* data stored in node */
} Node;

#define NIL &sentinel           /* all leafs are sentinels */
Node sentinel = { NIL, NIL, 0, BLACK, 0};

Node *root = NIL;               /* root of Red-Black tree */

void rotateLeft(Node *x)
{

    /**************************
     *  rotate node x to left *
     **************************/

    Node *y = x->right;

    /* establish x->right link */
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;

    /* establish y->parent link */
    if (y != NIL)
        y->parent = x->parent;
    if (x->parent)
    {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    else
    {
        root = y;
    }

    /* link x and y */
    y->left = x;
    if (x != NIL)
        x->parent = y;
}

void rotateRight(Node *x)
{

    /****************************
     *  rotate node x to right  *
     ****************************/

    Node *y = x->left;

    /* establish x->left link */
    x->left = y->right;
    if (y->right != NIL)
        y->right->parent = x;

    /* establish y->parent link */
    if (y != NIL)
        y->parent = x->parent;
    if (x->parent)
    {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    }
    else
    {
        root = y;
    }

    /* link x and y */
    y->right = x;
    if (x != NIL)
        x->parent = y;
}

void insertFixup(Node *x)
{

    /*************************************
     *  maintain Red-Black tree balance  *
     *  after inserting node x           *
     *************************************/

    /* check Red-Black properties */
    while (x != root && x->parent->color == RED)
    {

        FILE *file;
        file = fopen("rbt.txt", "a");
        if (file == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }
        fprintf(file, "Desbalanceamento devido ao pai de (%i) ser vermelho\n", x->data);

        /* we have a violation */
        if (x->parent == x->parent->parent->left)
        {
            Node *y = x->parent->parent->right;
            if (y->color == RED)
            {
                fprintf(file, "Trocando a cor do pai, tio e avo do nodo (%i) para rebalancear a arvore.\n", x->data);
                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else
            {
                /* uncle is BLACK */
                if (x == x->parent->right)
                {
                    fprintf(file, "Rotacionando o pai de (%i) a esquerda.\n", x->data);
                    /* make x a left child */
                    x = x->parent;
                    rotateLeft(x);
                }
                fprintf(file, "Trocando a cor do pai e do avo de (%i), e rotacionando a direita o avo.\n", x->data);
                /* recolor and rotate */
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateRight(x->parent->parent);
            }
        }
        else
        {

            /* mirror image of above code */
            Node *y = x->parent->parent->left;
            if (y->color == RED)
            {
                fprintf(file, "Trocando a cor do pai, tio e avo do nodo (%i) para rebalancear a arvore.\n", x->data);
                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else
            {
                /* uncle is BLACK */
                if (x == x->parent->left)
                {
                    fprintf(file, "Rotacionando o pai de (%i) a direita.\n", x->data);
                    x = x->parent;
                    rotateRight(x);
                }
                fprintf(file, "Trocando a cor do pai e do avo de (%i), e rotacionando a esquerda o avo.\n", x->data);
                /* recolor and rotate */
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateLeft(x->parent->parent);
            }
        }
        fclose(file);
    }
    root->color = BLACK;
}

Node *insertNode(T data)
{
    /* Salvando insercao de nodo na arvore no arquivo */
    FILE *file;
    file = fopen("rbt.txt", "a");
    if(file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fprintf(file, "Valor adicionado a arvore: %i\n", data);
    fclose(file);

    Node *current, *parent, *x;

    /***********************************************
     *  allocate node for data and insert in tree  *
     ***********************************************/

    /* find where node belongs */
    current = root;
    parent = 0;
    while (current != NIL)
    {
        if (compEQ(data, current->data))
            return (current);
        parent = current;
        current = compLT(data, current->data) ? current->left : current->right;
    }

    /* setup new node */
    if ((x = malloc(sizeof(*x))) == 0)
    {
        printf("insufficient memory (insertNode)\n");
        exit(1);
    }
    x->data = data;
    x->parent = parent;
    x->left = NIL;
    x->right = NIL;
    x->color = RED;

    /* insert node in tree */
    if (parent)
    {
        if (compLT(data, parent->data))
            parent->left = x;
        else
            parent->right = x;
    }
    else
    {
        root = x;
    }

    insertFixup(x);
    return (x);
}

void deleteFixup(Node *x)
{

    /*************************************
     *  maintain Red-Black tree balance  *
     *  after deleting node x            *
     *************************************/

    while (x != root && x->color == BLACK)
    {
        FILE *file;
        file = fopen("rbt.txt", "a");
        if (file == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }
        fprintf(file, "Desbalanceamento devido ao nodo de valor (%i) ser preto\n", x->data);

        if (x == x->parent->left)
        {
            Node *w = x->parent->right;
            if (w->color == RED)
            {
                fprintf(file, "Alterando a cor do irmao de (%i), trocando a cor do pai para vermelhor e rotacionando o pai para a esquerda.\n", x->data);
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                fprintf(file, "Se os filhos de (%i) forem pretos, deixa a sua propria cor em vermelho.\n", w->data);
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    fprintf(file, "Se o filho da direita de (%i) for preto, troca a cor do filho a esquerda para preto, a sua propria para vermelho e faz uma rotacao em si para a direita.\n", w->data);
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->right;
                }
                fprintf(file, "Deixa a cor de (%i) igual a de (%i) e muda a cor desse para preto. A cor do filho a direita de (%i) se torna preta, e rotaciona o pai de (%i) para a esquerda\n", w->data, x->parent, w->data, x->data);
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        }
        else
        {
            Node *w = x->parent->left;
            if (w->color == RED)
            {
                fprintf(file, "Alterando a cor do irmao de (%i), trocando a cor do pai para vermelho e rotacionando o pai para a direita.\n", x->data);
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                fprintf(file, "Se os filhos de (%i) forem pretos, deixa a sua propria cor em vermelho.\n", w->data);
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    fprintf(file, "Se o filho da direita de (%i) for preto, troca a cor do filho a direita para preto, a sua propria para vermelho e faz uma rotacao em si para a esquerda.\n", w->data);
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(w);
                    w = x->parent->left;
                }
                fprintf(file, "Deixa a cor de (%i) igual a de (%i) e muda a cor desse para preto. A cor do filho a esquerda de (%i) se torna preta, e rotaciona o pai de (%i) para a direita\n", w->data, x->parent, w->data, x->data);
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
        fclose(file);
    }
    x->color = BLACK;
}

void deleteNode(Node *z)
{
    /* Salvando insercao de nodo na arvore no arquivo */
    FILE *file;
    file = fopen("rbt.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fprintf(file, "Valor removido da arvore: %i\n", z->data);
    fclose(file);

    Node *x, *y;

    /*****************************
     *  delete node z from tree  *
     *****************************/

    if (!z || z == NIL)
        return;

    if (z->left == NIL || z->right == NIL)
    {
        /* y has a NIL node as a child */
        y = z;
    }
    else
    {
        /* find tree successor with a NIL node as a child */
        y = z->right;
        while (y->left != NIL)
            y = y->left;
    }

    /* x is y's only child */
    if (y->left != NIL)
        x = y->left;
    else
        x = y->right;

    /* remove y from the parent chain */
    x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;

    if (y != z)
        z->data = y->data;

    if (y->color == BLACK)
        deleteFixup(x);

    free(y);
}

Node *findNode(T data)
{

    /*******************************
     *  find node containing data  *
     *******************************/

    Node *current = root;
    while (current != NIL)
        if (compEQ(data, current->data))
            return (current);
        else
            current = compLT(data, current->data) ? current->left : current->right;
    return (0);
}

void generateDOT(Node *root, FILE *file)
{
    if (root != NIL)
    {
        if (root->left != NIL)
        {
            fprintf(file, "    %d -> %d [color=%s];\n", root->data, root->left->data, root->left->color == RED ? "red" : "black");
            generateDOT(root->left, file);
        }
        if (root->right != NIL)
        {
            fprintf(file, "    %d -> %d [color=%s];\n", root->data, root->right->data, root->right->color == RED ? "red" : "black");
            generateDOT(root->right, file);
        }
    }
}

void exportToDOT(Node *root, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(file, "digraph RedBlackTree {\n");
    fprintf(file, "    node [fontname=\"Arial\"];\n");

    if (root == NIL)
    {
        fprintf(file, "\n");
    }
    else
    {
        generateDOT(root, file);
    }

    fprintf(file, "}\n");
    fclose(file);
}

void main(int argc, char **argv)
{
    int a, maxnum, ct;
    Node *t;

    /* command-line:
     *
     *   rbt maxnum
     *
     *   rbt 2000
     *       process 2000 records
     *
     */

    maxnum = atoi(argv[1]);

    for (ct = maxnum; ct; ct--)
    {
        a = rand() % 9 + 1;
        if ((t = findNode(a)) != NULL)
        {
            deleteNode(t);
        }
        else
        {
            insertNode(a);
        }
    }
    exportToDOT(root, "rbt.dot");
}