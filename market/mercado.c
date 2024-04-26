#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

typedef struct mercado { caixa *topoFila; } mercado;

typedef struct caixa
{
    int itens;
    fila *clientes;
    struct caixa *prox;
} caixa;

mercado *criaMercado(int nCaixas)
{
    mercado *meuMercado = (mercado *) malloc(sizeof(mercado));
    meuMercado->topoFila = NULL;
    for(int i = 0; i < nCaixas;i++)
    {
        caixa *meuCaixa = (caixa *)malloc(sizeof(caixa));
        meuCaixa->itens = 0;
        meuCaixa->clientes = NULL;
        if(meuMercado->topoFila == NULL)
        {
            meuMercado->topoFila = meuCaixa;
            meuCaixa->prox = NULL;
        }
        else
        {
            caixa *auxCaixa = meuMercado->topoFila;
            while(auxCaixa->prox != NULL) auxCaixa = auxCaixa->prox;
            auxCaixa->prox = meuCaixa;
            meuCaixa->prox = NULL;
        }
    }
}

void possivelCliente()
{
    srand(time(NULL));
    int chance = rand() % 100;
    if(chance < 10)
    {
        cliente *novoCliente = (cliente *) malloc(sizeof(cliente));
        novoCliente->itens = (rand() % 10) + 1;
    }
}

void comecaMercado()
{
    mercado *meuMercado = criaMercado(5);
    
}

int main(void)
{

}