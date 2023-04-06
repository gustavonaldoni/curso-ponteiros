#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int mf_criar(matrizFloat *m, int linhas, int colunas)
{
    int i;

    if (linhas <= 0 || colunas <= 0)
        return 0;

    float *conteudo = (float *)malloc((linhas * colunas) * sizeof(float));

    if (conteudo == NULL)
        exit(EXIT_FAILURE);

    m->linhas = linhas;
    m->colunas = colunas;
    m->conteudo = conteudo;

    for (i = 0; i < (linhas * colunas); i++)
        m->conteudo[i] = 0.0f;

    return 1;
}

int mf_destruir(matrizFloat *m)
{
    if (m->conteudo == NULL)
        return 0;

    free(m->conteudo);
    m->conteudo = NULL;

    return 1;
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
            printf("%.2f ", m.conteudo[m.colunas * i + j]);

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

    m->conteudo[m->colunas * numLinha + numColuna] = novoValor;
}

float mf_retornarValor(int numLinha, int numColuna, matrizFloat m)
{
    if (mf_estaVazia(m))
        return -1.0f;

    if (mf_validarNumeroLinhaNumeroColuna(numLinha, numColuna, m) == 0)
        return -1.0f;

    return m.conteudo[m.colunas * numLinha + numColuna];
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

int mf_somar(matrizFloat *m1, matrizFloat *m2, matrizFloat *mr)
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

int mf_multiplicar(matrizFloat *m1, matrizFloat *m2, matrizFloat *mr)
{
    int i, j, aux;
    float r;

    if (m1->colunas != m2->linhas)
        return 0;

    mf_criar(mr, m1->linhas, m2->colunas);

    for (i = 0; i < mr->linhas; i++)
    {
        for (j = 0; j < mr->colunas; j++)
        {
            r = 0.0f;

            for (aux = 0; aux < m1->linhas; aux++)
                r += mf_retornarValor(i, aux, *m1) * mf_retornarValor(aux, j, *m2);

            mf_alterarValor(i, j, r, mr);
        }
    }

    return 1;
}

int mf_inserirLinha(matrizFloat *m)
{
    int i;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (mf_estaVazia(*m))
        return 0;

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas + 1) * (m->colunas));
    aux = (float *)malloc(tamanho * sizeof(float));

    for (i = 0; i < m->linhas * m->colunas; i++)
        aux[i] = copia[i];

    for (i = m->linhas * m->colunas; i < tamanho; i++)
        aux[i] = 0.0f;

    m->linhas += 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}

int mf_inserirColuna(matrizFloat *m)
{
    int i, j;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (mf_estaVazia(*m))
        return 0;

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas) * (m->colunas + 1));
    aux = (float *)malloc(tamanho * sizeof(float));

    for (i = 0; i < m->linhas; i++)
    {
        for (j = 0; j < m->colunas + 1; j++)
        {
            if (j == m->colunas)
                aux[(m->colunas + 1) * i + j] = 0.0f;
            else
                aux[(m->colunas + 1) * i + j] = copia[m->colunas * i + j];
        }
    }

    m->colunas += 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}

int mf_removerLinha(matrizFloat *m, int numLinha)
{
    int i, j;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (numLinha < 0 ||
        numLinha >= m->linhas)
        return 0;

    if (mf_estaVazia(*m))
        return 0;

    if (m->linhas == 1)
    {
        free(m->conteudo);
        m->conteudo = NULL;
        return 1;
    }

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas - 1) * (m->colunas));
    aux = (float *)malloc(tamanho * sizeof(float));

    for (i = 0; i < m->linhas; i++)
        for (j = 0; j < m->colunas; j++)
            if (i != numLinha)
            {
                if (i < numLinha)
                    aux[m->colunas * i + j] = copia[m->colunas * i + j];
                else if (i > numLinha)
                    aux[m->colunas * (i - 1) + j] = copia[m->colunas * i + j];
            }

    m->linhas -= 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}


int mf_removerColuna(matrizFloat *m, int numColuna)
{
    int i, j, k;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (numColuna < 0 ||
        numColuna >= m->colunas)
        return 0;

    if (mf_estaVazia(*m))
        return 0;

    if (m->colunas == 1)
    {
        free(m->conteudo);
        m->conteudo = NULL;
        return 1;
    }

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas) * (m->colunas - 1));
    aux = (float *)malloc(tamanho * sizeof(float));

    k = 0;
    for (i = 0; i < m->linhas; i++)
        for (j = 0; j < m->colunas; j++)
            if (j != numColuna)
            {
                aux[k] = copia[m->colunas * i + j];  
                k++;
            }
                
    m->colunas -= 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}