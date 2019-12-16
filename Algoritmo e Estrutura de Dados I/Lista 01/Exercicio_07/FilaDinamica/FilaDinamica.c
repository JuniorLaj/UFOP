#include "FilaDinamica.h"

void ffvazia(tipoFila *fila){
	fila->frente = (apontador) malloc(sizeof(celula));
	fila->tras = fila->frente;
	fila->tras->prox = NULL;
	fila->contador = 0;
}

int vazia(tipoFila fila){
	return(fila.frente==fila.tras);
}
void enfileira(tipoFila *fila, tipoItem x){
	fila->tras->prox = (apontador) malloc(sizeof(celula));
	fila->tras = fila->tras->prox;
	fila->tras->item = x;
	fila->contador++;
	fila->tras->prox = NULL;
}

void desenfileira(tipoFila *fila, tipoItem *x){
	if(vazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{

		apontador q = fila->frente;
		fila->frente = fila->frente->prox;
		*x = fila->frente->item;
		free(q);
	}
}

void imprimeFila(tipoFila *fila){
	if(vazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{
		apontador q = fila->frente;
		while(q->prox!=NULL){
			printf("%d\n", q->prox->item.chave);
			q = q->prox;
		}
	}
}

void verificaA(tipoFila *fila, int x){
	if(vazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	} else{
		apontador q = fila->frente;
		while(q->prox!=NULL){
			if(q->prox->item.chave == x){
				printf("Pertence a TAD!\n\n");
				return;
			}
			q = q->prox;
		}
		printf("Nao pertence a TAD!\n\n");
	}
}

void copiaC(tipoFila *fila, tipoFila *fila2){
	if(vazia(*fila)){
		printf("Fila vazia!\n\n");
		return;
	}else{
		apontador q = fila->frente;
		while(q->prox!=NULL){
			enfileira(fila2,q->prox->item);
			q =q->prox;
		}
	}
}

void concatenaD(tipoFila *fila, tipoFila *fila2){
		if(vazia(*fila)|| vazia(*fila2)){
		printf("Alugma das filas esta vazia!\n\n");
		return;
	}else{
	 	apontador q = fila->frente;
	 	while(q->prox!=NULL){
	 		enfileira(fila2,q->prox->item);
	 		 q= q->prox;
		 }
	}
}
void intercalaE(tipoFila *fila, tipoFila *fila2, tipoFila *fila3){
	if(vazia(*fila) || vazia(*fila2)){
		printf("Alguma fila para intercalar esta vazia!\n\n");
		return;
	} else{
	apontador q = fila->frente;
		apontador k = fila2->frente;
		int g =0;
			if(fila->contador > fila2->contador){
				while(q->prox!=NULL && g < fila->contador+fila2->contador){
					if(g%2==0 || k->prox==NULL){
						enfileira(fila3,q->prox->item);

					q = q->prox;
					} else if(g%2!=0 && k->prox!=NULL){
					enfileira(fila3,k->prox->item);
					k = k->prox;
						}
					g++;
			}
				}else if(fila->contador < fila2->contador){
					while(k->prox!=NULL && g < fila->contador+fila2->contador){
					if(g%2==0 || q->prox==NULL){
					enfileira(fila3,k->prox->item);
					k = k->prox;
					} else if(g%2!=0 && q->prox!=NULL){
							enfileira(fila3,q->prox->item);
					q = q->prox;
					}
					g++;
				}
			} else{
				int r;
				for(r=0; r<fila->contador+fila2->contador; r++){
					if(r%2==0){
						enfileira(fila3,q->prox->item);
						q = q->prox;
					} else {
						enfileira(fila3,k->prox->item);
						k = k->prox;
					}
				}
			}
	}
}
void intersecaoF(tipoFila *fila, tipoFila *fila2, tipoFila *fila3){
		if(vazia(*fila) || vazia(*fila2)){
		printf("Alguma fila para verificar intersecao esta vazia!\n\n");
		return;
	} else{
		apontador q = fila->frente;
		apontador k = fila2->frente;
		int z;
			while(q->prox!=NULL){
				while(k->prox!=NULL){
					if(q->prox->item.chave==k->prox->item.chave){
						z=1;
					}
					k = k->prox;
				}
				if(z==1){
					enfileira(fila3,q->prox->item);
				}
				z =0;
				q = q->prox;
				k = fila2->frente;
			}

		}
}

void diferencaG(tipoFila *fila, tipoFila *fila2, tipoFila *fila3){
	if(vazia(*fila) || vazia(*fila2)){
	printf("Alguma fila para verificar intersecao esta vazia!\n\n");
	return;
	} else{
		apontador q = fila->frente;
		apontador k = fila2->frente;
		int z=0;
		while(q->prox!=NULL){
			while(k->prox!=NULL){
			if(q->prox->item.chave==k->prox->item.chave){
				z=1;
			}
			k = k->prox;
		}
		if(z==0){
			enfileira(fila3,q->prox->item);
		}
		q = q->prox;
		k = fila2->frente;
		z = 0;
		}

		q = fila->frente;
		while(k->prox!=NULL){
			while(q->prox!=NULL){
			if(q->prox->item.chave==k->prox->item.chave){
				z=1;
			}
			q = q->prox;
		}
		if(z==0){
			enfileira(fila3,k->prox->item);
		}
		k = k->prox;
		q = fila->frente;
		z = 0;
		}
	}
}

void verificaOrdenaH(tipoFila *fila){
	if(vazia(*fila)){
	printf("Fila vazia!\n\n");
	return;
	}else{
		printf("Verificando ordenacao crescente!\n\n");
		apontador q = fila->frente;
		while(q->prox!=fila->tras){
			if(q->prox->item.chave > q->prox->prox->item.chave){
				printf("Nao esta ordenada!\n");
				return;
			}
			q =q->prox;
		}
		printf("Esta ordenada!\n\n");
}
}


