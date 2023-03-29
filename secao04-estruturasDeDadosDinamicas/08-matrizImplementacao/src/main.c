#include <stdio.h>
#include "matriz.h"

int main()
{
    int i, j;

    int rSoma;
    int rMultEscalar;
    int rMult;

    matrizFloat m1;
    matrizFloat m2;

    matrizFloat mSoma;
    matrizFloat mMultEscalar;
    matrizFloat mMult;

    mf_criar(&m1, 10, 10);
    mf_criar(&m2, 10, 1);

    printf("======== Criando m1 (10x10) ========\n\n");
    mf_mostrar(m1);

    printf("======== Criando m2 (10x1) ========\n\n");
    mf_mostrar(m2);

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            mf_alterarValor(i, j, 5.5f * i + j, &m1);
    
    for (i = 0; i < 10; i++)
        for (j = 0; j < 1; j++)
            mf_alterarValor(i, j, 2.3f * i + j, &m2);

    printf("======== Alterando m1 ========\n\n");
    mf_mostrar(m1);

    printf("======== Alterando m2 ========\n\n");
    mf_mostrar(m2);

    rSoma = mf_soma(&m1, &m2, &mSoma);

    printf("======== mSoma = m1 + m2 ========\n\n");

    if (rSoma) 
        mf_mostrar(mSoma);
    else
        printf("Soma inválida ...\n\n");

    rMultEscalar = mf_multiplicarPorEscalar(10.3f, &m1, &mMultEscalar);

    printf("======== mMultEscalar = 10.3f * m1 ========\n\n");

    if (rMultEscalar) 
        mf_mostrar(mMultEscalar);
    else
        printf("Multiplicação por escalar inválida ...\n\n");

    rMult = mf_multiplicar(&m1, &m2, &mMult);

    printf("======== mMult = m1 * m2 ========\n\n");

    if (rMult) 
        mf_mostrar(mMult);
    else
        printf("Multiplicação entre m1 e m2 inválida ...\n\n");
    
    mf_destruir(&m1);
    mf_mostrar(m1);

    mf_destruir(&m2);
    mf_mostrar(m2);

    if (rSoma)
    {
        mf_destruir(&mSoma);
        mf_mostrar(mSoma);
    }

    if (rMultEscalar)
    {
        mf_destruir(&mMultEscalar);
        mf_mostrar(mMultEscalar);
    }

    if (rMult)
    {
        mf_destruir(&mMult);
        mf_mostrar(mMult);
    }
}