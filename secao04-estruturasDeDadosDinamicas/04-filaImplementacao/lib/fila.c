#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void f_criar(fila *f)
{
    f->primeiro = NULL;
    f->ultimo = NULL;
}

void f_destruir(fila *f)
{
    int i;
    int tamanhoFila = f_tamanho(*f);

    for (i = 0; i < tamanhoFila; i++)
        f_desenfileirar(f);
}

int f_estaVazia(fila f)
{
    return f.primeiro == NULL &&
           f.ultimo == NULL;
}

int f_primeiro(fila f)
{
    if (f_estaVazia(f))
        return -1;

    return f.primeiro->dado;
}

int f_ultimo(fila f)
{
    if (f_estaVazia(f))
        return -1;

    return f.ultimo->dado;
}

void f_mostrar(fila f)
{
    struct no *aux;

    if (f_estaVazia(f))
        printf("fila vazia ...\n");

    else
    {
        aux = f.primeiro;

        while (aux != NULL)
        {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
    }
}

int f_tamanho(fila f)
{
    int contador;
    struct no *aux;

    contador = 0;

    if (f_estaVazia(f))
        return 0;

    else
    {
        aux = f.primeiro;

        while (aux != NULL)
        {
            contador += 1;
            aux = aux->prox;
        }
    }

    return contador;
}

size_t f_tamanhoBytes(fila f)
{
    int tamanhoFila;
    struct no aux;

    if (f_estaVazia(f))
        return (size_t)0;

    tamanhoFila = f_tamanho(f);
    return (size_t)(sizeof(f) + sizeof(aux) * tamanhoFila);
}

int f_enfileirar(fila *f, int dado)
{
    struct no *aux;

    aux = (struct no *)malloc(sizeof(struct no));

    if (aux == NULL)
        return 0;

    aux->dado = dado;
    aux->prox = NULL;

    if (f_estaVazia(*f))
    {
        f->primeiro = aux;
        f->ultimo = aux;

        return 1;
    }

    f->ultimo->prox = aux;
    f->ultimo = aux;

    return 1;
}

int f_desenfileirar(fila *f)
{
    int tamanhoFila = f_tamanho(*f);
    struct no *aux;

    if (f_estaVazia(*f))
        return 0;

    if (tamanhoFila == 1)
    {
        aux = f->primeiro;

        aux->dado = 0;
        aux->prox = NULL;

        f->primeiro = NULL;
        f->ultimo = NULL;
    }

    else if (tamanhoFila == 2)
    {
        aux = f->primeiro;

        aux->dado = 0;
        aux->prox = NULL;

        f->primeiro->prox = NULL;
        f->primeiro = f->ultimo;
    }

    else
    {
        aux = f->primeiro;
        f->primeiro = f->primeiro->prox;

        aux->dado = 0;
        aux->prox = NULL;
    }
 
    free(aux);
    return aux->dado;
}
