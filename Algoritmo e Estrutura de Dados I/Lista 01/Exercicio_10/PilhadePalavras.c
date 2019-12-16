#include "PilhadePalavras.h"


void fpilhaVazia(tipoPilha *pilha){
    pilha->topo = (apontador) malloc(sizeof(celula));
    pilha->fundo = pilha->topo;
    pilha->fundo->prox = NULL;
    pilha->Tamanho = 0;
}

int vazia(tipoPilha pilha){
    return (pilha.topo == pilha.fundo);
}

void emPilha(tipoPilha *pilha, tipoItem x){

        apontador aux = (apontador) malloc (sizeof(celula));
        aux->prox = pilha->topo;
        pilha->topo->item = x;
        pilha->topo = aux;
    }

void emPilhaPartes(tipoPilha *pilha, char x[]){
		int i=0;
        while(x[i] != '\0'){

        apontador aux = (apontador) malloc (sizeof(celula));
        aux->prox = pilha->topo;
        pilha->topo->item.chave = x[i];
        pilha->topo = aux;
        i++;
	}
}

void palindromStrings(tipoPilha pilha){
	apontador aux = pilha.topo;
	char stringContraria[1000];
	int i=0;
	int k;
	while(aux->prox!=NULL){
		if(aux->prox->item.chave != '-' && aux->prox->item.chave != ' ' && aux->prox->item.chave != '.'){

		stringContraria[i] = aux->prox->item.chave;
		i++;
		k = i;
	}
	aux = aux->prox;
}
	printf("String contraria: %s\n\n\n", stringContraria);

	char stringComp[1000];
	int j=0;
	for(i=k; i>0;i--){
		stringComp[j] = stringContraria[i-1];
		j++;
	}
	printf("String: %s\n\n\n",stringComp);

    i = 0;

    while(k!=0){
        if(stringComp[i]!=stringContraria[i]){
        printf("Nao e palindromo!\n\n");
        return;
        }
        k--;
    }
    printf("E palindromo!\n\n");
}

void desemPilha(tipoPilha *pilha, tipoItem *x){
	if(vazia(*pilha)){
		printf("Pilha vazia!\n\n");
		return;
	} else{

	apontador q = pilha->topo;
	*x = q->item;
	pilha->topo = pilha->topo->prox;
	free(q);
	}
}

void imprimePilha(tipoPilha pilha){
	if(vazia(pilha)){
		printf("Pilha vazia!\n\n");
		return;
	} else{

		apontador aux = pilha.topo;
		while(aux->prox!=NULL){
			printf("%c\n", aux->prox->item.chave);
			aux = aux->prox;
		}
		printf("\n");
	}
}


