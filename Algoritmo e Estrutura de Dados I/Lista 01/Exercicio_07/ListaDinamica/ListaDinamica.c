#include "ListaDinamica.h"

void flvazia(tipoLista *lista){
	lista->primeiro = (apontador) malloc(sizeof(celula));
	lista->ultimo = lista->primeiro;
	lista->contador = 0;
}

int vazia(tipoLista lista){
	return(lista.primeiro==lista.ultimo);
}

void listarDireita(tipoLista *lista, tipoItem item){
	apontador aux = (apontador) malloc(sizeof(celula));
	lista->ultimo->prox = aux;
	aux->item = item;
	lista->ultimo =aux;
	aux->prox = NULL;
	lista->contador++;
//	insereOrdB(*lista);
}

void retiraLista(tipoLista *lista, tipoItem *item, int pos){
	if(vazia(*lista)){
		printf("Fila vazia!\n\n");
		return;
	} else{
		apontador k = lista->primeiro;
		apontador l = lista->primeiro->prox;
		int i;
		for(i=1; i<lista->contador+1; i++){
			if(i==pos){
				if(l->prox==NULL){
				*item = l->item;
				k->prox =NULL;
				free(l);
				return;
				}

				*item = l->item;
				k->prox = l->prox;
				free(l);
				return;
			}
			k =k->prox;
			l = l->prox;
		}
	}
}


void imprimeLista(tipoLista *lista){
		if(vazia(*lista)){
		printf("Fila vazia!\n\n");
		return;
} else{
	apontador f = lista->primeiro;
	while(f->prox!=NULL){
		printf("%d\n", f->prox->item.chave);
		f = f->prox;
		}
	}
}

void verificaA(tipoLista lista, int item){
	apontador q = lista.primeiro;

	while(q->prox!=NULL){
		if(q->prox->item.chave == item){
			printf("Pertence a TAD!\n\n");
			return;
		}
		q = q->prox;
	}
	printf("Nao pertence a TAD!\n\n");
}

void insereOrdB(tipoLista *lista, tipoItem x){

	//	ORDEM CRESCENTE
		int i;
		apontador q = lista->primeiro;
		for(i=0; i<lista->contador; i++){
			if(q->prox->item.chave>x.chave){
				apontador aux = (apontador) malloc(sizeof(celula));
				aux->item = x;
				aux->prox = q->prox;
				q->prox = aux;
				lista->contador++;

				return;
			}
			q = q->prox;
		}
	lista->ultimo->prox = (apontador) malloc(sizeof(celula));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item = x;
	lista->ultimo->prox = NULL;
	lista->contador++;
	}

void Ordena(tipoLista *lista){


		apontador aux = lista->primeiro;
		tipoItem vet[lista->contador];
		int z=0;
			while(aux->prox!=NULL){
				vet[z] = aux->prox->item;
				z++;
				aux = aux->prox;
			}
		int i, j;
		//ORDEM CRESCENTE!!
			for(j=0; j<lista->contador; j++){
				for(i=j+1; i<lista->contador; i++){
					if(vet[i].chave < vet[j].chave){
						tipoItem aux = vet[j];
						vet[j] = vet[i];
						vet[i] = aux;
					}
				}
			}
				//ORDEM DECRESCENTE!!
		/*	for(i=0; i<lista->contador; i++){
				for(j=i+1; j<lista->contador; j++){
					if(vet[i].chave < vet[j].chave){
						tipoItem aux = vet[j];
						vet[j] = vet[i];
						vet[i] = aux;
					}
				}
			}*/
			for(i=0; i<lista->contador; i++){
				printf("%d\n", vet[i].chave);
			}
			 aux = lista->primeiro;
			i=0;
			while(aux->prox!=NULL){
				aux->prox->item = vet[i];
				i++;
				aux = aux->prox;
			}


	}




void copiaC(tipoLista *lista, tipoLista *lista2){
	if(vazia(*lista)){
		printf("Lista vazia!!\n\n");
		return;
	} else{
		apontador q = lista->primeiro;
		while(q->prox!=NULL){
		listarDireita(lista2,q->prox->item);
	/*apontador aux = (apontador) malloc(sizeof(celula));
	lista2->ultimo->prox = aux;
	aux->item = q->prox->item;
	lista2->ultimo =aux;
	aux->prox = NULL;
	lista2->contador++;*/
	q =q->prox;
		}
	}
}
void concatenaD(tipoLista *lista, tipoLista *lista2){
	if(vazia(*lista2)){
		printf("Lista para concatenar vazia!!\n\n");
		return;
	} else{
		apontador q = lista2->primeiro;
		while(q->prox!=NULL){
		listarDireita(lista,q->prox->item);
	/*apontador aux = (apontador) malloc(sizeof(celula));
	lista->ultimo->prox = aux;
	aux->item = q->prox->item;
	lista->ultimo =aux;
	aux->prox = NULL;
	lista->contador++;*/
	q = q->prox;
		}
	}
}

