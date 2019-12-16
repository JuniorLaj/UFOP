#include <stdio.h>
#include <stdlib.h>
#include "Exec_03_Nao_Recursivo.h"


void criarArvore(Arvore *pRaiz){
    *pRaiz = NULL;
}


void insercao_Recursiva(Arvore *pRaiz, int numero2){
	if(*pRaiz == NULL){
		*pRaiz= (Arvore*) malloc(sizeof(Arvore));
        (*pRaiz)->direita = NULL;
        (*pRaiz)->esquerda = NULL;
        return;
	}
	
	if((*pRaiz)->numero < numero2){
		insercao_Recursiva((*pRaiz)->direita, numero2);
	}else{
		insercao_Recursiva((*pRaiz)->esquerda, numero2);
	}
}/*
void insercao(Arvore **pRaiz, int numero2){
    if(*pRaiz == NULL){
     
    }
    Arvore *aux;
	*aux = (Arvore*) malloc(sizeof(Arvore));
        (*aux)->esquerda = NULL;
        (*aux)->direita = NULL;
        (*aux)->numero = numero2;

    Arvore** ant;
	ant = NULL;
    Arvore** atual;
	*atual = *pRaiz;
    while(atual!=NULL){
    	(*ant) = (*atual);
    	if(numero2>((*atual))->numero){
    		(*atual) = (*atual)->direita;
		}else{
			(*atual) = (*atual)->esquerda;
		}
	}
	if(numero2>(*atual)->numero){
		(*atual)->direita = *aux;
	}else{
		(*atual)->esquerda = *aux;
	}
     	

}

int totalNo_Recursivo(Arvore **pRaiz){
    if(*pRaiz == NULL){
        return 0;
    }else{
        int alt_esq = totalNo_Recursivo(&((*pRaiz)->esquerda));
        int alt_dir = totalNo_Recursivo(&((*pRaiz)->direita));
        return(alt_esq+alt_dir +1);
    }
}

int maior(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int altura_Recursiva(Arvore *pRaiz){
    if(pRaiz == NULL || (pRaiz->esquerda == NULL && pRaiz->direita == NULL)){
   		return 0;
    }else{
        return 1 + maior(altura_Recursiva(pRaiz->esquerda),altura_Recursiva(pRaiz->direita));
    }
}

int somaArvBin(Arvore **pRaiz){
    if((*pRaiz) == NULL){
        return 0;
    }else{
    	int g = (*pRaiz)->numero;
        Arvore *aux = *pRaiz;
        g+=aux->direita->numero;
        aux = aux->direita;
        while(aux!=NULL){
        	g+=aux->direita->numero;
			aux = aux->direita; 
		}
        }
        
    }
    

/*int somaArvBin(Arvore *pRaiz){
	if(pRaiz==NULL){
		return 0;
	}else{
		int m;
		Arvore* aux = pRaiz->direita;
		Arvore* aux2 = pRaiz->esquerda;
		
		while(aux->direita!=NULL&&aux->esquerda!=NULL){
			while(aux)
		}
	}
}*/


int main(){

    Arvore* arvore;
    criarArvore(&arvore);
	insercao(&arvore,5);
	insercao(&arvore,8);
	insercao(&arvore,9);
	insercao(&arvore,4);
	insercao(&arvore,3);
	insercao(&arvore,6);
	insercao(&arvore,2);
	//TOTAL DE NÓS NA ARVORE
	int m = totalNo_Recursivo(&arvore);
	printf("Total de itens na arvore: %d\n", m);
	//ALTURA DA ÁRVORE
	int g = altura_Recursiva(arvore);
	printf("Altura: %d\n",g);
	//SOMA DOS NÓS DA ARVORE
	int k = somaArvBin_Recursiva(&arvore);
	printf("Soma total das chaves da arvore: %d\n",k);
    return 0;
}

