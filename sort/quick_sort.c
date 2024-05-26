#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *particao(int *vet, int low, int high, int operacoes)
{
    int *ret = (int *) malloc(sizeof(int) * 2);
    int pivo = vet[low];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do { i++; } while (vet[i] < pivo);
        operacoes++;
        do { j--; } while (vet[j] > pivo);
        operacoes++;

        if (i >= j)
        {
            operacoes++;
            ret[0] = j;
            ret[1] = operacoes;
            return ret;
        }


        troca(&vet[i], &vet[j]);
        operacoes++;
    }

}

int quickSort(int *vet, int low, int high, int operacoes)
{
    if (low < high)
    {
        int *ret = particao(vet, low, high, operacoes);
        int pivo = ret[0];
        operacoes = ret[1];

        operacoes = quickSort(vet, low, pivo, operacoes);
        operacoes = quickSort(vet, pivo + 1, high, operacoes);
    }
    return operacoes;
}

void printVetor(int *vet, int tam, int operacoes)
{
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
    printf("Houve %i operacoes em um vetor de tamanho %i\n", operacoes, tam);
}

int *criaVetor(int tam)
{
    srand(time(NULL));
    int *vetor = (int *)malloc(sizeof(int) * tam);
    for (int i = 0; i < tam; i++)
        vetor[i] = (rand() % 20) + 1;
    return vetor;
}

int main(void)
{
    int tam = 60;
    int *vetor = criaVetor(tam);

    printVetor(vetor, tam, 0);
    int operacoes = quickSort(vetor, 0, tam - 1, 0);
    printVetor(vetor, tam, operacoes);
    

    free(vetor);
    return 0;
}