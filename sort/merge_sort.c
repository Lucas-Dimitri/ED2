#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int *left, int left_size, int *right, int right_size, int *output)
{
    // Ponteiros para percorrer os arrays
    int i = 0, j = 0, k = 0;

    // Intercala os elementos enquanto houver elementos em ambos os subarrays
    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            output[k] = left[i];
            i++;
        }
        else
        {
            output[k] = right[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de 'left', se houver
    while (i < left_size)
    {
        output[k] = left[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de 'right', se houver
    while (j < right_size)
    {
        output[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *segment, int tam)
{
    // Caso base: array com tamanho 1 ou 0 já está ordenado
    if (tam <= 1) return;

    // Calcula o índice do meio do array
    int mid = tam / 2;

    // Aloca memória para os subarrays 'left' e 'right'
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((tam - mid) * sizeof(int));

    if (left == NULL || right == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE); // Encerra o programa com erro
    }

    // Copia a primeira metade do array para 'left'
    memcpy(left, segment, mid * sizeof(int));

    // Copia a segunda metade do array para 'right'
    memcpy(right, segment + mid, (tam - mid) * sizeof(int));

    // Ordena recursivamente as duas metades
    mergeSort(left, mid);
    mergeSort(right, tam - mid);

    // Intercala as duas metades ordenadas de volta no array original
    merge(left, mid, right, tam - mid, segment);

    // Libera a memória alocada para 'left' e 'right'
    free(left);
    free(right);
}

int *criaVetor(int tam)
{
    srand(time(NULL));
    int *vetor = (int *)malloc(sizeof(int) * tam);
    for (int i = 0; i < tam; i++)
        vetor[i] = (rand() % 20) + 1;
    return vetor;
}

void printVetor(int *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main(void)
{
    int tam = 10;
    int *vetor = criaVetor(tam);

    printf("Vetor original:\n");
    printVetor(vetor, tam);

    mergeSort(vetor, tam);

    printf("Vetor ordenado:\n");
    printVetor(vetor, tam);

    free(vetor);
    return 0;
}