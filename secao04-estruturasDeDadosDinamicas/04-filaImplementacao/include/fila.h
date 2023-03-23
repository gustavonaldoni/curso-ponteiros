struct no
{
    int dado;
    struct no *prox;
};

typedef struct
{
    struct no *primeiro;
    struct no *ultimo;
} fila;

void f_criar(fila *);
void f_destruir(fila *);
int f_estaVazia(fila);

int f_primeiro(fila);
int f_ultimo(fila);

int f_enfileirar(fila *, int);
int f_desenfileirar(fila *);

void f_mostrar(fila);

int f_tamanho(fila);
size_t f_tamanhoBytes(fila);
