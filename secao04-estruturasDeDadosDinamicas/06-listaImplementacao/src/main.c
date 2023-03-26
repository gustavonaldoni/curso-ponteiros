#include <stdio.h>
#include "lista.h"

int main()
{
    int i;

    lista l;
    l_criar(&l);

    for (i = 1; i <= 20; i++)
        l_inserir(&l, i * 10);

    l_mostrar(l);

    l_remover(&l, 30);
    l_remover(&l, 50);
    printf("\n");
    l_mostrar(l);

    l_inserir(&l, 200);
    l_inserir(&l, 200);
    l_inserir(&l, 300);
    printf("\n");
    l_mostrar(l);

    l_removerTodos(&l, 200);
    printf("\n");
    l_mostrar(l);

    l_substituir(&l, 300, 210);
    printf("\n");
    l_mostrar(l);

    l_destruir(&l);
    printf("\n");
    l_mostrar(l);
}