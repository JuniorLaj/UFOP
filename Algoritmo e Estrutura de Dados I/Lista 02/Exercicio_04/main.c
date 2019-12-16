#include <stdio.h>
#include <stdlib.h>
#include "Exercicio_04.c"


int main(){
	arvore arvore2;
    arvore arvore1;
    
	insercao(&arvore1,6);
	insercao(&arvore1,8);
	insercao(&arvore1,9);
	insercao(&arvore1,7);
	insercao(&arvore1,4);
	insercao(&arvore1,3);
	insercao(&arvore1,5);
//	insercao(&arvore1,10);

	//insercao(&arvore,1);
	int m = totalNo_Recursivo(&arvore1);
	printf("Total de itens na arvore: %d\n", m);
/*
	int g = altura_Recursiva(&arvore1);
	printf("Altura: %d\n",g);

	int c = estritamente(arvore1);
		if(c==0){
		printf("%d\tEstritamente Binaria!\n\n", c);
	}
/*
	int p = binariaCompleta(&arvore1);
	if(p==1 || p==-1 || p==0){
		printf("%d\t Binaria Completa!\n\n",p);
	}
	
	int t = binariaCheia(&arvore1);
	if(t){
		printf("%d\tBinaria Cheia!\n\n\n", t);
	}
	
	red(arvore1);
	printf("\n\n");
	edr(arvore1);
	*/

    return 0;
}

