#include "listaSep.c"

int main(){
	tipoLista l1;
	flvazia(&l1);
	tipoItem x;

	x.tipoChave = 'K';
	insere(&l1,x);
	x.tipoChave = 'L';
	insere(&l1,x);
	x.tipoChave = '3';
	insere(&l1,x);
	x.tipoChave = 'B';
	insere(&l1,x);
	x.tipoChave = '2';
	insere(&l1,x);
	x.tipoChave = '8';
	insere(&l1,x);
	x.tipoChave = '4';
	insere(&l1,x);

	printf("Imprimindo lista 1: ");
	imprime(&l1);
	//printf("\n");
	//retira(&l1,&x,2);
	//imprime(&l1);
	printf("\n\n");

	tipoPilha p1;
	fpvazia(&p1);
	tipoLista l2;
	flvazia(&l2);
	arruma(&l1,&p1,&l2);
	//imprime(&p1);
	printf("\n\n");
		printf("Imprimindo lista 2: ");
	imprime(&l2);

	return 0;

}
