#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubbleSort(int *vet, int tam)
{
    int aux, operations = 0;
    for (int i = 0; i < tam; i++)
    {
        int changes = 0;
        for (int j = 1; j < tam - i; j++)
        {
            if (vet[j] < vet[j - 1])
            {
                aux = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = aux;
                changes++;
                operations++;
            }
            operations++;
        }
        if (changes == 0)
            return operations;
    }
    return operations;
}

void printVetor(int *vet, int tam, int operacoes)
{
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
    if (operacoes > 0)
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
    int tam = 10;
    int *vetor = criaVetor(tam);

    printVetor(vetor, tam, 0);
    int operacoes = bubbleSort(vetor, tam);
    printVetor(vetor, tam, operacoes);

    free(vetor);
}