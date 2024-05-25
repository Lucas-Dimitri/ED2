#include <stdlib.h>

typedef struct arvBinaria
{
    int info;
    int altura;
    int fb;
    struct arvBinaria *esq;
    struct arvBinaria *dir;
} arvBinaria;

int attFB(arvBinaria *arv)
{
    if(arv == NULL) return 0;

    int altDir = attFB(arv->esq);
    int altEsq = attFB(arv->dir);

    // Atualiza a altura da arvore
    arv->altura = 1 + (altEsq > altDir ? altEsq : altDir);

    // Atualiza o fb da arvore
    arv->fb = altDir - altEsq;

    return arv->altura;
}

void rebalanceamento(arvBinaria *arv)
{
    if (arv->fb == 2 )
    {
        if (arv->esq == 1) rotE(arv);
        if (arv->dir == 1) rotD(arv);
        if (arv->esq == -1) rotE(arv->esq);
        if (arv->dir == -1) rotD(arv);
    }
    
}

void rotD(arvBinaria *arv)
{
    arvBinaria *q = arv->esq, *temp = q->dir;
    q->dir = arv;
    arv->esq = temp;
    arv = q;
}

void rotE(arvBinaria *arv)
{
    arvBinaria *q = arv->dir, *temp = q->esq;
    q->esq = arv;
    arv->dir = temp;
    arv = q;
}

arvBinaria *buscaArvBinaria(arvBinaria *r, int valor)
{
    if (r == NULL)
        return NULL;
    else if (r->info < valor)
        return buscaArvBinaria(r->esq, valor);
    else if (r->info > valor)
        return buscaArvBinaria(r->dir, valor);
    else
        return r;
}

int main(void)
{
    
}