#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char chave;
}tipoItem;

typedef struct celula *apontador;

typedef struct celula{
	tipoItem item;
	apontador prox;
}celula;


typedef struct tipoPilha{
	apontador topo, fundo;
	int Tamanho;

}tipoPilha;



void fpilhaVazia(tipoPilha *pilha);
int vazia(tipoPilha pilha);
void emPilha(tipoPilha *pilha, tipoItem x);
void emPilhaPartes(tipoPilha *pilha, char x[]);
void palindromStrings(tipoPilha pilha);
void desemPilha(tipoPilha *pilha, tipoItem *x);
void imprimePilha(tipoPilha pilha);

