#include <stdio.h>
#include <stdlib.h> // Contém malloc() e free()

#define NUM_FLOATS 20
#define STR_LENGTH 10

void *e_malloc(size_t);

int main(void)
{
    int i;

    // Alocações ESTÁTICAS:
    int n = 10;
    float f = 5.0f;
    char c[STR_LENGTH] = "123456789";
    int v[25];

    printf("\n");

    printf("n: int => %ld byte(s)\n", sizeof(n));
    printf("f: float => %ld byte(s)\n", sizeof(f));
    printf("c: char => %ld byte(s)\n", sizeof(c));
    printf("v: int[25] => %ld byte(s)\n\n", sizeof(v));

    // Alocações DINÂMICAS:
    int *pi = (int *)e_malloc(1 * sizeof(int));
    float *pf = (float *)e_malloc(NUM_FLOATS * sizeof(float));
    char *s = (char *)e_malloc(STR_LENGTH * sizeof(char));

    *pi = 25;

    for (i = 0; i < NUM_FLOATS; i++)
        pf[i] = i * 2.0f;

    for (i = 0; i < STR_LENGTH; i++)
        s[i] = c[i];

    s[STR_LENGTH] = '\0';

    printf("pi: int * => %ld byte(s)\n", sizeof(pi));
    printf("pf: float * => %ld byte(s)\n", sizeof(pf));
    printf("s: char * => %ld byte(s)\n\n", sizeof(s));

    printf("pi = %d\n\n", *pi);

    for (i = 0; i < NUM_FLOATS; i++)
        printf("pf[%d] = %f\n", i, *(pf + i));

    printf("\n");

    printf("s = %s\n", s);

    // Desalocando a memória previamente alocada
    free(pi);
    pi = NULL;

    free(pf);
    pf = NULL;

    free(s);
    s = NULL;
}

void *e_malloc(size_t bytes)
{
    void *p = malloc(bytes);

    if (p == NULL)
        exit(EXIT_FAILURE);

    return p;
}
