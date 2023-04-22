#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Erro comum 1 */
    char c = 'A'; // char: 1 byte (8 bits)
    char *pc = &c; 

    printf("Endereço de c = %p\n", pc);
    printf("Conteúdo de c = %c\n\n", c);

    int *int_pc = (int *) pc; // int: 4 bytes (32 bits)

    printf("Endereço de c = %p\n", int_pc);
    printf("Conteúdo de int_pc = %d\n", *int_pc);

    // 1 byte = 8 bits = 10010011
    // 0 até 2^8 - 1 => 0 até 1023

    /* Erro comum 2 */
    int a = 1025653;
    int *pa = &a;

    printf("Endereço de a = %p\n", pa);
    printf("Conteúdo de a = %d\n\n", a);

    char *pc = (char *)pa;

    printf("Endereço apontado por pc = %p\n", pc);
    printf("Conteúdo do endereço apontado por pc = %d\n", *pc);
}
