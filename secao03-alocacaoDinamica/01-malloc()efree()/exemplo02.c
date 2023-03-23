#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInt(int, int);

typedef struct
{
    int area;
    int numeroQuartos;
    int anos;
} Casa;

Casa *criarCasa(int, int, int);

int main(void)
{
    srand(time(NULL));

    int i;
    int numeroCasas = 0;

    Casa *arrayCasas = NULL;
    Casa *casaAleatoria = NULL;

    printf("Digite o número de casas que deseja gerar: ");
    scanf("%d", &numeroCasas);

    arrayCasas = (Casa *)malloc(numeroCasas * sizeof(Casa));

    for (i = 0; i < numeroCasas; i++)
    {
        casaAleatoria = criarCasa(randomInt(150, 300),
                                  randomInt(1, 10),
                                  randomInt(1, 30));

        arrayCasas[i] = *casaAleatoria;

        free(casaAleatoria);
    }

    printf("\n");

    for (i = 0; i < numeroCasas; i++)
    {
        printf("====== CASA %d ======\n\n", i + 1);

        printf("Área (m2) = %d\n", arrayCasas[i].area);
        printf("Número de quartos = %d\n", arrayCasas[i].numeroQuartos);
        printf("Anos desde a construção = %d\n\n", arrayCasas[i].anos);
    }

    free(arrayCasas);
}

int randomInt(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

Casa *criarCasa(int area, int numeroQuartos, int anos)
{
    Casa *casa = NULL;
    casa = (Casa *)malloc(sizeof(Casa));

    if (casa == NULL)
        exit(1);

    casa->area = area;
    casa->numeroQuartos = numeroQuartos;
    casa->anos = anos;

    return casa;
}
