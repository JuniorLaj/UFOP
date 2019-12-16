#include "FilaDinamica.c"

int main(){

	tipoFila f1;
	ffvazia(&f1);
	tipoFila f2;
	ffvazia(&f2);
	tipoFila f3;
	ffvazia(&f3);
	tipoFila f4;
	ffvazia(&f4);
	tipoFila f5;
	ffvazia(&f5);
	tipoItem x;
	x.chave = 42;
	enfileira(&f1,x);
	x.chave = 43;
	enfileira(&f1,x);
	x.chave = 44;
	enfileira(&f1,x);
	x.chave = 167;
	enfileira(&f1,x);
	x.chave = 46;
	enfileira(&f1,x);
	x.chave = 47;
	enfileira(&f1,x);
	//desenfileira(&f1, &x);
	//printf("%d\n\n", x.chave);
	//verificaA(&f1,38);
	imprimeFila(&f1);
	printf("\n\n");
	x.chave = 13;
	enfileira(&f2,x);
	x.chave = 16;
	enfileira(&f2,x);
	x.chave = 167;
	enfileira(&f2,x);
	x.chave = 12;
	enfileira(&f2,x);
	x.chave = 14;
	enfileira(&f2,x);
	//copiaC(&f1,&f2);
	imprimeFila(&f2);
	printf("\n\n");
	//concatenaD(&f1,&f2);
	//intercalaE(&f1,&f2,&f3);
	//imprimeFila(&f3);
	printf("\n\n");
	intersecaoF(&f1,&f2,&f4);
	imprimeFila(&f4);
	printf("\n\n");
	diferencaG(&f1,&f2,&f5);
	imprimeFila(&f5);
	printf("\n\n");
	verificaOrdenaH(&f1);
	return 0;
}
