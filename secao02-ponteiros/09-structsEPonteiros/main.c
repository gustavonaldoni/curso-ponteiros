#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x, y;
    int tamanho;
    int vidas;
    int pontuacao;
} Jogador;

void criarJogador(Jogador *, int, int, int, int);
void aumentarTamanhoJogador(Jogador *, int);
void atualizarVidasJogador(Jogador *, int);
void atualizarPontuacaoJogador(Jogador *, int);

typedef struct
{
    int x, y;
    float largura, altura;
} Retangulo;

void criarRetangulo(Retangulo *, int, int, float, float);
void escalarLadosRetangulo(Retangulo *, float);
void atualizarPosicaoRetangulo(Retangulo *, int, int);

typedef struct
{
    int x, y;
    float lado;
} Quadrado;

void criarQuadrado(Quadrado *, int, int, float);
void escalarAreaQuadrado(Quadrado *, float);
void atualizarPosicaoQuadrado(Quadrado *, int, int);

int main(void)
{
    Jogador j;
    criarJogador(&j, 0, 0, 200, 10);

    printf("\n");
    printf("=== Jogador j ===\n\n");

    printf("(j.x, j.y) = (%d, %d)\n", j.x, j.y);
    printf("j.tamanho = %d\n", j.tamanho);
    printf("j.vidas = %d\n", j.vidas);
    printf("j.pontuacao = %d\n\n", j.pontuacao);

    aumentarTamanhoJogador(&j, 20);
    atualizarVidasJogador(&j, 5);
    atualizarPontuacaoJogador(&j, 2);

    printf("(j.x, j.y) = (%d, %d)\n", j.x, j.y);
    printf("j.tamanho = %d\n", j.tamanho);
    printf("j.vidas = %d\n", j.vidas);
    printf("j.pontuacao = %d\n\n", j.pontuacao);

    Retangulo r;
    criarRetangulo(&r, 50, 50, 100.0f, 500.0f);

    printf("\n");
    printf("(r.x, r.y) = (%d, %d)\n", r.x, r.y);
    printf("r.largura = %f\n", r.largura);
    printf("r.altura = %f\n\n", r.altura);

    atualizarPosicaoRetangulo(&r, 20, 30);
    escalarLadosRetangulo(&r, 2.5f);

    printf("(r.x, r.y) = (%d, %d)\n", r.x, r.y);
    printf("r.largura = %f\n", r.largura);
    printf("r.altura = %f\n\n", r.altura);

    Quadrado q;
    criarQuadrado(&q, 0, 0, 200.0f);

    printf("\n");
    printf("(q.x, q.y) = (%d, %d)\n", q.x, q.y);
    printf("q.lado = %f\n", q.lado);

    atualizarPosicaoQuadrado(&q, 150, 120);
    escalarAreaQuadrado(&q, 4.0f);

    printf("(q.x, q.y) = (%d, %d)\n", q.x, q.y);
    printf("q.lado = %f\n", q.lado);
}

void criarJogador(Jogador *jogador, int x, int y, int tamanho, int vidas)
{
    jogador->x = x;
    jogador->y = y;
    jogador->tamanho = tamanho;
    jogador->vidas = vidas;

    jogador->pontuacao = 0;
}

void aumentarTamanhoJogador(Jogador *jogador, int incremento)
{
    jogador->tamanho += incremento;
}

void atualizarVidasJogador(Jogador *jogador, int novoValor)
{
    jogador->vidas = novoValor;
}

void atualizarPontuacaoJogador(Jogador *jogador, int novaPontuacao)
{
    jogador->pontuacao = novaPontuacao;
}

void criarRetangulo(Retangulo *retangulo, int x, int y, float largura, float altura)
{
    retangulo->x = x;
    retangulo->y = y;
    retangulo->largura = largura;
    retangulo->altura = altura;
}

void escalarLadosRetangulo(Retangulo *retangulo, float fator)
{
    retangulo->largura *= fator;
    retangulo->altura *= fator;
}

void atualizarPosicaoRetangulo(Retangulo *retangulo, int novoX, int novoY)
{
    retangulo->x = novoX;
    retangulo->y = novoY;
}

void criarQuadrado(Quadrado *quadrado, int x, int y, float lado)
{
    quadrado->x = x;
    quadrado->y = y;
    quadrado->lado = lado;
}

void escalarAreaQuadrado(Quadrado *quadrado, float fator)
{
    quadrado->lado *= sqrtf(fator);
}

void atualizarPosicaoQuadrado(Quadrado *quadrado, int novoX, int novoY)
{
    quadrado->x = novoX;
    quadrado->y = novoY;
}
