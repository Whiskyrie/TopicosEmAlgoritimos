#ifndef MEDIANOFTHREE_H
#define MEDIANOFTHREE_H
#include "Swap.h"

int medianOfThree(int *arr, int low, int high)
{
    int mid = (low + high) / 2;

    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);

    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);

    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    swap(&arr[mid], &arr[high - 1]);
    return arr[high - 1];
}

#endif // MEDIANOFTHREE_H