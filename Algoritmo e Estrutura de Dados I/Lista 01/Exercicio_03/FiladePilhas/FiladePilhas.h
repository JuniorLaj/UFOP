#include <stdio.h>
#include <stdlib.h>

typedef int tipoChave;

typedef struct{
tipoChave chave;
}tipoItem;

typedef struct celula *apontador;

typedef struct tipoFila{
    apontador primeiro, ultimo;
    int contador;
}tipoFila;

typedef struct tipoPilha{
	apontador topo, fundo;
	tipoChave cont;
}tipoPilha;

typedef struct{
	tipoPilha pilha;
}tipoItemP;

typedef struct celula{
    apontador prox;
    tipoItem item;
    tipoItemP itemP;
}celula;

void ffVazia(tipoFila *fila);
int fVazia(tipoFila fila);
void enfileira(tipoFila *fila, tipoItemP pilha);
void desenfileira(tipoFila *fila, tipoItemP *pilha);
void imprimeFila(tipoFila *fila);

void fpVazia(tipoPilha *pilha);
int vazia(tipoPilha pilha);
void emPilha(tipoPilha *pilha, tipoItem x);
void desemPilha(tipoPilha *pilha, tipoItem *x);
void imprimePilha(tipoPilha pilha);

