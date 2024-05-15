#include <stdio.h>
#include <time.h>

// Função para encontrar o maior elemento do array
int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Função para realizar a ordenação Radix Sort
void radixSort(int arr[], int n)
{
    int max = findMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int output[n];
        int count[10] = {0};

        // Contagem da ocorrência de cada dígito em count[]
        for (int i = 0; i < n; i++)
        {
            count[(arr[i] / exp) % 10]++;
        }

        // Atualização de count[i] para conter a posição real do dígito no output[]
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        // Construção do array de saída
        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copiar o array de saída para arr[], assim arr[] contém os números ordenados de acordo com o dígito atual
        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }
}

// Função para imprimir um array de tamanho n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Exemplo de uso
int main()
{
    int tam = 10;
    int arr[tam];

    srand(time(NULL));
    printf("Array desordenado: \n");
    for (int i = 0; i < tam; i++)
    {
        arr[i] = rand() % 10;
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}