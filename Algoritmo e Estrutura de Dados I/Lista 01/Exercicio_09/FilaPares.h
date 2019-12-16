#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;

}tipoItem;
typedef struct celula *apontador;

typedef struct celula{
    apontador prox;
    tipoItem item;
}celula;

typedef struct{
    apontador frente, tras;
    int cont;
}tipoLista;

void flvazia(tipoLista *lista);
void insereLista(tipoLista *lista, tipoItem x);
void removePar(tipoLista *lista);
void imprimeLista(tipoLista *lista);
