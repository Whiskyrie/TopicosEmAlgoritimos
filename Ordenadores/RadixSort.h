#ifndef RADIXSORT_H
#define RADIXSORT_H
#include "CountingSort.h"

int getMax(int arr[], int n)
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

void radixSort(int arr[], int n)
{
    if (n <= 0)
        return; // Proteção contra arrays vazios

    // Encontra o maior número para saber o número de dígitos
    int max = getMax(arr, n);

    // Faz counting sort para cada dígito
    // exp é 10^i onde i é o dígito atual
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

#endif // RADIXSORT_H
