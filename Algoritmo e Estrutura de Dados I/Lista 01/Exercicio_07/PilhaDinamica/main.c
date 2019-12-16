#include "PilhaDinamica.c"

int main(){


	tipoPilha p1;
	tipoPilha p2;
	tipoPilha p3;
	tipoPilha p4;
	tipoPilha p5;
	fpvazia(&p1);
	fpvazia(&p2);
	fpvazia(&p3);
	fpvazia(&p4);
	fpvazia(&p5);
	tipoItem x;
	x.chave = 32;
	emPilha(&p1,x);
	x.chave = 31;
	emPilha(&p1,x);
	x.chave = 30;
	emPilha(&p1,x);
	x.chave = 28;
	emPilha(&p1,x);
	x.chave = 36;
	emPilha(&p2,x);



	//imprimePilha(&p1);
	//verificaA(p1,6);
	printf("\n\n");
	copiaB(&p1,&p2);
		x.chave = 27;
	emPilha(&p1,x);
	x.chave = 26;
	emPilha(&p1,x);
	x.chave = 25;
	emPilha(&p2,x);

	//imprimePilha(&p2);
	//concatenaD(&p1,&p2);
		printf("\n\n\n");
	imprimePilha(&p1);
	printf("\n\n\n");
	//intercalaE(&p1,&p2,&p3);
	//imprimePilha(&p3);
	//printf("\n\n\n");
	//intercessaoF(&p1,&p2,&p4);
	//imprimePilha(&p4);
	diferencaG(&p1,&p2,&p5);
	//imprimePilha(&p5);
	verificaordemH(p1);
	return 0;
}
