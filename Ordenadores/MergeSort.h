#ifndef MERGESORT_H
#define MERGESORT_H

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Encontra o ponto médio
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combina as metades ordenadas
        merge(arr, left, mid, right);
    }
}

#endif // MERGESORT_H