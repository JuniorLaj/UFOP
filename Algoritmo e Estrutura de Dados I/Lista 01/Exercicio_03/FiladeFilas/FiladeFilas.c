#include "FilaDeFilas.h"
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
    fila->primeiro->prox = q->prox;
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
	printf("\n");
}
//}
// FILA DE FILAS
void ffVaziaP(tipoFila *fila){
    fila->primeiro = (apontador) malloc(sizeof(celula));
    fila->ultimo = fila->primeiro;
    fila->contador = 0;
    fila->ultimo->prox = NULL;
}

int fVaziaP(tipoFila fila){
    return(fila.primeiro==fila.ultimo);
}

void enfileiraP(tipoFila *fila, tipoItemP filaP){
    fila->ultimo->prox = (apontador) malloc(sizeof(celula));
    fila->ultimo = fila->ultimo->prox;
    fila->ultimo->itemP = filaP;
    fila->ultimo->prox = NULL;
	fila->contador++;
}

void desenfileiraP(tipoFila *fila, tipoItemP *filaP){
	/*if(fvazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{*/

    apontador q = fila->primeiro->prox;
    *filaP = q->itemP;
    fila->primeiro->prox = q->prox;
    fila->contador--;
    free(q);
	}
//}


void imprimeFilaP(tipoFila *fila){
/*	if(fvazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{*/
    apontador aux = fila->primeiro;
    int i=1;
    while(aux->prox!=NULL){
    	printf("Imprimindo fila %d: ", i);
        imprimeFila(aux->prox->itemP.fila);
        aux = aux->prox;
        i++;
        }

    }
//}
