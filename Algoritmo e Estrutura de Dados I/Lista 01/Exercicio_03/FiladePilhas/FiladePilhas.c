#include "FilaDePilhas.h"
//PILHA
void fpVazia(tipoPilha *pilha){
	pilha->topo = (apontador) malloc(sizeof(celula));
	pilha->fundo = pilha->topo;
	pilha->cont = 0;
	pilha->fundo->prox = NULL;
}
int vazia(tipoPilha pilha){
	return(pilha.topo == pilha.fundo);
}

void emPilha(tipoPilha *pilha, tipoItem x){
	apontador aux;
	aux = (apontador) malloc(sizeof(celula));
	pilha->topo->item = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
}

void desemPilha(tipoPilha *pilha, tipoItem *x){
	if(vazia(*pilha)){
		printf("Pilha vazia!!\n\n");
		return;
	} else{

	apontador q;
	q = pilha->topo;
	*x = q->item;
	pilha->topo = q->prox;
	free(q);
	}
}

void imprimePilha(tipoPilha pilha){
	if(vazia(pilha)){
		printf("Pilha vazia!\n\n");
		return;
	}
	apontador aux = pilha.topo;
	while(aux->prox!=NULL){
		printf("%d\t", aux->prox->item.chave);
		aux = aux->prox;
	}
	printf("\n");
}

// FILA
void ffVazia(tipoFila *fila){
    fila->primeiro = (apontador) malloc(sizeof(celula));
    fila->ultimo = fila->primeiro;
    fila->contador = 0;
    fila->ultimo->prox = NULL;
}

int fVazia(tipoFila fila){
    return(fila.primeiro==fila.ultimo);
}

void enfileira(tipoFila *fila, tipoItemP pilha){
    fila->ultimo->prox = (apontador) malloc(sizeof(celula));
    fila->ultimo = fila->ultimo->prox;
    fila->ultimo->itemP = pilha;
    fila->ultimo->prox = NULL;
	fila->contador++;
}

void desenfileira(tipoFila *fila, tipoItemP *pilha){
	/*if(fvazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{*/

    apontador q = fila->primeiro->prox;
    *pilha = q->itemP;
    fila->primeiro->prox = q->prox;
    fila->contador--;
    free(q);
	}
//}


void imprimeFila(tipoFila *fila){
/*	if(fvazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{*/
    apontador aux = fila->primeiro;
    int i=1;
    while(aux->prox!=NULL){
    	printf("Imprimindo pilha %d: ", i);
        imprimePilha(aux->prox->itemP.pilha);
        aux = aux->prox;
        i++;
        }

    }
//}
