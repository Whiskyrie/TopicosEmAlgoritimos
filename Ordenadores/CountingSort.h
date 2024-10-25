#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

void countingSort(int arr[], int n, int exp)
{
    // Aloca dinamicamente os arrays temporários
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0}; // Array para contar dígitos de 0-9

    if (output == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return;
    }

    // Contagem de ocorrências
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Atualiza count[i] para conter a posição atual do dígito
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[]
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    // Libera a memória alocada
    free(output);
}

#endif // COUNTINGSORT_H