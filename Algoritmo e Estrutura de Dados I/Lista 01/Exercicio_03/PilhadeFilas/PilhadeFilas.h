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
	tipoFila fila;
}tipoItemP;

typedef struct celula{
    apontador prox;
    tipoItem item;
    tipoItemP itemP;
}celula;

void ffVazia(tipoFila *fila);
int fVazia(tipoFila fila);
void enfileira(tipoFila *fila, tipoItem x);
void desenfileira(tipoFila *fila, tipoItem *x);
void imprimeFila(tipoFila fila);

void fpVazia(tipoPilha *pilha);
int vazia(tipoPilha pilha);
void emPilha(tipoPilha *pilha, tipoItemP fila);
void desemPilha(tipoPilha *pilha, tipoItemP *fila);
void imprimePilha(tipoPilha pilha);


