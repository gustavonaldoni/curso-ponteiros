#include <stdio.h>
#include <stdlib.h>

// Site oficial valgrind:
// https://valgrind.org/ -> LINUX

// 100 bytes (25 inteiros)
// 20 bytes não desalocados
// malloc() e free()

// Instalação:
// sudo apt install valgrind

#define MAXIMO 100

int main(void)
{
    /* Código sem leaks:
    int x = 10;

    printf("x = %d\n", x);
    printf("&x = %p\n\n", &x);
    */

    /* Código COM leaks:
    // Exemplo 1
    int i;

    for (i = 0; i < MAXIMO; i++)
    {
        int *bloco = (int *) malloc(sizeof(int));
        *bloco = 100;
    }
    */

    /* Código SEM leaks:
    // Correção do exemplo 1
    int i;

    for (i = 0; i < MAXIMO; i++)
    {
        int *bloco = (int *) malloc(sizeof(int));
        *bloco = 100;

        free(bloco);
        bloco = NULL;
    }
    */

    /* Código COM leaks:
    // Exemplo 2
    FILE *arquivo = fopen("arquivo.txt", "a");
    int numero = 33;

    fprintf(arquivo, "%d\n", numero);
    */

    /* Código SEM leaks:
    // Correção do exemplo 2
    FILE *arquivo = fopen("arquivo.txt", "a");
    int numero = 33;

    fprintf(arquivo, "%d\n", numero);

    fclose(arquivo);
    */

    /* Código com acesso ilegal de memória:
    int i;
    int *bloco = (int *) malloc(MAXIMO * sizeof(int));

    for (i = 0; i < MAXIMO + 1; i++)
    {
        bloco[i] = i * 10;
    }

    free(bloco);
    bloco = NULL;
    */

    /* Código sem acesso ilegal de memória:
    int i;
    int *bloco = (int *) malloc(MAXIMO * sizeof(int));

    for (i = 0; i < MAXIMO; i++)
    {
        bloco[i] = i * 10;
    }

    free(bloco);
    bloco = NULL;
    */
}
