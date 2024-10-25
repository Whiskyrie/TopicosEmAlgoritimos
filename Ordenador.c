#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utilitarios.h"
#include "Ordenacao.h"

#define MAX_FILES 12

typedef struct
{
    int *numbers;
    int size;
    char filename[100];
} FileData;

int main()
{
    int option;
    FileData files[MAX_FILES] = {0}; // Inicializa estrutura para múltiplos arquivos
    int filesLoaded = 0;

    do
    {
        displayMenu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            printf("\nQuantos arquivos deseja ler (max %d)? ", MAX_FILES);
            scanf("%d", &filesLoaded);

            if (filesLoaded > MAX_FILES)
            {
                printf("Numero maximo de arquivos é %d.\n", MAX_FILES);
                filesLoaded = MAX_FILES;
            }

            for (int i = 0; i < filesLoaded; i++)
            {
                printf("\nDigite o nome do arquivo %d: ", i + 1);
                scanf("%s", files[i].filename);

                // Libera memória se já existir
                if (files[i].numbers != NULL)
                {
                    free(files[i].numbers);
                }

                files[i].numbers = readFile(files[i].filename, &files[i].size);

                if (files[i].numbers != NULL)
                {
                    printf("Arquivo %d lido com sucesso. %d numeros carregados.\n",
                           i + 1, files[i].size);
                }
                else
                {
                    printf("Erro ao ler o arquivo %d.\n", i + 1);
                    i--; // Tenta ler este arquivo novamente
                }
            }
            break;
        }

        case 2: // Bubble Sort
        case 3: // Insertion Sort
        case 4: // Shell Sort
        case 5: // Selection Sort
        case 6: // Quick Sort
        case 7: // Merge Sort
        case 8: // Heap Sort
        case 9: // Radix Sort
        {
            if (filesLoaded == 0)
            {
                printf("Nenhum arquivo foi lido ainda.\n");
                break;
            }

            printf("\nExecutando ordenacao em todos os arquivos...\n");

            // Para cada arquivo
            for (int i = 0; i < filesLoaded; i++)
            {
                printf("\nOrdenando arquivo: %s\n", files[i].filename);
                clock_t start = clock();

                switch (option)
                {
                case 2:
                    bubbleSort(files[i].numbers, files[i].size);
                    printf("Bubble Sort ");
                    break;
                case 3:
                    insertionSort(files[i].numbers, files[i].size);
                    printf("Insertion Sort ");
                    break;
                case 4:
                    shellSort(files[i].numbers, files[i].size);
                    printf("Shell Sort ");
                    break;
                case 5:
                    selectionSort(files[i].numbers, files[i].size);
                    printf("Selection Sort ");
                    break;
                case 6:
                    quickSort(files[i].numbers, 0, files[i].size - 1);
                    printf("Quick Sort ");
                    break;
                case 7:
                    mergeSort(files[i].numbers, 0, files[i].size - 1);
                    printf("Merge Sort ");
                    break;
                case 8:
                    heapSort(files[i].numbers, files[i].size);
                    printf("Heap Sort ");
                    break;
                case 9:
                    radixSort(files[i].numbers, files[i].size);
                    printf("Radix Sort ");
                    break;
                }

                clock_t end = clock();
                double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("concluido em %.6f segundos.\n", time_taken);
            }
            break;
        }

        case 10:
        {
            printf("Saindo...\n");
            break;
        }

        default:
            printf("Opcao invalida.\n");
        }

    } while (option != 10);

    // Libera memória de todos os arquivos
    for (int i = 0; i < filesLoaded; i++)
    {
        if (files[i].numbers != NULL)
        {
            free(files[i].numbers);
        }
    }

    return 0;
}