#include <stdio.h>
#include <stdlib.h> 

typedef struct
{
    float vida;
    int x, y;
    int forca;
} Inimigo;

void criarInimigo(Inimigo *, float, int, int, int);

void *e_malloc(size_t);
void *e_calloc(size_t, size_t);
void *e_realloc(void *, size_t);

int main(void)
{
    int i, n = 0;
    Inimigo *inimigos = NULL;
    Inimigo inimigo;

    printf("Digite o número de inimigos que deseja alocar: ");
    scanf("%d", &n);

    inimigos = (Inimigo *)e_malloc(n * sizeof(Inimigo));

    for (i = 0; i < n; i++)
        criarInimigo(inimigos + i, i + 1.0f, i * 10, i * 10, i * 2);

    printf("========================================\n");
    printf("Exibindo inimigos alocados com malloc():\n\n");

    for (i = 0; i < n; i++)
    {
        inimigo = *(inimigos + i);

        printf("Inimigo %d:\n", i);
        printf("Posição = (%d, %d)\n", inimigo.x, inimigo.y);
        printf("Vida = %.2f\n", inimigo.vida);
        printf("Força = %d\n\n", inimigo.forca);
    }

    free(inimigos);
    inimigos = NULL;

    inimigos = (Inimigo *)e_calloc(n * 2, sizeof(Inimigo));

    for (i = 0; i < n * 2; i++)
        criarInimigo(inimigos + i, i + 2.0f, i, i, i * 2 + 5);

    printf("========================================\n");
    printf("Exibindo inimigos alocados com calloc():\n\n");

    for (i = 0; i < n * 2; i++)
    {
        inimigo = *(inimigos + i);

        printf("Inimigo %d:\n", i);
        printf("Posição = (%d, %d)\n", inimigo.x, inimigo.y);
        printf("Vida = %.2f\n", inimigo.vida);
        printf("Força = %d\n\n", inimigo.forca);
    }

    inimigos = e_realloc(inimigos, (n * 3) * sizeof(Inimigo));

    /*
    for (i = n * 2; i < n * 3; i++)
        criarInimigo(inimigos + i, i + 2.0f, i, i, i * 2 + 5);
    */
    
    printf("========================================\n");
    printf("Exibindo inimigos realocados com realloc():\n\n");

    for (i = 0; i < n * 3; i++)
    {
        inimigo = *(inimigos + i);

        printf("Inimigo %d:\n", i);
        printf("Posição = (%d, %d)\n", inimigo.x, inimigo.y);
        printf("Vida = %.2f\n", inimigo.vida);
        printf("Força = %d\n\n", inimigo.forca);
    }

    free(inimigos);
    inimigos = NULL;
}

void criarInimigo(Inimigo *inimigo, float vida, int x, int y, int forca)
{
    inimigo->vida = vida;
    inimigo->x = x;
    inimigo->y = y;
    inimigo->forca = forca;
}

void *e_malloc(size_t bytes)
{
    void *p = malloc(bytes);

    if (p == NULL)
        exit(EXIT_FAILURE);

    return p;
}

void *e_calloc(size_t n, size_t elementBytes)
{
    void *p = calloc(n, elementBytes);

    if (p == NULL)
        exit(EXIT_FAILURE);

    return p;
}

void *e_realloc(void *ptr, size_t newSize)
{
    void *p = realloc(ptr, newSize);

    if (p == NULL)
        exit(EXIT_FAILURE);

    return p;
}
