#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int *vetor, int tam) // função para ordenação de um vetor dinâmico utilizando o shell sort
{
    int i, j, aux, h = tam / 2;

    while (h > 0)
    {
        i = h;
        while(i < tam)
        {
            aux = vetor[i];
            j = i;
            while (j >= h && aux < vetor[j - h])
            {
                vetor[j] = vetor[j - h];
                j -= h;
                vetor[j] = aux;
            }
            i++;
        }
        h = h/2;
    }
}

int main(void)
{
    srand(time(NULL));
    int tam = 7, *vetor;

    vetor = (int *) malloc(sizeof(int) * tam);

    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 10;
    }

    printf("Vetor desordenado: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");

    shellSort(vetor, tam);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}