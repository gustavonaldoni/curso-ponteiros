struct no
{
    int dado;
    struct no *prox;
};

typedef struct
{
    struct no *primeiro;
    struct no *ultimo;
} lista;

void l_criar(lista *);
int l_destruir(lista *);

int l_estaVazia(lista);
void l_mostrar(lista);

int l_primeiro(lista);
int l_ultimo(lista);

int l_tamanho(lista);
int l_tamanhoBytes(lista);

int l_inserir(lista *, int);
int l_remover(lista *, int);
int l_removerTodos(lista *, int);

int l_contar(lista, int);
int l_substituir(lista *, int, int);
