#include "ListaSites.h"

void flvazia(tipoLista *lista){
    lista->frente = (apontador) malloc(sizeof(celula));
    lista->tras = lista->frente;
    lista->tras->prox = NULL;
    lista->cont=0;
}

void addLista(tipoLista *lista, tipoItem item){
    lista->tras->prox = (apontador) malloc(sizeof(celula));
     lista->tras->prox->item = item;
     lista->tras->prox->item.contador = 0;
     lista->tras = lista->tras->prox;
    lista->cont++;
}


void retiraLista(tipoLista *lista, tipoItem *item){
    if(lista->frente == lista->tras){
    printf("Lista vazia!\n\n");
    return;
    } else{
    apontador q;
    q = lista->frente;

        int i=0;
        *item = q->prox->item;
        lista->frente = q->prox;
        free(q);
        lista->cont--;
    }
}


void imprimeLista(tipoLista *lista){
    if(lista->frente==lista->tras){
        printf("Lista vazia!!\n\n");
        return;
    } else{
    	printf("\n\n*********************IMPRIMINDO OS ITENS*********************\n");

    apontador i = lista->frente;

    while(i->prox != NULL){
        printf("Nome: %s\n", i->prox->item.nome);
        printf("Site: %s\n", i->prox->item.site);
        printf("Numero de buscas: %d\n", i->prox->item.contador);
        printf("\n");
        i = i->prox;

        }
   	printf("\n\n*********************FIM DA LISTA*********************\n");
    }

}
void buscaLista(tipoLista *lista, char busca[]){
    int c;
	apontador g = lista->frente;
	apontador l = lista->frente;

	printf("\n\n*********************BUSCANDO ITEM*********************\n");
	while(g->prox != NULL){
		if(strcmp(g->prox->item.nome,busca)==0){
			g->prox->item.contador ++;
			printf("Nome: %s\n",g->prox->item.nome);
			printf("Site: %s\n",g->prox->item.site);
			printf("Numero de buscas: %d\n", g->prox->item.contador);
			printf("\n\n*********************FIM DE BUSCA*********************\n\n");
			c = 1;

			break;
		}
		g = g->prox;
	}
		if(c==1){

			apontador l = lista->frente;
			tipoItem celulas[lista->cont];

			int i=0;
			while(l->prox!=NULL){
				celulas[i] = l->prox->item;
				l = l->prox;
				i++;
			}
		int j;
			for(i=0; i<lista->cont; i++){
				for(j=i+1; j<lista->cont; j++){
					if(celulas[i].contador < celulas[j].contador){
						tipoItem aux;
						aux = celulas[j];
						celulas[j] = celulas[i];
						celulas[i] = aux;
					}
			}
		}
			l = lista->frente;
			i=0;
			while(l->prox!=NULL){
				l->prox->item = celulas[i];
				i++;
				l = l->prox;
			}
		}

	}


