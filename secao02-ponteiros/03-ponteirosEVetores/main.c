#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

int main(void)
{
    int i;
    int vetor[MAX_ELEMENTS];

    int *pv = NULL;
    
    int x;
    
    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        vetor[i] = i;
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    pv = &vetor[0];
    printf("pv -> %p\n", pv);

    pv = vetor;
    printf("pv -> %p\n", pv);

    x = *pv;
    printf("x = %d\n", x);

    x = *(pv + 1); // x = v[1]
    printf("x = %d\n", x);

    x = *(pv + 2); // x = v[2]
    printf("x = %d\n", x);

    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        x = *(pv + i);
        printf("x = %d\n", x);
        printf("vetor[%d] = %d\n\n", i, vetor[i]);
    }
}

    

    
