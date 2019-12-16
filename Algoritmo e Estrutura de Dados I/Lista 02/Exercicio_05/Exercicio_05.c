#include "Exercicio_05.h"
void criarArvore(arvore **pRaiz){
    *pRaiz = NULL;
}

void insercao(arvore **pRaiz, int numero2){
	No *novo = malloc(sizeof(No));
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->numero = numero2;
    if(*pRaiz == NULL){
        *pRaiz = novo;
        return;
    }
       
    No* ant;
    No* atual = *pRaiz;
    while(atual!=NULL){
    	ant = atual;
    	if(numero2>atual->numero){
    		atual = atual->direita;
		}else{
			atual = atual->esquerda;
		}
	}
	if(numero2>ant->numero){
		ant->direita = novo;
	}else{
		ant->esquerda = novo;
	}
     	
}

int totalNo_Recursivo(arvore *pRaiz){
    if(*pRaiz == NULL){
        return 0;
    }else{
        int alt_esq = totalNo_Recursivo(&(*pRaiz)->esquerda);
        int alt_dir = totalNo_Recursivo(&(*pRaiz)->direita);
        return(alt_esq+alt_dir +1);
    }
}

int estritamente(arvore *pRaiz){
	if(*pRaiz == NULL){
		return 0;
	}
	if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita !=NULL || (*pRaiz)->esquerda != NULL && (*pRaiz)->direita ==NULL){
		return 1;
	}
	int h = estritamente(&(*pRaiz)->esquerda);
	int g = estritamente(&(*pRaiz)->direita);
	return(h+g);
}

int binariaCompleta(arvore *pRaiz){
	if(*pRaiz == NULL){
		return 0;
	}
	if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita ==NULL){
		return 0;
	}	
	
	int h = altura_Recursiva(&(*pRaiz)->esquerda);
	int g = altura_Recursiva(&(*pRaiz)->direita);
	return (h-g);
	}

int binariaCheia(arvore *pRaiz){
	if(*pRaiz == NULL){
		return 1;
	}
	if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita !=NULL || (*pRaiz)->esquerda != NULL && (*pRaiz)->direita ==NULL ){
		return 0;
	}
	int h = binariaCheia(&(*pRaiz)->esquerda);
	if(h==0){
		return 0;
	}
	int g = binariaCheia(&(*pRaiz)->direita);
	if(g==0){
		return 0;
	}
	return (h==g);
	
}


int maior(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int altura_Recursiva(arvore *pRaiz){
    if(*pRaiz == NULL || ((*pRaiz)->esquerda == NULL && (*pRaiz)->direita == NULL)){
   		return 0;
    }else{
        return 1 + maior(altura_Recursiva(&(*pRaiz)->esquerda),altura_Recursiva(&(*pRaiz)->direita));
    }
}

//VARREDURA EM PRÉ ORDEM
void red(arvore r){
	if(r!=NULL){
	printf("%d\t", r->numero);
	red(r->esquerda);
	red(r->direita);
	}
}

//VARREDURA EM PÓS ORDEM
void edr(arvore r){
	if(r!=NULL){
		edr(r->esquerda);
		edr(r->direita);
		printf("%d\t", r->numero);
	}
}
//VARREDURA EM ORDEM
void erd(arvore r){
	if(r!=NULL){
		erd(r->esquerda);
		printf("%d\t", r->numero);
		erd(r->direita);
		
	}
}


int similar_Esq(arvore r, arvore r2){

	if(r->esquerda == NULL && r2->esquerda!=NULL){
	}
	else if(r->direita == NULL && r2->direita!=NULL){
		return 0;
	}
	else if(r->numero!=r2->numero){
		return 1;
	}
	
	if(r!=NULL && r2!=NULL){
		int h = similar_Esq(r->esquerda,r2->esquerda);
		int g = similar_Esq(r->direita,r2->direita);
		
		return (h!=1 && g!=1);
	}
	
	
	
}
	
	

void similar(arvore *r, arvore *r2){ 
	int h = totalNo_Recursivo(&(*r)->esquerda);
	int c = totalNo_Recursivo(&(*r2)->esquerda);
	if(h==c){
		printf("Ok, Esquerda\n\n");
	}
	h = totalNo_Recursivo(&(*r)->direita);
	c = totalNo_Recursivo(&(*r2)->direita);
	if(h==c){
		printf("Ok, Direita\n\n");
	}
	if(similar_Esq((*r)->esquerda,(*r2)->esquerda)){
		printf("sim\n");
	}
	
}
	
	







/*
int somaArvBin(Coisa **pRaiz){
    if((*pRaiz) == NULL){
        return 0;
    }else{
    	int g = (*pRaiz)->numero;
        Coisa *aux = *pRaiz;
        g+=aux->direita->numero;
        aux = aux->direita;
        while(aux!=NULL){
        	g+=aux->direita->numero;
			aux = aux->direita; 
		}
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
