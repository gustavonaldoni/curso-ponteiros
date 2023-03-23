#include <stdio.h>
#include "fila.h"

int main()
{
    int i;

    fila f;
    f_criar(&f);

    for (i = 1; i <= 4; i++)
        f_enfileirar(&f, i * 10);

    f_mostrar(f);

    printf("\n");
    printf("tamanho fila = %d\n", f_tamanho(f));
    f_desenfileirar(&f);
    f_mostrar(f);

    printf("\n");
    printf("tamanho fila = %d\n", f_tamanho(f));
    f_desenfileirar(&f);
    f_mostrar(f);

    printf("\n");
    printf("tamanho fila = %d\n", f_tamanho(f));
    f_desenfileirar(&f);
    f_mostrar(f);

    printf("\n");
    printf("tamanho fila = %d\n", f_tamanho(f));
    f_desenfileirar(&f);
    f_mostrar(f);

    for (i = 1; i <= 20; i++)
        f_enfileirar(&f, i * 10);

    f_mostrar(f);

    printf("\n");
    printf("tamanho fila = %d\n", f_tamanho(f));

    printf("\n");
    f_destruir(&f);
    f_mostrar(f);
}