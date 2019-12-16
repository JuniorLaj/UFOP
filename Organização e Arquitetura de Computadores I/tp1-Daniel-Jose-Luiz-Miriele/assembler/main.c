#include "Assembler.h"

int main(){
	char nomePrograma[100];
	printf("Digite o nome do arquivo, inclusive sua extensao: ");
	scanf("%s",nomePrograma);
	int tam = lendoPrograma(nomePrograma);
	if(tam==0) return 0;
	primeiroPasso(tam);
	montandoEscrita(tam,nomePrograma);
	
	return 0;
}