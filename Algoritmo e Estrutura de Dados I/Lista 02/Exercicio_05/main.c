#include "Exercicio_05.c"
int main(){

	arvore av2;
	arvore av1;
	criarArvore(&av1);
	criarArvore(&av2);
	insercao(&av1,5);
	insercao(&av1,2);
	insercao(&av1,8);
	insercao(&av1,9);
	insercao(&av1,7);
	insercao(&av1,1);
	insercao(&av1,3);
	insercao(&av1,4);
	//insercao(&av1,18);
	erd(av1);
	printf("\n\n");
	insercao(&av2,5);
	insercao(&av2,2);
	insercao(&av2,8);
	insercao(&av2,9);
	insercao(&av2,7);
	insercao(&av2,1);
	insercao(&av2,3);
	//insercao(&av2,18);
	erd(av2);
	printf("\n\n");
	
	similar(&av1,&av2);
	
		
	
	
		
	
	return 0;
}
