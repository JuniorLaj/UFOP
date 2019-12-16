#include <stdio.h>

typedef int tipoChave;

typedef struct{
	tipoChave chave;
}tipoItem;

typedef struct celula *apontador;

typedef struct celula{
	apontador prox;
	tipoItem item;
}celula;

typedef struct tipoPilha{
	apontador topo, fundo;
	int contador;
}tipoPilha;


void fpvazia(tipoPilha *pilha);
int vazia(tipoPilha pilha);
void emPilha(tipoPilha *pilha, tipoItem item);
void desemPilha(tipoPilha *pilha, tipoItem *item);
void imprimePilha(tipoPilha *pilha);
void verificaA(tipoPilha pilha, int x);
void copiaB(tipoPilha *pilha, tipoPilha *pilha2);
void concatenaD(tipoPilha *pilha, tipoPilha *p2);
void intercalaE(tipoPilha *pilha, tipoPilha *p2, tipoPilha *p3);
void intercessaoF(tipoPilha *pilha, tipoPilha *p2, tipoPilha *p3);
void diferencaG(tipoPilha *pilha, tipoPilha *p2, tipoPilha *p3);
void verificaordemH(tipoPilha pilha);
