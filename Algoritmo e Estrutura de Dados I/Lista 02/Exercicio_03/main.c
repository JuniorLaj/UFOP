#include <stdio.h>
#include <stdlib.h>
#include "Exec_03_Nao_Recursivo.c"

int main(){

    Arvore arvore;
    criarArvore(&arvore);
	insercao_Recursiva(&arvore,5);
	insercao_Recursiva(&arvore,8);
	insercao_Recursiva(&arvore,9);
	insercao_Recursiva(&arvore,4);
	insercao_Recursiva(&arvore,3);
	insercao_Recursiva(&arvore,6);
	insercao_Recursiva(&arvore,2);
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
