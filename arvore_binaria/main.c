#include <stdlib.h>

typedef struct arvBinaria
{
    int info;
    int altura;
    struct arvBinaria *esq;
    struct arvBinaria *dir;
} arvBinaria;

arvBinaria *buscaArvBinaria(arvBinaria *r, int valor)
{
    if (r == NULL) return NULL;
    else if (r->info < valor) return buscaArvBinaria(r->esq, valor);
    else if (r->info > valor) return buscaArvBinaria(r->dir, valor);
    else return r;
}

int main(void)
{
    
}