#include "FilaDeFilas.c"

int main(){
	//CRIANDO UMA NOVA FILA E ADICIONANDO ITENS NELA
	tipoFila f1;
	ffVazia(&f1);

	tipoItem x;
	x.chave = 41;
	enfileira(&f1,x);
	x.chave = 551;
	enfileira(&f1,x);
	x.chave = 31;
	enfileira(&f1,x);
	x.chave = 12;
	enfileira(&f1,x);
	//CRIANDO UMA NOVA FILA E ADICIONANDO ITENS NELA
	tipoFila f2;
	ffVazia(&f2);
	x.chave = 11;
	enfileira(&f2,x);
	x.chave = 51;
	enfileira(&f2,x);
	x.chave = 131;
	enfileira(&f2,x);
	x.chave = 123;
	enfileira(&f2,x);
	//CRIANDO NOVA FILA E ADICIONANDO FILAS NELA
	tipoItemP k;
	tipoFila f3;
	ffVaziaP(&f3);
	k.fila = f1;
	enfileiraP(&f3,k);
	k.fila = f2;
	enfileiraP(&f3,k);
	printf("\n");
	imprimeFilaP(&f3);

	//printf("\n\n");
	//tipoItemP h;
	//desenfileiraP(&f3, &h);
	//imprimeFila(h.fila);
	//printf("\n\n");
	//imprimeFilaP(&f3);
	return 0;
}
