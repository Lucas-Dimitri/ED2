#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cliente {
    int itens;
    struct cliente *prox;
} cliente;

typedef struct fila { cliente *filaCliente; } fila;

typedef struct caixa
{
    int itens;
    fila *clientes;
    struct caixa *prox;
} caixa;

typedef struct mercado { caixa *topoFila; } mercado;

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



void escolheCaixa(mercado *meuMercado, cliente *meuCliente)
{
    int nCaixa = 0;
    caixa *auxCaixa = meuMercado->topoFila;
    while(auxCaixa != NULL)
    {
        int caixa = 0;
        if(auxCaixa->itens >= nCaixa) nCaixa = caixa;
        auxCaixa = auxCaixa->prox;
        caixa++;
    }

    auxCaixa = meuMercado->topoFila;
    for (int i = 0; i < nCaixa; i++)
    {
        auxCaixa = auxCaixa->prox;
    }

    if(auxCaixa->clientes->filaCliente == NULL)
    {
        auxCaixa->clientes->filaCliente = meuCliente;
        meuCliente->prox = NULL ;
    }
    else
    {
        cliente *aux = auxCaixa->clientes->filaCliente;
        while(aux->prox != NULL) aux = aux->prox; 
        aux->prox = meuCliente;
        meuCliente->prox = NULL;
        auxCaixa->itens = auxCaixa->itens + meuCliente->itens; 
    }
}

cliente *possivelCliente()
{
    srand(time(NULL));
    int chance = rand() % 100;
    if(chance < 10)
    {
        cliente *novoCliente = (cliente *) malloc(sizeof(cliente));
        novoCliente->itens = (rand() % 10) + 1;
        return novoCliente;
    }
    else return NULL;
}

void removeItens(mercado *meuMercado)
{
    caixa *auxCaixa = meuMercado->topoFila;
    while(auxCaixa != NULL)
    {
        auxCaixa->clientes->filaCliente->itens--;
        auxCaixa->itens--;
        if(auxCaixa->clientes->filaCliente->itens == 0)
        {
            cliente *auxCliente = auxCaixa->clientes->filaCliente;
            auxCaixa->clientes->filaCliente = auxCaixa->clientes->filaCliente->prox;
            free(auxCliente);
        }
        auxCaixa = auxCaixa->prox;
    }
}

void printMercado(mercado *meuMercado)
{
    caixa *auxCaixa = meuMercado->topoFila;
    int numCaixa = 1;
    while(auxCaixa != NULL)
    {
        printf("### Caixa %i ###\n", numCaixa);
        printf("Itens no caixa %i: %i\n", numCaixa,auxCaixa->itens);
        int numClientes = 0;
        cliente *auxCliente = auxCaixa->clientes->filaCliente;
        while(auxCliente != NULL)
        {
            numClientes++;
            auxCliente = auxCliente->prox;
        }
        printf("Clientes no caixa %i: %i\n", numCaixa, numClientes);
    }
}

void comecaMercado()
{
    int continua, quantiaCaixas;
    printf("Escolha quantos caixas tera o seu mercado: ");
    scanf("%i", &quantiaCaixas);
    printf("\n");

    mercado *meuMercado = criaMercado(quantiaCaixas);

    do
    {
        cliente *novoCliente = possivelCliente();
        if(novoCliente != NULL) escolheCaixa(meuMercado, novoCliente);
        removeItens(meuMercado);
        printMercado(meuMercado);

        printf("Digite 1 se deseja continuar a simulacao e 0 se nao deseja continuar: ");
        scanf("%i", &continua);
    } while (continua);
}

int main(void)
{
    comecaMercado();
}