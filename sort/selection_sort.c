#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selectionSort(int *vet, int tam)
{
    int smallestIndex, smallestValue, operations = 0;

    // Outer loop: Iterate through the array from the first element to the second-to-last
    for (int i = 0; i < tam - 1; i++)
    {

        // Initialize variables to track the smallest value and its index in the unsorted portion
        smallestValue = vet[i];
        smallestIndex = i;

        // Inner loop: Find the smallest element in the unsorted portion (from i+1 onwards)
        for (int j = i + 1; j < tam; j++)
        {
            // If a smaller element is found, update smallestValue and smallestIndex
            if (smallestValue > vet[j])
            {
                smallestValue = vet[j];
                smallestIndex = j;
            }

            // Increment the operation counter for each comparison
            operations++;
        }

        // Swap the smallest element with the element at the current position (i)
        vet[smallestIndex] = vet[i];
        vet[i] = smallestValue;

        // Increment the operation counter for the swap
        operations++;
    }

    // Return the total number of operations performed
    return operations;
}

void printVetor(int *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++) printf("%d ", vet[i]);
    printf("\n");
}

int *criaVetor(int tam)
{
    srand(time(NULL));
    int *vetor = (int *)malloc(sizeof(int) * tam);
    for (int i = 0; i < tam; i++) vetor[i] = (rand() % 20) + 1;
    return vetor;
}

int main(void)
{
    int tam = 10;
    int *vetor = criaVetor(tam);

    printVetor(vetor, tam);
    selectionSort(vetor, tam);
    printVetor(vetor, tam);

    free(vetor);
    return 0;
}

// Se tu viu o meu código eu não pedi pro chatGPT, gemini ou qualquer outra IA fazer, mas eu pedi para o gemini comentar ele :)