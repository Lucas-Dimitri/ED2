#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int *vet, int esq, int dir, int valor)
{
    int meio = (dir + esq) / 2;

    if (vet[meio] == valor) return meio;
    else if (esq > dir) return -1;
    else if (vet[meio] < valor) return binary_search(vet, meio + 1, dir, valor);
    else if (vet[meio] > valor) return binary_search(vet, esq, meio - 1, valor);

    return 0; 
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
    int tam = 10, *vet = (int *) malloc(sizeof(int));
    for (int i = 0; i < tam; i++) vet[i] = i;

    printVetor(vet, tam);
    
    int posicao = binary_search(vet, 0, tam, 3);
    printf("posicao: %i\n", posicao);

}
