#include "PilhaDeFilas.c"

int main(){

	//CRIANDO UMA NOVA FILA E ADICIONANDO OS ITENS
	tipoFila f1;
	ffVazia(&f1);
	tipoItem x;
	x.chave = 12;
	enfileira(&f1,x);
	x.chave = 65;
	enfileira(&f1,x);
	x.chave = 132;
	enfileira(&f1,x);
	x.chave = 52;
	enfileira(&f1,x);
	//CRIANDO UMA PILHA
	tipoPilha p1;
	fpVazia(&p1);
	tipoItemP k;
	//ADICIONANDO A FILA NA PILHA
	k.fila = f1;
	emPilha(&p1,k);
	//CRIANDO UMA NOVA FILA E ADICIONANDO OS ITENS
	tipoFila f2;
	ffVazia(&f2);
	x.chave = 123;
	enfileira(&f2,x);
	x.chave = 651;
	enfileira(&f2,x);
	x.chave = 12;
	enfileira(&f2,x);
	x.chave = 352;
	enfileira(&f2,x);
	//ADICIONANDO FILA NA PILHA
	k.fila = f2;
	emPilha(&p1,k);
	//IMPRIMINDO A PILHA

	imprimePilha(p1);
	printf("\n\n");

	desemPilha(&p1,&k);
	//FUNÇÃO COM PROBLEMA! ----->>>>>> imprimeFila(k.fila);
	return 0;
}
