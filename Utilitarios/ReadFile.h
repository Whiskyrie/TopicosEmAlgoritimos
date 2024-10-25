#ifndef READFILE_H
#define READ_FILE_H

int *readFile(const char *filename, int *size)

{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    int *arr = NULL;
    int num, count = 0;

    while (fscanf(file, "%d", &num) != EOF)
    {
        arr = (int *)realloc(arr, (count + 1) * sizeof(int));
        arr[count] = num;
        count++;
    }

    fclose(file);
    *size = count;
    return arr;
}

#endif