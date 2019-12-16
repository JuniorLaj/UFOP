#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {						//STRUCT DO PASSO1 1: IDENTIFICAR TODOS _xxx: -->> LABEL
	char label[100][50];
	char numeroReferencia[200][10];
	int cont;
}Passo1;

typedef struct {						//STRUCT DAS LINHAS DO PROGRAMA
	char cod[800][100];
	int qtCod;
	int numLinha;
}Linha;

void converteBinario(int num, char ret1[]);
int lendoPrograma(char nomeArquivo[]);
void primeiroPasso(int tam);
void auxiliarEscrita(int tam, char leituraRegistradores[], char typeRegister[]);
void montandoEscrita(int tam, char nomeArquivo[]);
