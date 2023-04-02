typedef struct
{
    int linhas, colunas;
    float *conteudo;
} matrizFloat;

int mf_criar(matrizFloat *, int, int);
int mf_destruir(matrizFloat *);

void mf_mostrar(matrizFloat);
int mf_estaVazia(matrizFloat);
int mf_validarNumeroLinhaNumeroColuna(int, int, matrizFloat);

void mf_alterarValor(int, int, float, matrizFloat *);
float mf_retornarValor(int, int, matrizFloat);

void mf_criarIdentidade(int, matrizFloat*);

int mf_somar(matrizFloat *, matrizFloat *, matrizFloat *);
int mf_subtrair(matrizFloat *, matrizFloat *, matrizFloat *);

int mf_multiplicarPorEscalar(float, matrizFloat *, matrizFloat *);
int mf_multiplicar(matrizFloat *, matrizFloat *, matrizFloat *);

int mf_inserirLinha(matrizFloat *);
int mf_inserirColuna(matrizFloat *);

int mf_removerLinha(matrizFloat *, int);
