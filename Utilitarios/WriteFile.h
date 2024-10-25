#ifndef WRITEFILE_h
#define WRITEFILE_h

void writeFile(const char *filename, int *arr, int size)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

#endif // WRITEFILE_h
