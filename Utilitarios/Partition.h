#ifndef PARTITION_H
#define PARTITION_H
#include "Swap.h"
#include "MedianOfThree.h"

int partition(int *arr, int low, int high)
{
    int pivot = medianOfThree(arr, low, high);
    int i = low;
    int j = high - 1;

    while (1)
    {
        while (arr[++i] < pivot)
            ; // Encontra o maior que o pivô
        while (arr[--j] > pivot)
            ; // Encontra o menor que o pivô

        if (i >= j)
            break;
        swap(&arr[i], &arr[j]);
    }

    swap(&arr[i], &arr[high - 1]); // Coloca o pivô em sua posição correta
    return i;
}

#endif // PARTITION_H