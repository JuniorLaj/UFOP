#include "funcoesaux.c"


void analiseComparativa(){

	int m=0; 
	int z;
	unsigned long long int k;
	char r[50];
	char aux[500];
	analiseComparativas a;
	printf("=========Analise Comparativa=========\n\n\n");
	printf("Acessando arquivos...\n\n");
	printf("Digite a ordenacao dos dados que deseja analisar:\n1 - Ordem Crescente\n2 - Ordem Decrescente\n3 - Ordem randomica\n4 - Sair\n");
	scanf("%d",&z);
		while(m!=4){
			if(z==1){
				strcpy(r,"01_");
				break;
			} else if(z==2){
				strcpy(r,"02_");
				break;
			} else if(z==3){
				strcpy(r,"03_");
				break;
			}else if(z==4){
				menu();
				return;
			} 
			else{
			printf("Essa opcao nao existe, digite novamente.\n\n");
			}
		}

	printf("Agora, precisamos saber a quantidade de valores que voce usou para serem ordenados:\n");
	k=0;
	while(m!=4){
		printf("Digite a quantidade:");
		scanf("%d", &k);
		snprintf(aux, 500, "%s%d.dat\0",r,k);
		a.arquivo = fopen(aux,"r");
		if(a.arquivo == NULL){
			printf("Essa quantidade de valores que voce digitou nao se encontra em nossa memoria.\n");
			menu();
			return;
		}
		break;
	}
	fscanf(a.arquivo,"%d",&a.quantVet);
	int i,g,j;
	int b[a.quantVet];
	a.vetor = (int*) malloc(a.quantVet*sizeof(int));
	int vetor[a.quantVet];
	for(i=0; i<a.quantVet; i++){
	fscanf(a.arquivo,"%d,",&a.vetor[i]);
	}
	for(i=0; i<a.quantVet; i++){
		vetor[i] = a.vetor[i];
		b[i] = a.vetor[i];
	}

	while(g!=5){
	printf("Qual algoritmo de ordenacao deseja, para fazer comparacoes?\n");
	printf("1 - Insertion Sort\n2 - Selection Sort\n3 - Shell Sort\n4 - Quick Sort\n5 - Sair\n");
	scanf("%d", &g);
	FILE *result;
	
	char comb[50];
	if(g==1){
		int i, j;
		//Insertion Sort
		snprintf(comb, 50, "%s_Teste_InsertionSort.dat\0",aux);
		result = fopen(comb,"a");
		for(i=0; i<1; i++){
		a.numTrocas = 0;
		a.numComparacoes = 0;		
		double m = insertionSort(&a);
		if(i<10){	
		fprintf(result,"Teste:%d \tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,a.numTrocas,a.numComparacoes,m);
	}	else{
		fprintf(result,"Teste:%d\tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,a.numTrocas,a.numComparacoes,m);
	}
		a.numTrocas = 0;
		a.numComparacoes = 0;
		for(j=0; j<a.quantVet; j++){
		a.vetor[j] = vetor[j];
		
		}
	}
		fclose(result);

		break;
	} else if(g==2){
		//Selection Sort
		snprintf(comb, 50, "%s_Teste_SelectiontionSort.dat\0",aux);
		result = fopen(comb,"a");
		for(i=0; i<33; i++){
		a.numTrocas = 0;
		a.numComparacoes = 0;		
		double m = selectionSort(&a);
		if(i<10){	
		fprintf(result,"Teste:%d \tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,a.numTrocas,a.numComparacoes,m);
	}	else{
		fprintf(result,"Teste:%d\tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,a.numTrocas,a.numComparacoes,m);
	}
		a.numTrocas = 0;
		a.numComparacoes = 0;
		for(j=0; j<a.quantVet; j++){
		a.vetor[j] = vetor[j];
		}
	}
		fclose(result);

		break;
	} else if(g==3){
		//Shell Sort
		snprintf(comb, 50, "%s_Teste_ShellSort.dat\0",aux);
		result = fopen(comb,"a");
		for(i=0; i<33; i++){
		a.numTrocas = 0;
		a.numComparacoes = 0;		
		double m = shellSort(&a);
		if(i<10){	
		fprintf(result,"Teste:%d \tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,a.numTrocas,a.numComparacoes,m);
	}	else{
		fprintf(result,"Teste:%d\tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,a.numTrocas,a.numComparacoes,m);
	}
		a.numTrocas = 0;
		a.numComparacoes = 0;
		for(j=0; j<a.quantVet; j++){
		a.vetor[j] = vetor[j];
		}
	}
		fclose(result);
		break;
	} else if(g==4){
		//Quick Sort
		snprintf(comb, 50, "%s_Teste_QuickSort.dat\0",aux);
		result = fopen(comb,"a");	
		int vetorAux[a.quantVet];
		for(i=0; i<33; i++){
		for(j=0; j<a.quantVet; j++){
		vetorAux[j] = b[j];
		}
		int p = a.quantVet-1;
		double e;
		long int o=0;
		long int u=0;
		clock_t Ticks[2];
		Ticks[0] = (double) clock();
		quickSort(vetorAux,0,p,&o,&u);
		Ticks[1] = (double) clock();
		e = (Ticks[1] - Ticks[0])*1000/CLOCKS_PER_SEC;
		if(i<10){	
		fprintf(result,"Teste:%d \tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,o,u,e);
		}else{
		fprintf(result,"Teste:%d\tNumTrocas: %d\tNumComparacoes:%d\tTempo Gasto:%lfms\n",i+1,o,u,e);
			}
		}
		printf("\n\n");
		fclose(result);

		break;
	} else if(g==5){
		break;
	}
		else{
		printf("Opcao nao existente. Tente novamente.\n");
		}
	}
	fclose(a.arquivo);
	
	printf("\n\n");
	menu();
}



