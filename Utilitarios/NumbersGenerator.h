#ifndef NUMBERSGENERATOR_H
#define NUMBERSGENERATOR_H

void NumbersGenerator(int size, const char *filename, int type)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int *numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Gerar números de acordo com o tipo
    if (type == 1)
    { // Números ordenados
        for (int i = 0; i < size; i++)
        {
            numbers[i] = i + 1;
        }
    }
    else if (type == 2)
    { // Números invertidos
        for (int i = 0; i < size; i++)
        {
            numbers[i] = size - i;
        }
    }
    else if (type == 3)
    { // Números randômicos
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            numbers[i] = rand() % 1000; // Números aleatórios entre 0 e 999
        }
    }

    // Escrevendo números no arquivo
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", numbers[i]);
    }

    fclose(file);
    free(numbers);
    printf("Arquivo '%s' gerado com sucesso.\n", filename);
}

#endif // NUMBERSGENERATOR_H