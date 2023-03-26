#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void l_criar(lista *l)
{
    l->primeiro = NULL;
    l->ultimo = NULL;
}

int l_destruir(lista *l)
{
    struct no *aux;

    if (l_estaVazia(*l))
        return 0;

    aux = l->primeiro;

    while (aux != NULL)
    {
        l_remover(l, aux->dado);
        aux = l->primeiro;
    }

    return 1;
}

int l_estaVazia(lista l)
{
    return l.primeiro == NULL &&
           l.ultimo == NULL;
}

void l_mostrar(lista l)
{
    struct no *aux;

    if (l_estaVazia(l))
    {
        printf("lista vazia ...\n");
        return;
    }
        
    aux = l.primeiro;

    while (aux != NULL)
    {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}

int l_primeiro(lista l)
{
    if (l_estaVazia(l))
        return -1;

    return l.primeiro->dado;
}

int l_ultimo(lista l)
{
    if (l_estaVazia(l))
        return -1;

    return l.ultimo->dado;
}

int l_tamanho(lista l)
{
    int contador = 0;
    struct no *aux;

    if (l_estaVazia(l))
        return 0;

    aux = l.primeiro;

    while (aux != NULL)
    {
        contador += 1;
        aux = aux->prox;
    }

    return contador;
}

int l_tamanhoBytes(lista l)
{
    int numeroElementos = l_tamanho(l);

    return (size_t) (sizeof(l) + numeroElementos * sizeof(struct no));
}

int l_inserir(lista *l, int dado)
{
    struct no *aux;

    aux = (struct no *)malloc(sizeof(struct no));

    if (aux == NULL)
        return 0;

    aux->dado = dado;

    if (l_estaVazia(*l))
    {
        l->primeiro = aux;
        l->ultimo = aux;

        aux->prox = NULL;

        return 1;
    }

    l->ultimo->prox = aux;
    aux->prox = NULL;
    l->ultimo = aux;

    return 1;
}

int l_remover(lista *l, int dado)
{
    struct no *aux, *anterior, *atual;
    int temp;

    if (l_estaVazia(*l))
        return -1;

    // Remover único elemento de lista unitária
    if (l->primeiro == l->ultimo && l->primeiro != NULL && l->primeiro->dado == dado)
    {
        aux = l->primeiro;
        temp = aux->dado;

        aux->dado = 0;

        l->primeiro = NULL;
        l->ultimo = NULL;

        free(aux);

        return temp;
    }

    // Remover primeiro elemento de lista não unitária
    if (l->primeiro != l->ultimo && l->primeiro->dado == dado)
    {
        aux = l->primeiro;
        temp = aux->dado;

        l->primeiro = l->primeiro->prox;

        free(aux);

        return temp;
    }

    // Remover elemento de qualquer outra posição da lista
    anterior = l->primeiro;
    atual = anterior->prox;

    while (atual->dado != dado && atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return -1;

    // Chegou no último elemento da lista
    else if (atual->prox == NULL)
    {
        aux = atual;
        temp = aux->dado;

        anterior->prox = NULL;
        l->ultimo = anterior;

        free(aux);

        return temp;
    }

    else
    {
        aux = atual;
        temp = aux->dado;

        anterior->prox = atual->prox;

        free(aux);

        return temp;
    }
}

int l_removerTodos(lista *l, int dado)
{
    int i;
    int repeticoes = l_contar(*l, dado);

    if (repeticoes == 0)
        return 0;

    for (i = 0; i < repeticoes; i++)
        l_remover(l, dado);
    
    return 1;
}

int l_contar(lista l, int dado)
{
    int contador = 0;
    struct no *aux;

    if (l_estaVazia(l))
        return 0;

    aux = l.primeiro;

    while (aux != NULL)
    {
        if (aux->dado == dado)
            contador += 1;
            
        aux = aux->prox;
    }

    return contador;
}

int l_substituir(lista *l, int dadoOrigem, int dadoDestino)
{
    struct no *aux;

    if (l_estaVazia(*l))
        return 0;

    aux = l->primeiro;

    while (aux != NULL)
    {
        if (aux->dado == dadoOrigem)
        {
            aux->dado = dadoDestino;
            return 1;
        }
              
        aux = aux->prox;
    }

    return 0;
}