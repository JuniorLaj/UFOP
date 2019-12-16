#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tipoChave;

typedef struct{
	tipoChave chave;
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

void flvazia(tipoLista *lista);
int vazia(tipoLista lista);
void retiraLista(tipoLista *lista, tipoItem *item, int pos);
void imprimeLista(tipoLista *lista);
void verificaA(tipoLista lista, int item);
void insereOrdB(tipoLista *lista, tipoItem x);
void Ordena(tipoLista *lista);
void copiaC(tipoLista *lista, tipoLista *lista2);
void concatenaD(tipoLista *lista, tipoLista *lista2);
void intercalaE(tipoLista *lista, tipoLista *lista2, tipoLista *lista3);
void intercedeF(tipoLista *lista, tipoLista *lista2, tipoLista *lista3);
void diferencaG(tipoLista *lista, tipoLista *lista2, tipoLista *lista3);
void verificaOrdenaH(tipoLista lista);
void mesclaI(tipoLista *lista, tipoLista *lista2);
