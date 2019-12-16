#include "DequeEstatico.h"

void ffVazio(tipoDeque *deque){
	deque->esquerda = 0;
	deque->direita = 0;
	deque->cont=0;
}

int vazia(tipoDeque deque){
	return(deque.cont==0);
}

void insDir(tipoDeque *deque, tipoItem carta){
	if(deque->cont== MAX){
		printf("Fila cheia!!\n\n");
	} else if(deque->direita==MAX-1 && deque->cont !=MAX){
		printf("Nao e mais possivel inserir pela direita, insira pela esquerda!\n\n");
		} else{


		deque->item[deque->direita]=carta;
			deque->direita ++;
	//	printf("%d\n", deque->item[deque->direita].chave);

		deque->cont++;
	}
}

void remEsq(tipoDeque *deque, tipoItem *carta){
	if(vazia(*deque)){
		printf("Deque vazio!\n\n");
		return;
	} else{

	*carta = deque->item[0];
	int i;
	for(i=0;i<deque->cont-1; i++){
		deque->item[i] = deque->item[i+1];
	}
	deque->direita--;
	deque->cont--;
	}

}




void remDir(tipoDeque *deque, tipoItem *carta){
	if(vazia(*deque)){
		printf("Deque vazio!\n\n");
		return;
	} else{
	*carta= deque->item[deque->direita-1];
	deque->direita--;
	deque->cont--;
	}
}

void insEsq(tipoDeque *deque, tipoItem carta){
	if(deque->cont==MAX){
		printf("Fila cheia!\n\n");
	} else{
		int i;
		for(i=deque->cont; i!=0; i--){
			deque->item[i] = deque->item[i-1];
		}
		deque->item[deque->esquerda]=carta;
		deque->cont++;
		deque->direita++;
		//printf("%s\n",deque->item[deque->esquerda-1]);
	}

}

void imprime(tipoDeque deque){
    if(vazia(deque)){
            printf("Deque vazio!\n\n");
            return;
        } else{
            int i=0;
            while(i!=deque.direita){
            printf("%d\n", deque.item[i].chave);
            i++;

        }

	}
}


