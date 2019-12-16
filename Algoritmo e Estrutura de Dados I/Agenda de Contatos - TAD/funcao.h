#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro{
	int codigo;
	char nome[50];
	char celular[20];
	char email[50];
}Contato;

cadastrar(Contato* c,int a);
listar(Contato* c,int a);
alterar(Contato* c,int a);
excluir(Contato* c,int a);
