#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utilitarios.h"
#include "Ordenacao.h"

int main()
{
    int size, type;
    char filename[100];
    char continuar;

    do
    {
        // Menu para o usuário
        printf("\n=== Gerador de Numeros ===\n");
        printf("Digite o tamanho da sequencia: ");
        scanf("%d", &size);

        printf("\nEscolha o tipo de sequencia:\n");
        printf("1 - Numeros ordenados (1 ate n)\n");
        printf("2 - Numeros invertidos (n ate 1)\n");
        printf("3 - Numeros aleatorios\n");
        printf("Digite sua escolha: ");
        scanf("%d", &type);

        printf("\nDigite o nome do arquivo de saida: ");
        scanf("%s", filename);

        // Validação das entradas
        if (size <= 0)
        {
            printf("Erro: O tamanho deve ser maior que zero.\n");
            continue; // Volta ao início do loop
        }

        if (type < 1 || type > 3)
        {
            printf("Erro: Tipo invalido. Escolha entre 1 e 3.\n");
            continue; // Volta ao início do loop
        }

        // Chama a função para gerar os numeros
        NumbersGenerator(size, filename, type);

        // Limpa o buffer do teclado
        while (getchar() != '\n')
            ;

        // Pergunta se deseja continuar
        printf("\nDeseja gerar outro arquivo? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    printf("\nPrograma finalizado.\n");
    return 0;
}