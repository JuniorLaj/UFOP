#include "FilaDePilhas.c"


int main(){
	//CRIANDO UMA PILHA E ADICIONANDO ITENS NELA
	tipoPilha p1;
	fpVazia(&p1);
	tipoItem x;
	x.chave = 125;
	emPilha(&p1, x);
	x.chave = 235;
	emPilha(&p1, x);
	x.chave = 233;
	emPilha(&p1, x);
	//CRIANDO UMA PILHA E ADICIONANDO ITENS NELA
	tipoPilha p2;
	fpVazia(&p2);
	x.chave = 115;
	emPilha(&p2, x);
	x.chave = 2123;
	emPilha(&p2, x);
	x.chave = 2;
	emPilha(&p2, x);
	//CRIANDO UMA FILA E ADICIONANDO PILHAS NELA
	tipoFila f1;
    ffVazia(&f1);
	tipoItemP p;
	p.pilha = p1;
    enfileira(&f1,p);
    p.pilha = p2;
    enfileira(&f1,p);

    imprimeFila(&f1);
    printf("\n\n");
    tipoItemP p3;
	//desenfileira(&f1,&p3);
    //imprimePilha(p3.pilha);
    printf("\n\n");
	//imprimeFila(&f1);


	return 0;
}
