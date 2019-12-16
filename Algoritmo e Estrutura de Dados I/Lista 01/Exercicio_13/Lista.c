#include "Lista.H"
#include <stdio.h>
#include <stdlib.h>

void fazLista(tLista *lista){
  lista->inicio = (apontador)malloc(sizeof(celula));
  lista->fim = lista->inicio;
  lista->inicio->proximo = NULL;
  lista->count = 0;
}

int ehVazia(tLista lista){
  return lista.count==0;
}

void add(tLista *lista, tipoChave x){
  lista->fim->proximo = (apontador)malloc(sizeof(celula));
  lista->fim = lista->fim->proximo;
  lista->fim->item.chave = x;
  lista->fim->proximo = NULL;
  lista->count++;
}

void removes(tLista *lista, tipoChave *x){
  if(ehVazia(*lista)){
    printf("A lista esta vazia\n");
    return;
  }
  apontador aux = lista->inicio;
  lista->inicio = aux->proximo;
  *x = lista->inicio->item.chave;
  free(aux);
  lista->count--;
}

void imprime(tLista lista){
  if(ehVazia(lista)){
    printf("A lista esta vazia\n");
    return;
  }
  apontador aux = lista.inicio->proximo;
  while(aux != NULL){
    printf("%d\n", aux->item.chave);
    aux = aux->proximo;
  }
}

void removeRepetido(tLista *lista){
  if(ehVazia(*lista)){
    printf("A lista esta vazia\n");
    return;
  }
  apontador aux = lista->inicio->proximo;
  apontador aux1;
  apontador aux2;
  while (aux != NULL) {
    aux1 = aux;
    aux2 = aux->proximo;
    while(aux2 != NULL){
      if(aux->item.chave == aux2->item.chave){
        if(aux2 == lista->fim){
          aux1->proximo = NULL;
          lista->fim = aux1;
          free(aux2);
          aux2 = aux1->proximo;
        } else{
        aux1->proximo = aux2->proximo;
        free(aux2);
        aux2 = aux1->proximo;
      }
    } else {
      aux1 = aux1->proximo;
      aux2 = aux1->proximo;
    }
    }
    aux = aux->proximo;
  }
}
