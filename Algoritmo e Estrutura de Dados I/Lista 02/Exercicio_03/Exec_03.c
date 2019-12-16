#include "Exec_03.h"


void criarArvore(Coisa **pRaiz){
    (*pRaiz) = NULL;
}

void insercao_Recursiva(No **pRaiz, int numero2){
    if(*pRaiz == NULL){
        *pRaiz = (Coisa*) malloc(sizeof(Coisa));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero2;
        return;
    }else{
     if(numero2< ((*pRaiz)->numero)){
        insercao_Recursiva(&((*pRaiz)->esquerda), numero2);
     }else{
         insercao_Recursiva(&((*pRaiz)->direita), numero2);
     }
    }
}

int totalNO_Recursivo(No **pRaiz){
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

int altura_Recursiva(No *pRaiz){
    if(pRaiz == NULL || (pRaiz->esquerda == NULL && pRaiz->direita == NULL)){
   		return 0;
    }else{
        return 1 + maior(altura_Recursiva(pRaiz->esquerda),altura_Recursiva(pRaiz->direita));
    }
}

int somaArvBin_Recursiva(No **pRaiz){
    if((*pRaiz) == NULL){
        return 0;
    }else{
    	int g = (*pRaiz)->numero;
         g += somaArvBin_Recursiva(&(*pRaiz)->esquerda);
         g +=  somaArvBin_Recursiva(&(*pRaiz)->direita);
         return g;
        }

    }
