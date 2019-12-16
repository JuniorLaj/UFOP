#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void construirArquivos(){
    unsigned long long int h;
    int t;
    FILE *arquivo;
    
    printf("Digite a quantidade de numeros:\n");
    scanf("%d",&h);
    	if(h<=0){
    printf("A quantidade precisa ser maior que zero. Digite novamente.\n");    		
		}
    while(h<=0){
		scanf("%d", &h);
	}

    int vet[h];

    printf("Como deseja ordena-los?\n");
    printf("1 - de forma crescente\n2 - de forma decrescente\n3 - de forma randomica\n4 - Sair da construcao de arquivos\n");
    scanf("%d", &t);
    
    while(t!=4){
        if(t==1){
        int i;
		char s[] = "01_";
		char p[50];
		snprintf(p, 50, "%s%d.dat",s,h);
        arquivo = fopen(p,"a");
        fprintf(arquivo, "%d\n", h);
            for(i=0; i<h; i++){
                vet[i] = i;
                fprintf(arquivo,"%d,",vet[i]);
            }
            printf("\n\n");
            break;
        }
        if(t==2){
            int i;
            char s[] = "02_";
			char p[50];
			snprintf (p, 50, "%s%d.dat",s,h);
        arquivo = fopen(p,"a");
        fprintf(arquivo, "%d\n", h);
            int k=0;
            for(i=h; i>0; i--){
            vet[k] = i;
                fprintf(arquivo,"%d,",vet[k]); 
				k++;           
            }
            printf("\n\n");
            break;
        }
        if(t==3){
            int i;
            char s[] = "03_";
			char p[50];
			snprintf (p, 50, "%s%d.dat",s,h);
        arquivo = fopen(p,"a");
        fprintf(arquivo, "%d\n", h);
            for(i=0; i<h; i++){
            vet[i] = rand()%h;
                fprintf(arquivo,"%d,",vet[i]);         
            }
            
            printf("\n\n");
           break;
        }
        printf("Opcao invalida, digite novamente!\n");
        }
        fclose(arquivo);
        menu();
    }
