#include <stdio.h>
#include <stdlib.h>

typedef int tipoChave;

typedef struct{
	tipoChave chave;
}tipoItem;

typedef struct celula *apontador;

typedef struct tipoFila{
	apontador frente, tras;
	int contador;
}tipoFila;

typedef struct celula{
	apontador prox;
	tipoItem item;
}celula;

void ffvazia(tipoFila *fila);
int vazia(tipoFila fila);
void enfileira(tipoFila *fila, tipoItem x);
void desenfileira(tipoFila *fila, tipoItem *x);
void imprimeFila(tipoFila *fila);
void verificaA(tipoFila *fila, int x);
void copiaC(tipoFila *fila, tipoFila *fila2);
void concatenaD(tipoFila *fila, tipoFila *fila2);
void intercalaE(tipoFila *fila, tipoFila *fila2, tipoFila *fila3);
void intersecaoF(tipoFila *fila, tipoFila *fila2, tipoFila *fila3);
void diferencaG(tipoFila *fila, tipoFila *fila2, tipoFila *fila3);
void verificaOrdenaH(tipoFila *fila);
