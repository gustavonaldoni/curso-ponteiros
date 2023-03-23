#include <stdio.h>
#include "pilha.h"

int main()
{
    pilha p;
    p_criar(&p);

    p_insere(&p, 20);
    p_insere(&p, 10);
    p_insere(&p, 0);

    printf("Tamanho de p em bytes = %ld\n", p_tamanhoBytes(p));

    p_mostrar(p);

    p_remove(&p);
    p_remove(&p);
    p_remove(&p);

    printf("Tamanho de p em bytes = %ld\n", p_tamanhoBytes(p));

    p_mostrar(p);

    p_insere(&p, 20);
    p_insere(&p, 10);
    p_insere(&p, 0);
    p_insere(&p, -1);
    p_insere(&p, -10);

    printf("Tamanho de p em bytes = %ld\n", p_tamanhoBytes(p));

    p_mostrar(p);

    p_destruir(&p);

    p_mostrar(p);

    printf("Tamanho de p em bytes = %ld\n", p_tamanhoBytes(p));
}