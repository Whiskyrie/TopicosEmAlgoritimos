#ifndef TAD_UTILITARIOS_H
#define TAD_UTILITARIOS_H

void NumbersGenerator(int size, const char *filename, int type);

void displayMenu();

int *readFile(const char *filename, int *size);

void writeFile(const char *filename, int *arr, int size);

int partition(int *arr, int low, int high);

int medianOfThree(int *arr, int low, int high);

void swap(int *a, int *b);

void merge(int arr[], int left, int mid, int right);

void heapify(int arr[], int n, int i);

#endif // TAD_UTILITARIOS_H