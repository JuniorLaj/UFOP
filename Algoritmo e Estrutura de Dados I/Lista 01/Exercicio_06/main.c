#include "ListaDinamica.c"

int main(){

	tipoLista l1;
	flVazia(&l1);
	tipoLista l2;
	flVazia(&l2);
	tipoLista l3;
	flVazia(&l3);
	//imprimeLista(&l1);
	tipoItem x;
	x.chave = 14;
	insereLista(&l1,x);
	x.chave = 44;
	insereLista(&l1,x);
	x.chave = 56;
	insereLista(&l1,x);
	x.chave = 23;
	insereLista(&l1,x);
	imprimeLista(&l1);

	printf("Nova Lista!\n\n");
	novaListaA(&l1,&l2);
	imprimeLista(&l2);
	printf("Nova Lista!\n\n");
	novaListaB(&l1,&l3);
	imprimeLista(&l3);

	printf("\n\n\n\n");
	tipoLista l4;
	flVazia(&l4);
	printf("Nova Lista!\n\n");
	novaListaC(&l1,&l4);
	imprimeLista(&l4);

	return 0;
}

