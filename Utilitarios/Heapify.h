#ifndef HEAPIFY_H
#define HEAPIFY_H


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compara com filho esquerdo
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Compara com filho direito
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não é a raiz
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

#endif // HEAPIFY_H