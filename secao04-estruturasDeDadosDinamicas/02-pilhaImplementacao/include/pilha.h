struct no
{
    int dado;
    struct no *prox;
};

typedef struct
{
    struct no *topo;
} pilha;

void p_criar(pilha *);
void p_destruir(pilha *);
int p_estaVazia(pilha);
int p_insere(pilha *, int);
void p_mostrar(pilha);
int p_remove(pilha *);
int p_topo(pilha);

int p_tamanho(pilha);
size_t p_tamanhoBytes(pilha);
