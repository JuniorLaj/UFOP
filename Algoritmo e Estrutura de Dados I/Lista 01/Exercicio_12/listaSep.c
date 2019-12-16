#include "listaSep.h"

void flvazia(tipoLista *lista){
	lista->primeiro = (apontador) malloc(sizeof(celula));
	lista->ultimo = lista->primeiro;
	lista->ultimo->prox = NULL;
	lista->contador = 0;
}

void fpvazia(tipoPilha *pilha){
	pilha->topo = (apontador) malloc(sizeof(celula));
	pilha->fundo = pilha->topo;
	pilha->fundo->prox = NULL;
	pilha->contador =0;
}

int vazia(tipoLista lista){
	return(lista.primeiro==lista.ultimo);
}
int vaziaP(tipoPilha pilha){
	return(pilha.topo==pilha.fundo);
}

void insere(tipoLista *lista, tipoItem x){
	lista->ultimo->prox = (apontador) malloc(sizeof(celula));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item = x;
	lista->ultimo->prox = NULL;
	lista->contador++;
}
void inserePilha(tipoPilha *pilha, tipoItem x){
	apontador aux = (apontador) malloc(sizeof(celula));
	pilha->topo->item = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->contador++;
}

void retira(tipoLista *lista, tipoItem *x, int pos){
	if(vazia(*lista)){
		printf("Lista vazia!\n\n");
		return;
	} else{
		if(pos>lista->contador){
			printf("Posicao nao existe!\n\n");
			return;
		}
		apontador q = lista->primeiro;
		int i=1;
		while(q->prox!=NULL){
			if(i!=pos){
			} else{
				if(q->prox==lista->ultimo){
					apontador k = q->prox;
					*x = k->item;
					q->prox = NULL;
					free(k);
				}
				apontador k = q->prox;
				*x = k->item;
				q->prox = k->prox;
				free(k);
				return;
			}
			q = q->prox;
			i++;
		}
	}


}

void retiraPilha(tipoPilha *pilha, tipoItem *x){
	if(vaziaP(*pilha)){
		printf("Pilha vazia!\n\n");
		return;
	} else{
		apontador q = pilha->topo;
		*x = q->prox->item;
		pilha->topo = pilha->topo->prox;
		free(q);
	}
}


void imprime(tipoLista *lista){
	if(vazia(*lista)){
		printf("Lista vazia!\n\n");
		return;
	}else{
		apontador k = lista->primeiro;
		while(k->prox!=NULL){
			printf("%c  ", k->prox->item.tipoChave);
		k = k->prox;
		}
	}
}
void imprimePilha(tipoPilha *pilha){
	if(vaziaP(*pilha)){
		printf("Pilha vazia!\n\n");
		return;
	} else{
		apontador q = pilha->topo;
		while(q->prox!=NULL){
			printf("%c\n", q->prox->item.tipoChave);
		q =q->prox;
		}
	}
}

int ehDigito(char item){
	if(item == '1' || item == '2' || item == '3' || item == '4' || item == '5' || item == '6'
	|| item == '7' || item == '8' || item == '9' || item == '0'){
		return 1;
	} else{
		return 0;
	}
}

void arruma(tipoLista *lista, tipoPilha *pilha, tipoLista *lista2){
	apontador q = lista->primeiro;
	int i=0;
	while(q->prox!=NULL){
		if(ehDigito(q->prox->item.tipoChave)==0){
			insere(lista2,q->prox->item);
		} else{
			inserePilha(pilha,q->prox->item);
			i++;
		}
		q = q->prox;
	}
	apontador k = pilha->topo;
	while(k->prox!=NULL){
		insere(lista2,k->prox->item);
		k = k->prox;
	}

}
