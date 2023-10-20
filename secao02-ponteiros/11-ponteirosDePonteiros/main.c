#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void swapPointers(int **, int **);
void r_alloc(int **, int);

int main(void)
{
    int i;

    // Exemplo 01
    int n1 = 100;
    int n2 = 200;

    int *p1 = &n1;
    int *p2 = &n2;

    printf("*p1 = %d\n", *p1);
    printf("p1 = %p\n\n", p1);

    printf("*p2 = %d\n", *p2);
    printf("p2 = %p\n\n", p2);

    printf("======= Trocando p1 e p2 =======\n");

    swapPointers(&p1, &p2);

    printf("*p1 = %d\n", *p1);
    printf("p1 = %p\n\n", p1);

    printf("*p2 = %d\n", *p2);
    printf("p2 = %p\n\n", p2);

    // Exemplo 02
    printf("======= Alocando memória por ponteiros duplos =======\n");

    int *r1 = NULL, *r2 = NULL;

    r_alloc(&r1, 20);
    r_alloc(&r2, -10);

    printf("*r1 = %d\n", *r1);
    printf("r1 = %p\n\n", r1);

    printf("*r2 = %d\n", *r2);
    printf("r2 = %p\n\n", r2);

    // Exemplo 02
    printf("======= Alocando matriz de inteiros =======\n");

    int *linha1 = (int *) malloc(3 * sizeof(int)),
        *linha2 = (int *) malloc(3 * sizeof(int)),
        *linha3 = (int *) malloc(3 * sizeof(int));

    for (i = 0; i < 3; i++)
    {
        linha1[i] = i;
        linha2[i] = 2*i;
        linha3[i] = 3*i;
    }

    int **m = malloc(3 * sizeof(linha1));

    m[0] = linha1;
    m[1] = linha2;
    m[2] = linha3;

    for (i = 0; i< 3; i++)
        printf("%d %d %d\n", m[i][0], m[i][1], m[i][2]);
}

void swapPointers(int **p1, int **p2)
{
    int *temp = *p1;

    *p1 = *p2;
    *p2 = temp;
}

void r_alloc(int **p, int quantidade)
{
    quantidade = abs(quantidade);
    *p = (int *)malloc(quantidade * sizeof(int));
}