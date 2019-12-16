#include "ListaDinamica.c"

int main(){
	tipoLista l1;
	tipoLista l2;
	tipoLista l3;
	tipoLista l4;
	tipoLista l5;
		tipoLista l8;
	flvazia(&l1);
	flvazia(&l2);
	flvazia(&l3);
	flvazia(&l4);
	flvazia(&l5);
		flvazia(&l8);
	//INSERINDO ORDENADO E IMPRIMINDO
	printf("INSERINDO ORDENADO E IMPRIMINDO:\n");
	tipoItem x;
	x.chave = 15;
	insereOrdB(&l1, x);
	x.chave = 4;
	insereOrdB(&l1, x);
	x.chave = 12;
	insereOrdB(&l1, x);
	imprimeLista(&l1);
	printf("\n\n");
	tipoItem k;
	//retiraLista(&l1, &k, 1);
	//printf("%d\n", k.chave);
	//imprimeLista(&l1);
	//VERIFICANDO SE O ITEM PERTENCE A TAD
	printf("VERIFICANDO SE O ITEM PERTENCE A TAD\n");
	verificaA(l1, 8);
//	x.chave = 10;
//	insereOrdB(&l1, x);
//CRIANDO NOVA LISTA
	x.chave = 5;
	insereOrdB(&l2, x);
	x.chave = 6;
	insereOrdB(&l2, x);
	x.chave = 7;
	insereOrdB(&l2, x);
	x.chave = 4;
	insereOrdB(&l2, x);
	x.chave = 9;
	insereOrdB(&l2, x);
	printf("IMPRIMINDO NOVA LISTA\n");
	imprimeLista(&l2);
	printf("\n\n");
//	imprimeLista(&l1);
//	printf("\n\n");
	printf("COPIANDO ITENS DE UMA TAD 1 PARA UMA TAD 2\n");
	copiaC(&l1,&l8);
	imprimeLista(&l8);
	printf("CONCATENANDO TAD 1 NUMA TAD 2\n");
	concatenaD(&l1,&l2);
	imprimeLista(&l1);
	printf("INTERCALANDO TAD 1 E TAD 2 NUMA TAD 3\n");
	intercalaE(&l1,&l2,&l3);
	imprimeLista(&l3);
	printf("FAZENDO INTERSEÇÃO TAD 1 E TAD 2 NUMA TAD 3\n");
	intercedeF(&l1,&l2,&l4);
	imprimeLista(&l4);
	printf("FAZENDO DIFERENCA TAD 1 E TAD 2 NUMA TAD 3\n");
	diferencaG(&l1,&l2,&l5);
	imprimeLista(&l5);
	printf("VERIFICANDO ORDEM DE UMA TAD: ");
	verificaOrdenaH(l2);
	printf("MESCLANDO TAD 1 EM TAD 2 E ORDENANDO\n");
	mesclaI(&l1,&l2);

	return 0;
}
