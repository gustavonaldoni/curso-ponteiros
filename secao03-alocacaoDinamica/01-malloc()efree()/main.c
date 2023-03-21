#include <stdio.h>
#include <stdlib.h> // Contém malloc() e free()

typedef struct
{
    float area;
    int numeroQuartos;
    int anos;
} Casa;


int main(void)
{
    // Alocações ESTÁTICAS:
    int n = 10; 
    float f = 5.0f;
    char c;
    int v[25];

    printf("\n");

    printf("n: int => %ld byte(s)\n", sizeof(n));
    printf("f: float => %ld byte(s)\n", sizeof(f));
    printf("c: char => %ld byte(s)\n", sizeof(c));
    printf("v: int[25] => %ld byte(s)\n\n", sizeof(v));

    // Alocações DINÂMICAS:

}   
