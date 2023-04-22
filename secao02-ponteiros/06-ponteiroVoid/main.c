#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};

    void *p;
    p = a;

    printf("Endereço a[0] = %p\n", p);

    /*
    printf("Valor de a[0] = %d\n", *p); // ERRO!
    */

    printf("Valor de a[0] = %d\n", *((int *)p)); // Maneira correta

    printf("Endereço errado de a[1] = %p\n", p + 1);
    printf("Endereço correto de a[1] = %p\n", &a[1]);
}
