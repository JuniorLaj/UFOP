#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char tipoChave;
}tipoItem;

typedef struct celula *apontador;

typedef struct celula{
	apontador prox;
	tipoItem item;
}celula;

typedef struct tipoLista{
	apontador primeiro, ultimo;
	int contador;
}tipoLista;

//PILHA
typedef struct tipoPilha{
	apontador topo, fundo;
	int contador;
}tipoPilha;

void flvazia(tipoLista *lista);
void fpvazia(tipoPilha *pilha);
int vazia(tipoLista lista);
int vaziaP(tipoPilha pilha);
void insere(tipoLista *lista, tipoItem x);
void inserePilha(tipoPilha *pilha, tipoItem x);
void retira(tipoLista *lista, tipoItem *x, int pos);
void retiraPilha(tipoPilha *pilha, tipoItem *x);
void imprime(tipoLista *lista);
void imprimePilha(tipoPilha *pilha);
int ehDigito(char item);
void arruma(tipoLista *lista, tipoPilha *pilha, tipoLista *lista2);


