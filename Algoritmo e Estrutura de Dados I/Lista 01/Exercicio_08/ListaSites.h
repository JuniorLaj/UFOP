#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

char nome[80];
char site[1000];
int contador;

}tipoItem;

typedef struct celula *apontador;

typedef struct celula{
    tipoItem item;
    apontador prox;
}celula;

typedef struct{

apontador frente;
apontador tras;
int cont;
}tipoLista;


void flvazia(tipoLista *lista);
void addLista(tipoLista *lista, tipoItem item);
void retiraLista(tipoLista *lista, tipoItem *item);
void imprimeLista(tipoLista *lista);
void buscaLista(tipoLista *lista, char busca[]);
