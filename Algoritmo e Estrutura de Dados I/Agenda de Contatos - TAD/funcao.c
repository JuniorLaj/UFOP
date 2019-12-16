#include "funcao.h"


void cadastrar(Contato contato[], int t){
int p;
	printf("Digite seu nome: ");
	getchar();
	scanf(" %[^\n]s", contato[t].nome);
	getchar();
	printf("Digite seu celular:");
	scanf(" %[^\n]s",contato[t].celular);
	printf("Digite seu email:");
	getchar();
	scanf(" %[^\n]s",contato[t].email);
	getchar();
	printf("Digite um ID pra voce: (SOMENTE NUMEROS): ");
	scanf("%d", &contato[t].codigo);

	int k;
	for(k=0; k<t; k++){
		if(contato[t].codigo==contato[k].codigo){
			printf("Esse id ja existe, digite um ID novo: ");
			scanf("%d", &contato[t].codigo);

		}
	}
	printf("Cadastro realizado com sucesso!\n\n\n");

}
void listar(Contato contato[], int t){
	int i, b;
	int k;
	for(i=0; i<t; i++){
        if(contato[i].codigo == 999999){
        continue;
        } else{
		printf("Nome:%s\t\tCodigo: %d\n", contato[i].nome, contato[i].codigo);
	}
}
	printf("\n\n\n\n");
	printf("Digite o codigo do contato que deseja acessar: ");
	scanf("%d", &b);
	for(k=0; k<t; k++){
		 if(contato[k].codigo==b){
		printf("Codigo:%d\n",contato[k].codigo);
		printf("Nome:%s\n", contato[k].nome);
		printf("Celular:%s\n", contato[k].celular);
		printf("E-mail:%s\n", contato[k].email);
		printf("\n\n\n\n\n");
		break;
			} else {
            printf("Codigo de contato inexistente, volte ao menu do programa!\n\n");
		}
	}
	}

void alterar(Contato contato[],int t ){
int n, c;
int k;
	char contatoi[3][20];
    printf("Digite o codigo do seu contato: ");
    scanf("%d", &n);
    for(c=0; c<t; c++){
    	if(contato[c].codigo!=999999){
    		if(contato[c].codigo==n){

        printf("Digite o novo nome: ");
        scanf("%s", &contatoi[0]);
        printf("Digite o novo email: ");
        scanf("%s", &contatoi[1]);
        printf("Digite o novo celular: ");
        scanf("%s", &contatoi[2]);
        printf("Digite seu novo ID: ");
        scanf("%d", &contato[c].codigo);
    		strcpy(contato[c].nome,contatoi[0]);
            strcpy(contato[c].celular,contatoi[1]);
            strcpy(contato[c].email,contatoi[2]);

    printf("Altercoes realizadas com sucesso!\n\n");
    printf("Codigo: %d\n",contato[c].codigo);
	printf("Nome: %s\n", contato[c].nome);
	printf("Celular: %s\n", contato[c].celular);
	printf("E-mail: %s\n\n\n", contato[c].email);
}
	} else {
		printf("Codigo inexistente, liste os contatos e escolha o codigo correspondente.\n\n\n");
	}
}
}

    void excluir(Contato *contato, int t){

        int a = t;
        int q, z, p;
        printf("Digite o codigo do contato que deseja excluir: ");
        scanf("%d", &z);
        for(q=0; q<a; q++){
            if(contato[q].codigo==z){
        printf("Codigo: %d\tNome: %s\n", contato[q].codigo, contato[q].nome);
        printf("Tem certeza que deseja excluir? Sim-> 1\tNao-> 0");
        scanf("%d", &p);
        if(p==1){
        	contato[q].codigo = 999999;
        printf("Contato excluido com sucesso!\n\n\n");
        break;
        }
	}
	}
	printf("Codigo inexistente, liste os contatos e digite o codigo correspondente.\n\n\n");

}
