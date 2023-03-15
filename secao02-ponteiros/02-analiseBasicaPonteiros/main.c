#include <stdio.h>

int main(void)
{
    int a1 = 10, a2 = 110;

    int *p1 = &a1, *p2 = &a2;

    printf("Vamos aprender sobre ponteiros!\n\n");

    printf("valor = %d, endereco = %p\n", a1, p1);
    printf("valor = %d, endereco = %p\n\n", a2, p2);

    *p1 += 20; // equivalente a1 += 20
    *p2 *= 500; // equivalente a2 = 500

    printf("valor = %d, endereco = %p\n", a1, p1);
    printf("valor = %d, endereco = %p\n\n", a2, p2);

    *p1 = 0;

    printf("valor = %d, endereco = %p\n", a1, p1);

    p1 = p2;

    printf("valor = %d, endereco = %p\n", a1, p1);
}