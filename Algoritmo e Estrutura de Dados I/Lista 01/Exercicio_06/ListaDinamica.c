#include "ListaDinamica.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void flVazia(tipoLista *lista){
	lista->primeiro = (apontador) malloc(sizeof(celula));
	lista->ultimo = lista->primeiro;
	lista->contador = 0;
}

int vazia(tipoLista lista){
	return(lista.primeiro==lista.ultimo);
}

void insereLista(tipoLista *lista, tipoItem x){
	lista->ultimo->prox = (apontador) malloc(sizeof(celula));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item = x;
	lista->ultimo->prox = NULL;
	lista->contador++;
}
void novaListaA(tipoLista *lista, tipoLista *lista2){
	apontador aux = lista->primeiro->prox;
	apontador aux2 = aux->prox;
	int i;
	for(i=0; i<lista->contador-1; i++){
	lista2->ultimo->prox = (apontador) malloc(sizeof(celula));
	lista2->ultimo = lista2->ultimo->prox;
	lista2->ultimo->item = aux2->item;
	lista2->ultimo->prox = NULL;
	lista2->contador++;
	aux2 = aux2->prox;
	}
	lista2->ultimo->prox = (apontador) malloc(sizeof(celula));
	lista2->ultimo = lista2->ultimo->prox;
	lista2->ultimo->item = aux->item;
	lista2->ultimo->prox = NULL;
}
void novaListaB(tipoLista *lista, tipoLista *lista3){
	apontador aux = lista->primeiro;

	tipoItem vetor[lista->contador];

	int i=0;
	while(aux->prox!=NULL){
		vetor[i] = aux->prox->item;
		i++;
		aux = aux->prox;
	}
	//int j = lista->contador;
	for(i=lista->contador-1; i>=0; i--){
	lista3->ultimo->prox = (apontador) malloc(sizeof(celula));
	lista3->ultimo = lista3->ultimo->prox;
	lista3->ultimo->item = vetor[i];
	lista3->ultimo->prox = NULL;
	lista3->contador++;

	}
}

void novaListaC(tipoLista *lista, tipoLista *lista4){
	tipoItem vetor[lista->contador];
	apontador aux = lista->primeiro;
	int i=0;
	while(aux->prox!=NULL){
		vetor[i] = aux->prox->item;
		i++;
		aux = aux->prox;
	}
	int j=0;
	int k = lista->contador;
	i=0;
	apontador h = lista4->primeiro;
	for(j=0; j<k+1; j++){
		if(j%2==0){
			insereLista(lista4,vetor[i]);
			h = h->prox;
			i++;
		} else{
			insereLista(lista4,vetor[k-1]);
			h = h->prox;
			k--;
		}
	}
}
void imprimeLista(tipoLista *lista){
	if(vazia(*lista)){
		printf("Lista vazia!!\n\n");
		return;
	}else{
	apontador k = lista->primeiro;
	while(k->prox!=NULL){
		printf("%d\n", k->prox->item.chave);
		k = k->prox;
		}
	}
}
