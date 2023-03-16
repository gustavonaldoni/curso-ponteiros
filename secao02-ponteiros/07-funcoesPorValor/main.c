#include <stdio.h>

int max(int, int);
int min(int, int);
float aumentoPercentual(int, float);
float descontoPercentual(int, float);
void swap(int, int);

int main(void)
{
    int a = 20, b = 10;

    printf("a = %d, b = %d\n", a, b);

    printf("max(a,b) = %d\n", max(a,b));
    printf("min(a,b) = %d\n", min(a,b));
    printf("aumentoPercentual(b, 10) = %f\n", aumentoPercentual(b, 10.0));
    printf("descontoPercentual(b, 10) = %f\n\n", descontoPercentual(b, 10.0));

    swap(a, b);

    printf("a depois de swap = %d, b depois de swap = %d\n", a, b);

}

int max(int a, int b)
{
    if (a > b)
        return a;
    
    return b;
}

int min(int a, int b)
{
    if (a > b)
        return b;
    
    return a;
}

float aumentoPercentual(int valor, float percentual)
{
    return (float) (valor + (valor * percentual/100));
}

float descontoPercentual(int valor, float percentual)
{
    return (float) (valor - (valor * percentual/100));
}

void swap(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}