#include <stdio.h>
#include <stdlib.h>

void rMax1(int *, int *, int *);
void rMin1(int *, int *, int *);
int *rMax2(int *, int *);
int *rMin2(int *, int *);
void rAumentoPercentual(int *, float, float *);
void rDescontoPercentual(int *, float, float *);
void rSwap(int *, int *);

int main(void)
{
    int a = 20, b = 10;
    
    int resultadoMax, resultadoMin;
    float resultadoAumento, resultadoDesconto; 

    printf("a = %d, b = %d\n\n", a, b);

    rMax1(&a, &b, &resultadoMax);
    rMin1(&a, &b, &resultadoMin);

    printf("rMax1(&a, &b, &resultadoMax) = %d\n", resultadoMax);
    printf("rMin1(&a, &b, &resultadoMin) = %d\n\n", resultadoMin);

    printf("rMax2(&a, &b) = %d\n", *rMax2(&a, &b));
    printf("rMin2(&a, &b) = %d\n\n", *rMin2(&a, &b));

    rAumentoPercentual(&a, 10.0f, &resultadoAumento);
    rDescontoPercentual(&a, 10.0f, &resultadoDesconto);

    printf("rAumentoPercentual(&a, 10.0f, &resultadoAumento) = %f\n", resultadoAumento);
    printf("rAumentoPercentual(&a, 10.0f, &resultadoDesconto) = %f\n\n", resultadoDesconto);

    rSwap(&a, &b);

    printf("a depois de swap = %d, b depois de swap = %d\n", a, b);
}

void rMax1(int *pa, int *pb, int *result)
{
    if (*pa > *pb)
        *result = *pa;
    else
        *result = *pb;
}

void rMin1(int *pa, int *pb, int *result)
{
    if (*pa > *pb)
        *result = *pb;
    else
        *result = *pa;
}

int *rMax2(int *pa, int *pb)
{
    int *result = NULL;

    if (*pa > *pb)
        result = pa;
    else
        result = pb;
    
    return result;
}

int *rMin2(int *pa, int *pb)
{
    int *result = NULL;

    if (*pa > *pb)
        result = pb;
    else
        result = pa;
    
    return result;
}

void rAumentoPercentual(int *valor, float percentual, float *result)
{
    *result = (float) (*valor + (*valor * percentual/100));
}

void rDescontoPercentual(int *valor, float percentual, float *result)
{
    *result = (float) (*valor - (*valor * percentual/100));
}

void rSwap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}