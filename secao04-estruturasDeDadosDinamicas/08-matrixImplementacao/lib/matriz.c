#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void mf_criar(matrizFloat *m, int linhas, int colunas)
{
    int i;

    if (linhas <= 0 || colunas <= 0)
        return;

    float *conteudo = (float *)malloc((linhas * colunas) * sizeof(float));

    if (conteudo == NULL)
        exit(EXIT_FAILURE);

    m->linhas = linhas;
    m->colunas = colunas;
    m->conteudo = conteudo;

    for (i = 0; i < (linhas * colunas); i++)
        m->conteudo[i] = 0.0f;
}

void mf_destruir(matrizFloat *m)
{
    if (m->conteudo == NULL)
        return;

    free(m->conteudo);
    m->conteudo = NULL;
}

void mf_mostrar(matrizFloat m)
{
    int i, j;

    if (m.conteudo == NULL)
    {
        printf("matriz vazia ...\n");
        return;
    }

    for (i = 0; i < m.linhas; i++)
    {
        for (j = 0; j < m.colunas; j++)
            printf("%.2f ", m.conteudo[m.linhas * i + j]);

        printf("\n");
    }

    printf("\n");
}

int mf_estaVazia(matrizFloat m)
{
    return m.conteudo == NULL;
}

int mf_validarNumeroLinhaNumeroColuna(int numLinha, int numColuna, matrizFloat m)
{
    return (numLinha >= 0 && numLinha <= m.linhas - 1) ||
           (numColuna >= 0 && numLinha <= m.colunas - 1);
}

void mf_alterarValor(int numLinha, int numColuna, float novoValor, matrizFloat *m)
{
    if (mf_estaVazia(*m))
        return;

    if (mf_validarNumeroLinhaNumeroColuna(numLinha, numColuna, *m) == 0)
        return;

    m->conteudo[m->linhas * numLinha + numColuna] = novoValor;
}

float mf_retornarValor(int numLinha, int numColuna, matrizFloat m)
{
    if (mf_estaVazia(m))
        return -1.0f;

    if (mf_validarNumeroLinhaNumeroColuna(numLinha, numColuna, m) == 0)
        return -1.0f;

    return m.conteudo[m.linhas * numLinha + numColuna];
}

void mf_criarIdentidade(int ordem, matrizFloat *m)
{
    int i, j;

    if (ordem <= 0)
        return;

    mf_criar(m, ordem, ordem);

    for (i = 0; i < m->linhas; i++)
    {
        for (j = 0; j < m->colunas; j++)
        {
            if (i == j)
                mf_alterarValor(i, j, 1.0f, m);
        }
    }
}

int mf_soma(matrizFloat *m1, matrizFloat *m2, matrizFloat *mr)
{
    int i, j;

    if (mf_estaVazia(*m1) ||
        mf_estaVazia(*m2))
        return 0;

    if (m1->linhas != m2->linhas || 
        m1->colunas != m2->colunas)
        return 0;
        
    mf_criar(mr, m1->linhas, m1->colunas);

    for (i = 0; i < mr->linhas; i++)
        for (j = 0; j < mr->colunas; j++)
            mf_alterarValor(i, j, mf_retornarValor(i, j, *m1) + mf_retornarValor(i, j, *m2), mr);
    
    return 1;
}

int mf_subtrair(matrizFloat *m1, matrizFloat *m2, matrizFloat *mr)
{
    int i, j;

    if (mf_estaVazia(*m1) ||
        mf_estaVazia(*m2))
        return 0;

    if (m1->linhas != m2->linhas || 
        m1->colunas != m2->colunas)
        return 0;

    mf_criar(mr, m1->linhas, m1->colunas);

    for (i = 0; i < mr->linhas; i++)
        for (j = 0; j < mr->colunas; j++)
            mf_alterarValor(i, j, mf_retornarValor(i, j, *m1) - mf_retornarValor(i, j, *m2), mr);
    
    return 1;
}

int mf_multiplicarPorEscalar(float n, matrizFloat *m, matrizFloat *mr)
{
    int i, j;

    if (mf_estaVazia(*m))
        return 0;

    mf_criar(mr, m->linhas, m->colunas);

    for (i = 0; i < mr->linhas; i++)
        for (j = 0; j < mr->colunas; j++)
            mf_alterarValor(i, j, n * mf_retornarValor(i, j, *m), mr);

    return 1;
}

void mf_multiplicar(matrizFloat *, matrizFloat *, matrizFloat *)
{
}
