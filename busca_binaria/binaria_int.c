#include <stdio.h>
#include <stdlib.h>

int binaria(int vet[], int esq, int dir, int valor)
{
    if(esq == dir)
    {
        if(vet[esq] == valor) return esq;
        else return -1;
    }
    int meio = ((esq + dir) / 2);

    if(vet[meio] == valor) return meio;
    if(vet[meio] > valor) return binaria(vet, esq, meio - 1, valor);
    if(vet[meio] < valor) return binaria(vet, meio + 1, dir, valor);

}

int main()
{
    int vetor[10] = {1,2,3,4,7,9,23,55,66,89};

    int index = binaria(vetor, 0, 9, 1);

    printf("%i\n", index);
}