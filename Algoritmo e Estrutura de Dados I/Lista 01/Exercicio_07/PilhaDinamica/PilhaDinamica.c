#include "PilhaDinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void fpvazia(tipoPilha *pilha){
	pilha->topo = (apontador) malloc (sizeof(celula));
	pilha->fundo = pilha->topo;
	pilha->fundo->prox = NULL;
	pilha->contador = 0;
}

int vazia(tipoPilha pilha){
	return(pilha.topo==pilha.fundo);
}

void emPilha(tipoPilha *pilha, tipoItem item){
	apontador aux = (apontador)malloc(sizeof(celula));
	pilha->topo->item = item;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->contador++;
}

void desemPilha(tipoPilha *pilha, tipoItem *item){
	if(vazia(*pilha)){

	printf("Pilha vazia!!\n\n");
	return;
	}else{

	apontador q = pilha->topo;
	*item = q->prox->item;
	pilha->topo = q->prox;
	free(q);
}
}

void imprimePilha(tipoPilha *pilha){
	if(vazia(*pilha)){
		printf("Pilha vazia!!\n\n");
		return;
	} else{

	apontador aux = pilha->topo;
	while(aux->prox!=NULL){
		printf("%d\n", aux->prox->item.chave);
		aux = aux->prox;

		}
	}
}
void verificaA(tipoPilha pilha, int x){
	apontador q = pilha.topo;
	while(q->prox!=NULL){
		if(q->prox->item.chave==x){
			printf("Pertence!\n\n");
			return;
		}
		q = q->prox;
	}
	printf("Nao pertence!!\n\n");
}
void copiaB(tipoPilha *pilha, tipoPilha *pilha2){
	if(vazia(*pilha)){
		printf("Pilha vazia!!\n\n");
		return;
	} else{
		apontador aux2 = pilha->topo;
		while(aux2->prox!=NULL){
	apontador aux = (apontador)malloc(sizeof(celula));
	pilha2->topo->item = aux2->prox->item;
	aux->prox = pilha2->topo;
	pilha2->topo = aux;
	aux2 = aux2->prox;
		pilha2->contador ++;
		}

	}
}

void concatenaD(tipoPilha *pilha, tipoPilha *p2){
	if(vazia(*p2)){
		printf("Pilha para concatenar vazia!!\n\n");
		return;
	}else{
		apontador q = p2->topo;
		while(q->prox!=NULL){
	apontador aux = (apontador)malloc(sizeof(celula));
	pilha->topo->item = q->prox->item;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	q = q->prox;
		}
	}
}

void intercalaE(tipoPilha *pilha, tipoPilha *p2, tipoPilha *p3){
	if(vazia(*pilha)){
		printf("Pilha 1 vazia!\n\n");
		return;
		}else if(vazia(*pilha)){
			printf("Pilha 2 vazia!\n\n");
			return;
		} else{
			int h = pilha->contador + p2->contador;
		apontador q = p2->topo;
		apontador c = pilha->topo;
		int k =0;
		while(k!=h){
			if(k%2==0){
	apontador aux = (apontador)malloc(sizeof(celula));
	p3->topo->item = c->prox->item;
	aux->prox = p3->topo;
	p3->topo = aux;
	c = c->prox;
		} else if(k%2!=0){
	apontador aux = (apontador)malloc(sizeof(celula));
	p3->topo->item = q->prox->item;
	aux->prox = p3->topo;
	p3->topo = aux;
	q = q->prox;
		}
		k++;
		}
	}
}

void intercessaoF(tipoPilha *pilha, tipoPilha *p2, tipoPilha *p3){
	if(vazia(*pilha)){
		printf("Pilha 1 vazia!\n\n");
		return;
	} else if(vazia(*p2)){
		printf("Pilha 2 vazia!\n\n");
		return;
	} else{

		apontador q = pilha->topo;
		apontador c = p2->topo;
		while (q->prox!=NULL){
			while(c->prox!=NULL){
				if(c->prox->item.chave == q->prox->item.chave){
		apontador aux = (apontador)malloc(sizeof(celula));
		p3->topo->item = c->prox->item;
		aux->prox = p3->topo;
		p3->topo = aux;
		p3->contador ++;
				}
				c = c->prox;
			}
			c = pilha->topo;
			q =q->prox;

			}
		}
}

void diferencaG(tipoPilha *pilha, tipoPilha *p2, tipoPilha *p3){
	if(vazia(*pilha)){
		printf("Pilha vazia!\n\n");
		return;
	} else if(vazia(*p2)){
		printf("Pilha vazia!\n\n");
		return;
	} else {
		int k= 0;
		apontador q = pilha->topo;
		apontador c = p2->topo;
		while(q->prox!=NULL){
			while(c->prox!=NULL){
				if(q->prox->item.chave==c->prox->item.chave){
					k++;
				}
				c = c->prox;
			}
				if(k==0){
		apontador aux = (apontador)malloc(sizeof(celula));
		p3->topo->item = q->prox->item;
		aux->prox = p3->topo;
		p3->topo = aux;
		p3->contador ++;
				}
				k=0;
				c = p2->topo;
				q =q->prox;
			}
				while(c->prox!=NULL){
			while(q->prox!=NULL){
				if(q->prox->item.chave==c->prox->item.chave){
					k++;
				}
				q = q->prox;
			}
				if(k==0){
		apontador aux = (apontador)malloc(sizeof(celula));
		p3->topo->item = c->prox->item;
		aux->prox = p3->topo;
		p3->topo = aux;
		p3->contador ++;
				}
				k=0;
				q = pilha->topo;
			c =c->prox;
			}

		}

	}

void verificaordemH(tipoPilha pilha){
	if(vazia(pilha)){
		printf("Pilha vazia!!\n\n");
		return;
	} else{
		printf("Verificando ordenacao crescente...\n");

		apontador g = pilha.topo->prox;
		while(g!=pilha.fundo){
			if(g->item.chave > g->prox->item.chave){
				printf("Nao esta ordenada de forma crescente!\n\n");
				return;
			}
			g = g->prox;
		}
		printf("Esta ordenada de forma crescente!!\n\n");
	}

}



