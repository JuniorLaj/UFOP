#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int chave;
}tipoItem;

typedef struct celula *apontador;

typedef struct tipoLista{
	apontador primeiro, ultimo;
	int contador;
}tipoLista;

typedef struct celula{
	tipoItem item;
	apontador prox;
}celula;



void flVazia(tipoLista *lista);
int vazia(tipoLista lista);
void insereLista(tipoLista *lista, tipoItem x);
void imprimeLista(tipoLista *lista);
void novaListaA(tipoLista *lista, tipoLista *lista2);
void novaListaB(tipoLista *lista, tipoLista *lista3);
