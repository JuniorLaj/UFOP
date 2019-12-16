#include <stdio.h>
#include "DequeEstatico.c"

int main(){
	//ADICIONANDO ITENS NO DEQUE
    tipoDeque d1;
    ffVazio(&d1);
	tipoItem cd;
	cd.chave = 5;
	insDir(&d1, cd);
	cd.chave = 8;
	insDir(&d1, cd);
   	cd.chave =32;
	insDir(&d1, cd);
	cd.chave = 112;
	insDir(&d1, cd);
	cd.chave = 15;
	insDir(&d1, cd);
	insEsq(&d1, cd);
	//IMPRIMINDO REMOVENDO E IMPRIMINDO NOVAMENTE
	printf("Imprimindo deque:\n");
	 imprime(d1);
	 printf("\n\n");
	remDir(&d1, &cd);
	 printf("\n\n");
		printf("Imprimindo deque:\n");
		 imprime(d1);

	return 0;
}