void intercalaE(tipoLista *lista, tipoLista *lista2, tipoLista *lista3){
	if(vazia(*lista) || vazia(*lista2)){
		printf("Alguma lista para intercalar esta vazia!\n\n");
		return;
	} else{
		apontador q = lista->primeiro;
		apontador k = lista2->primeiro;
		int g =0;
			if(lista->contador > lista2->contador){
				while(q->prox!=NULL && g < lista->contador+lista2->contador){
					if(g%2==0 || k->prox==NULL){
						listarDireita(lista3,q->prox->item);
					/*apontador aux = (apontador) malloc(sizeof(celula));
					lista3->ultimo->prox = aux;
					aux->item = q->prox->item;
					lista3->ultimo =aux;
					aux->prox = NULL;
					lista3->contador++;*/
					q = q->prox;
					} else if(g%2!=0 && k->prox!=NULL){
						listarDireita(lista3,k->prox->item);
					/*apontador aux = (apontador) malloc(sizeof(celula));
					lista3->ultimo->prox = aux;
					aux->item = k->prox->item;
					lista3->ultimo =aux;
					aux->prox = NULL;
					lista3->contador++;*/
					k = k->prox;

					}
					g++;
					}
			} else if(lista->contador < lista2->contador){
					while(k->prox!=NULL && g < lista->contador+lista2->contador){
					if(g%2==0 || q->prox==NULL){
							listarDireita(lista3,k->prox->item);
					/*apontador aux = (apontador) malloc(sizeof(celula));
					lista3->ultimo->prox = aux;
					aux->item = k->prox->item;
					lista3->ultimo =aux;
					aux->prox = NULL;
					lista3->contador++;*/
					k = k->prox;
					} else if(g%2!=0 && q->prox!=NULL){
							listarDireita(lista3,q->prox->item);
							/*
					apontador aux = (apontador) malloc(sizeof(celula));
					lista3->ultimo->prox = aux;
					aux->item = q->prox->item;
					lista3->ultimo =aux;
					aux->prox = NULL;
					lista3->contador++;*/
					q = q->prox;
					}
					g++;
					}
			} else{
				int r;
				for(r=0; r<lista->contador+lista2->contador; r++){
					if(r%2==0){
						listarDireita(lista3,q->prox->item);
						q = q->prox;
					} else {
						listarDireita(lista3,k->prox->item);
						k = k->prox;
					}
				}
			}
		}
}

void intercedeF(tipoLista *lista, tipoLista *lista2, tipoLista *lista3){
	if(vazia(*lista) || vazia(*lista2)){
		printf("Alguma lista esta vazia!\n\n");
		return;
	} else {
		apontador q = lista->primeiro;
		apontador k = lista2->primeiro;

		while(q->prox!=NULL){
			for(k=lista2->primeiro; k->prox!=NULL; k=k->prox){
			if(q->prox->item.chave == k->prox->item.chave){
				listarDireita(lista3,q->prox->item);
				}
			}
			q =q->prox;
		}
	}
}

void diferencaG(tipoLista *lista, tipoLista *lista2, tipoLista *lista3){
	if(vazia(*lista) || vazia(*lista2)){
	printf("Alguma lista esta vazia!\n\n");
	return;
	} else{
		int z=0;
		apontador q = lista->primeiro;
		apontador k = lista2->primeiro;
			while(q->prox!=NULL){
			for(k=lista2->primeiro; k->prox!=NULL; k = k->prox){
			if(q->prox->item.chave == k->prox->item.chave){
				z = 1;
			}
			}	if(z==0){
				listarDireita(lista3,q->prox->item);
				}
			q =q->prox;
			z = 0;
			k = lista2->primeiro;
			}
		q = lista->primeiro;

			while(k->prox!= NULL){
				for(q=lista->primeiro; q->prox!=NULL; q = q->prox){
			if(k->prox->item.chave == q->prox->item.chave){
				z = 1;
			}
		}
			if(z==0){
				listarDireita(lista3,k->prox->item);
			}
			k = k->prox;
			z=0;
			q = lista->primeiro;
			}

		}
	}

void verificaOrdenaH(tipoLista lista){
	if(vazia(lista)){
		printf("Lista vazia!\n\n");
		return;
	} else {
		printf("Verificando ordenacao crescente: ");
		int i;
		apontador q = lista.primeiro;
		while(q->prox!=lista.ultimo){
			if(q->prox->item.chave > q->prox->prox->item.chave){
				printf("Nao esta ordenada!\n\n");
				return;

			}
			q = q->prox;
		}
			printf("Lista ordenada!\n\n");

		}
	}
void mesclaI(tipoLista *lista, tipoLista *lista2){
	if(vazia(*lista)|| vazia(*lista2)){
		printf("Alguma lista esta vazia!\n\n");
		return;
	} else{
		copiaC(lista,lista2);
		Ordena(lista2);
	}
}










