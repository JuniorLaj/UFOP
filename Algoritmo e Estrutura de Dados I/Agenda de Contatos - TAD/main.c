#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcao.c"

int main(){

	Contato *contatos;

	contatos = (Contato*) malloc(1*sizeof(Contato));
	int n, i;
	int a=0;

	printf("\t\tAgenda eletronica!\n\n");

	int k, z=1, l;
	for(k=0; k<z; z++){

	printf("O que voce deseja fazer? Para entrar em uma determinada funcao, digite o valor correspondente:\n");
	printf("Cadastro: 1\nListar contatos e pesquisar um contato: 2\nAlterar um contato: 3\nExcluir um contato: 4\nSair do programa: 5\n");
	scanf("%d", &n);
    if(n==1){
		cadastrar(contatos,a);
		a++;
		contatos = realloc (contatos, (a+1)* sizeof (Contato));
		} else if(n==2){
		listar(*contatos,a);
		} else if(n==3){
        alterar(*contatos,a);
		} else if(n==4){
		excluir(*contatos, a);
		}
		else if(n==5){
		free(contatos);
		break;
        }

	}

	return 0;
}

