#include <stdio.h>
#include <stdlib.h>

size_t strlen(char *);

int main(void)
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i = 0;

    int *p = a;
    int *pBase = a;

    char *s1 = "ABCDEFGIJKaaaaaa   a";

    float v[2] = {1.0f, 10.0f};
    float *pf = v;

    printf("&a[0] = %p / a[0] = %d\n", p, *p);

    // OPERAÇÃO INCREMENTO (1a forma)
    for (i = 0; i < 10; i++)
    {
        p = pBase + i;
        printf("&a[%d] = %p / a[%d] = %d\n", i, p, i, *p);
    }
    
    // OPERAÇÃO INCREMENTO (2a forma)
    /*
    for (i = 0; i < 10; i++)
        printf("&a[%d] = %p / a[%d] = %d\n", i, p + i, i, *(p+i));
    */
    
    // CUIDADO! Nunca fazer dessa forma
    /*
    for (i = 0; i < 10; i++)
    {
        p = pBase + i * sizeof(int);
        printf("&a[%d] = %p / a[%d] = %d\n", i, p, i, *p);
    }
    */
    
    printf("Tamanho de '%s' = %d", s1, (int)strlen(s1));

    // Operações INVÁLIDAS:
    /*
    p = p * 2;     
    p = p / 2;
    p = p + pBase;
    p = p + 2.0f;
    p = p + 2.0;
    p = pf;
    */
}

size_t strlen(char *s)
{
    char *p = s;

    while(*p != '\0')
        p++;
    
    return (size_t)(p - s);
}
