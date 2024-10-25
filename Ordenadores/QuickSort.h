#ifndef QUICKSORT_H
#define QUICKSORT_H

void quickSort(int *arr, int low, int high)
{
    if (low + 10 <= high) // Usa Quick Sort apenas para subarrays maiores
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
    else // Para subarrays pequenos, usa Insertion Sort
    {
        insertionSort(arr + low, high - low + 1);
    }
}

#endif