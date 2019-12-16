#include "FilaPares.h"

void flvazia(tipoLista *lista){

    lista->frente = (apontador) malloc(sizeof(celula));
    lista->tras = lista->frente;
     lista->cont = 0;
    }

void insereLista(tipoLista *lista, tipoItem x){
    lista->tras->prox = (apontador) malloc(sizeof(celula));
    lista->tras->prox->item = x;
    lista->tras = lista->tras->prox;
    lista->tras->prox = NULL;
}

void removePar(tipoLista *lista){
    apontador t = lista->frente;
    apontador aux = lista->frente->prox;
    while(aux!=NULL){

        if(aux->item.chave%2==0){
            if(aux->prox == NULL){
                lista->tras = t;
                t->prox = NULL;
                free(aux);
                return;
            } else{
            t->prox = aux->prox;
            free(aux);
            aux = t->prox;
            }
        }
            else{
            t = aux;
            aux = aux->prox;
    		}

    	}

    }

void imprimeLista(tipoLista *lista){
    if(lista->frente==lista->tras){
        printf("Lista vazia!\n\n");
        return;
    } else{
        apontador aux = lista->frente;

        while(aux->prox!=NULL){
            printf("%d\n", aux->prox->item.chave);
            aux = aux->prox;
        }
        printf("\nFIM!\n\n");
    }
}
