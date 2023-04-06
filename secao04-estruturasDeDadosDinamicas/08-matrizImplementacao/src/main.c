#include <stdio.h>
#include "matriz.h"

int main()
{
    int i, j;

    int rSoma;
    int rMultEscalar;
    int rMult;

    int rInserirLinhaM1;
    int rInserirLinhaM2;

    int rRemoverLinhaM1;
    int rRemoverLinhaM2;

    int rInserirColunaM1;
    int rInserirColunaM2;

    int rRemoverColunaM1;

    matrizFloat m1;
    matrizFloat m2;

    matrizFloat mSoma;
    matrizFloat mMultEscalar;
    matrizFloat mMult;

    mf_criar(&m1, 10, 10);
    mf_criar(&m2, 10, 1);

    printf("======== Criando m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);
    mf_mostrar(m1);

    printf("======== Criando m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);
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

    rSoma = mf_somar(&m1, &m2, &mSoma);

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

    rInserirLinhaM1 = mf_inserirLinha(&m1);
    
    printf("======== Inserindo linha em m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if(rInserirLinhaM1)
        mf_mostrar(m1);
    else
        printf("Inserção de linha inválida ...\n\n");

    rInserirColunaM1 = mf_inserirColuna(&m1);
    
    printf("======== Inserindo coluna em m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if(rInserirColunaM1)
        mf_mostrar(m1);
    else
        printf("Inserção de coluna inválida ...\n\n");

    rRemoverLinhaM1 = mf_removerLinha(&m1, 5);
    
    printf("======== Removendo linha 5 de m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if(rRemoverLinhaM1)
        mf_mostrar(m1);
    else
        printf("Remoção de linha inválida ...\n\n");

    rRemoverColunaM1 = mf_removerColuna(&m1, 3);

    printf("======== Removendo coluna 3 de m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if(rRemoverColunaM1)
        mf_mostrar(m1);
    else
        printf("Remoção de coluna inválida ...\n\n");
    
    rInserirLinhaM2 = mf_inserirLinha(&m2);

    printf("======== Inserindo linha em m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);
    
    if(rInserirLinhaM2)
        mf_mostrar(m2);
    else
        printf("Inserção de linha inválida ...\n\n");
    
    rInserirColunaM2 = mf_inserirColuna(&m2);
    
    printf("======== Inserindo coluna em m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);

    if(rInserirColunaM2)
        mf_mostrar(m2);
    else
        printf("Inserção de coluna inválida ...\n\n");
    
    rRemoverLinhaM2 = mf_removerLinha(&m2, 3);
    
    printf("======== Removendo linha 3 de m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);

    if(rRemoverLinhaM2)
        mf_mostrar(m2);
    else
        printf("Remoção de linha inválida ...\n\n");

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