#include <stdio.h>
#include <stdlib.h>

struct cel{
	int numero;
	struct cel *esquerda;
	struct cel *direita;
};
typedef struct cel No;
typedef No* arvore;
