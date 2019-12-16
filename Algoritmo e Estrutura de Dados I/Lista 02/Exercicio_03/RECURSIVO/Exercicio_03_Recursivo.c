#include "Exercicio_03_Recursivo.h"

void criarArvore(Coisa *pRaiz){
    (*pRaiz) = NULL;
}

void insercao_Recursiva(Coisa *pRaiz, int numero2){
    if(*pRaiz == NULL){
        *pRaiz = (Coisa*) malloc(sizeof(Coisa));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero2;
    }else{
     if(numero2< ((*pRaiz)->numero)){
        insercao_Recursiva(&(*pRaiz)->esquerda, numero2);
     }else{
         insercao_Recursiva(&(*pRaiz)->direita, numero2);
     }
    }
}

int totalNo_Recursivo(Coisa *pRaiz){
    if(*pRaiz == NULL){
        return 0;
    }else{
        int tot_esq = totalNo_Recursivo(&((*pRaiz)->esquerda));
        int tot_dir = totalNo_Recursivo(&((*pRaiz)->direita));
        return(tot_esq+tot_dir +1);
    }
}

int maior(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int altura_Recursiva(Coisa pRaiz){
    if(pRaiz == NULL || (pRaiz->esquerda == NULL && pRaiz->direita == NULL)){
   		return 1;
    }else{
        return 1 + maior(altura_Recursiva(pRaiz->esquerda),altura_Recursiva(pRaiz->direita));
    }
}

int somaArvBin_Recursiva(Coisa *pRaiz){
    if((*pRaiz) == NULL){
        return 0;
    }else{
    	int g = (*pRaiz)->numero;
         g += somaArvBin_Recursiva(&(*pRaiz)->esquerda);
         g +=  somaArvBin_Recursiva(&(*pRaiz)->direita);
         return g;
        }
        
    }

/*int somaArvBin(Coisa *pRaiz){
	if(pRaiz==NULL){
		return 0;
	}else{
		int m;
		Coisa* aux = pRaiz->direita;
		Coisa* aux2 = pRaiz->esquerda;
		
		while(aux->direita!=NULL&&aux->esquerda!=NULL){
			while(aux)
		}
	}
}*/
