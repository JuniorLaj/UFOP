#include "construcaoArquivos.c"
#include "analiseComparativa.c"

void menu(){
    int h=0;	
    printf("==========MENU==========\n");
    printf("Escolha uma das opcoes:\n1 - Construcao de arquivos\n2 - Analise Comparativa\n");
    printf("3 - Sair\n");
    scanf("%d", &h);
    if(h!=3){
		if(h==1){
        construirArquivos();
     	}else if(h==2){
        analiseComparativa();
		}else{
        printf("Essa opcao nao existe. Digite novamente.\n\n");	
		menu();		
		}
    }	
}


int main(){
    printf("Seja bem vindo\nTrabalho pratico - AEDS I\n\n");
    menu();

    return 0;
}


