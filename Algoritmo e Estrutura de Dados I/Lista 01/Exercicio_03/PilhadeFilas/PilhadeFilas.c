#include "PilhaDeFilas.h"
// FILA
void ffVazia(tipoFila *fila){
    fila->primeiro = (apontador) malloc(sizeof(celula));
    fila->ultimo = fila->primeiro;
    fila->contador = 0;
}

int fVazia(tipoFila fila){
    return(fila.primeiro==fila.ultimo);
}

void enfileira(tipoFila *fila, tipoItem x){
    fila->ultimo->prox = (apontador) malloc(sizeof(celula));
    fila->ultimo = fila->ultimo->prox;
    fila->ultimo->item = x;
    fila->ultimo->prox = NULL;
	fila->contador++;
}

void desenfileira(tipoFila *fila, tipoItem *x){
	/*if(fvazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{*/

    apontador q = fila->primeiro->prox;
    *x = q->item;
    fila->primeiro = q->prox;
    fila->contador--;
    free(q);
	}
//}


void imprimeFila(tipoFila fila){
/*	if(fvazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{*/
    apontador aux = fila.primeiro;
    while(aux->prox!=NULL){
        printf("%d\t", aux->prox->item.chave);
        aux = aux->prox;
        }
    }
//}

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

void emPilha(tipoPilha *pilha, tipoItemP x){
	apontador aux;
	aux = (apontador) malloc(sizeof(celula));
	pilha->topo->itemP = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
}

void desemPilha(tipoPilha *pilha, tipoItemP *x){
	if(vazia(*pilha)){
		printf("Pilha vazia!!\n\n");
		return;
	} else{

	apontador q;
	q = pilha->topo;
	*x = q->itemP;
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
	int x= 1;
	while(aux->prox!=NULL){
		printf("Imprimindo fila %d: ", x);
		imprimeFila(aux->prox->itemP.fila);
		aux = aux->prox;
		x++;
		printf("\n");
	}

}


