#include "Assembler.h"

Linha *l;								
Passo1 *p;										

void converteBinario(int num, char ret1[]){
	if(num==0){										//CASO O num SEJA 0, SEU BINÁRIO TBM SERÁ 0
		strcpy(ret1,"000000000");
		return;
	}
	int moduloNum = num;
	if(num<0){
		moduloNum = num*(-1);
	}
	int i =0;
	int c=0;
	int j=0;
	char p[50];
	while(1){
		char z = '0'+moduloNum%2;
		p[c] = z;
		moduloNum = moduloNum/2;
		c++;
		if(moduloNum==1 || moduloNum==0){
			char k = '0'+moduloNum;
			p[c] = k; 
			c++;
			break;
		}	
	}
	p[c] = '\0';
	char ret[c];
	for(i=c-1; i>=0; i--, j++){
		ret[j] = p[i];
		if(i==0){
			ret[j+1] = '\0';
		}
	}

	if(strlen(ret)>8){									//CASO O NUMERO TENHA MAIS DE 8 BITS, ELE NÃO PRECISA SER -->>
		strcpy(ret1,ret);								//-->>COMPLETADO COM ZEROS
		return;
	}

	char aux[15];
	switch (strlen(ret)){								//COMPLETANDO COM ZEROS A STRING ATÉ DAR 9 BITS

		case 2:
		strcpy(aux,"0000000");
		strcat(aux,ret);
		break;
		
		case 3:
		strcpy(aux,"000000");
		strcat(aux,ret);
		break;

		case 4:
		strcpy(aux,"00000");
		strcat(aux,ret);
		break;

		case 5:
		strcpy(aux,"0000");
		strcat(aux,ret);
		break;

		case 6:
		strcpy(aux,"000");
		strcat(aux,ret);
		break;

		case 7:
		strcpy(aux,"00");
		strcat(aux,ret);
		break;

		case 8:
		strcpy(aux,"0");
		strcat(aux,ret);
		break;

		defaut:
			printf("Error\n\n");
			return;
	}
	if(num<0){											//CASO O NÚMERO SEJA NEGATIVO, FAZER COMPLEMENTO DE 2
		for(int i=0; i<strlen(aux); i++){
			if(aux[i]=='0'){
				aux[i] = '1';
			}else {
				aux[i] = '0';
			}
		}
		for(int i=strlen(aux); i>0; i--){
			if(aux[i]=='0'){
				aux[i] = '1';
				i = 0;
			}
		}
	}
	strcpy(ret1,aux);
}

int lendoPrograma(char nomeArquivo[]){
	FILE *arq;
	arq = fopen(nomeArquivo, "r");				//ABRINDO O ARQUIVO					
	if(arq==NULL){
		printf("Arquivo nulo\n");
		return 0;
	}

	int qtdeLinhas=0;							//QUANTIDADE DE LINHAS DO .ASSEMBLY
	int qtdeInstrucoes = 0;						//QUANTIDADE DE INSTRUÇÕES EM DETERMINADA LINHA
	int qtCaracteres=0;							//QUANTIDADE DE CARACTERES EM DETERMINADA INSTRUÇÃO
	int contLinhas =0;							//CONTADOR DE LINHAS AUXILIAR							
		
	l = (Linha*) malloc(1*sizeof(Linha));		//ALOCANDO UMA POSIÇÃO PARA 'l' (VARIÁVEL GLOBAL)

	while(!feof(arq)){							//LENDO O ARQUIVO ENQUANTO TIVER O QUE LER
		char aux;
		fscanf(arq,"%c", &aux);
		if(aux==';' || aux=='\n'){					//CASO LEIA '\n' OU ';', AS INFORMAÇÕES DA LINHA TERMINARAM. 
			if(aux==';'){							//CASO LEIA ';', QUER DIZER QUE A INSTRUÇÃO DAQUELA LINHA TERMINOU
			while(aux!=10) fscanf(arq,"%c", &aux);	//LEIO TODOS OS COMENTÁRIOS DEPOIS DE ';' (E NÃO OS ARMAZENO), -->>
			}										//ATÉ CHEGAR A PRÓXIMA LINHA (aux!=10)
			l[qtdeLinhas].numLinha = contLinhas; 	//ARMAZENANDO EM l.numLinha O NÚMERO DA LINHA(CASO PRECISE USAR PARA MANIPULAÇÕES)
			contLinhas++;
			l[qtdeLinhas].qtCod = qtdeInstrucoes;		//ARMAZENANDO EM l.qtCod A QUANTIDADE DE INSTRUÇÃO POR LINHA DO CÓDIGO		
			if(feof(arq)){								//CONFERINDO SE O ARQUIVO ACABOU, CASO O ARQUIVO TENHA ACABADO,-->>
				break;									//-->> DEIXA DE REALOCAR UM ESPAÇO NA MEMÓRIA QUE NÃO VAI SER UTILIZADO
			}
			qtdeLinhas++;
			l = (Linha*) realloc(l,(qtdeLinhas+1)*sizeof(Linha));	//ALOCANDO ESPAÇO PARA MAIS UMA LINHA DO PROGRAMA
			qtdeInstrucoes=0;										//ZERANDO O CONTADOR DE INSTRUÇÃO, PRA CONTAR NA NOVA LINHA
			qtCaracteres=0;		
			continue;

		}else{

			if(aux!=' '&& aux!='\t'){									//SE A LEITURA DO CARACTER FOR DIFERENTE DE 'espaço' ou '\t',
				l[qtdeLinhas].cod[qtdeInstrucoes][qtCaracteres] = aux;	//-->  eu armazeno.
				qtCaracteres++;
				while(1){												//LOOP PARA LER UMA INSTRUÇÃO DE UMA LINHA
					char aux2;	
					fscanf(arq,"%c", &aux2);
					if(aux2==' ' && aux!='\t'){							//PARO DE LER A INSTRUÇÃO DA LINHA QUANDO ENCONTRAR UM ESPAÇO
						qtdeInstrucoes++;								//QUANDO ISSO ACONTECE, MINHA QUANTIDADE DE INSTRUÇÕES AUMENTA
						qtCaracteres=0;
						break;
					}else{
						l[qtdeLinhas].cod[qtdeInstrucoes][qtCaracteres] = aux2;			//ADICIONO O CARACTERE NA DEVIDA POSIÇÃO
						qtCaracteres++;													//AUMENTO A QUANTIDADE DE CARACTERES
					}
				}
			}
		}
		
	}

	for(int g=0; g<qtdeLinhas; g++){
		for(int k=0; k<l[g].qtCod; k++){
			//printf("%s\t",l[g].cod[k]);									//PRINTANDO O CÓDIGO ASSEMBLY
		}
		//printf("\n");
	}
	
	return qtdeLinhas;													//RETORNA A QUANTIDADE DE LINHAS DO PROGRAMA
}

void primeiroPasso(int tam){
	p = (Passo1*) malloc(1*sizeof(Passo1));							//ALOCO UMA ESTRUTURA DO PASSO1
	for(int w=0; w<tam; w++){										
		int c = strlen(l[w].cod[0])-1;
		if(l[w].cod[0][0] == '_' && l[w].cod[0][c] ==':'){			//SE ESSA CONDIÇÃO EXISTIR, QUER DIZER QUE MINHA INSTRUÇÃO-->
			strcpy(p->label[p->cont],l[w].cod[0]);					//--> É UM LABEL, ENTÃO ARMAZENO ELE, FAZENDO ASSIM O PRIMEIRO PASSO
			p->label[p->cont][c] = '\0';
			converteBinario((w*2),p->numeroReferencia[p->cont]);	//CONVERTENDO PRA BINÁRIO A LINHA DO LABEL VEZES 2, ASSIM TENDO-->						//-->SUA DEVIDA REFERÊNCIA PARA FUTURAMENTE USAR
			p->cont++;
		}
	}
	for(int z=0; z<p->cont; z++){
		//printf("%s\t%s\n",p->label[z],p->numeroReferencia[z]);	//PRINTANDO TODOS OS LABELS, JUNTO COM SUAS REFERÊNCIAS		
	}
}

void auxiliarEscrita(int tam, char leituraRegistradores[], char typeRegister[]){
	for(int i=0; i<tam-1; i++){
		leituraRegistradores[i] = '0';
	}
	if(strcmp("A0",typeRegister)==0){
		leituraRegistradores[tam-1] = '0';
	} else if(strcmp("A1",typeRegister)==0){
		leituraRegistradores[tam-1] = '1';
	} else if(strcmp("A2",typeRegister)==0){
		leituraRegistradores[tam-2] = '1';
		leituraRegistradores[tam-1] = '0';
	} else if(strcmp("A3",typeRegister)==0){
		leituraRegistradores[tam-2] = '1';
		leituraRegistradores[tam-1] = '1';
	}
	leituraRegistradores[tam] = '\0';
}

void montandoEscrita(int tam, char nomeArquivo[]){
	char PosLeitura[65][20];
	int contLei =0;
	for(int z=0; z<tam; z++){
			int i=0;
			if(l[z].cod[0][0] == '_') i=1;

			//@@@@CONJUNTO DE INSTRUÇÕES QUE -->> NÃO PRECISAM --<< DE ENDEREÇO DE MEMÓRIA@@@@@@@
			if(strcmp(l[z].cod[i],"read")==0){							//"read" Reg1
				strcpy(PosLeitura[contLei],"00011");
				char auxiliarLeitura[15];
				auxiliarEscrita(11,auxiliarLeitura,l[z].cod[i+1]);
				strcat(PosLeitura[contLei],auxiliarLeitura);

				contLei++;
				continue;

			} else if(strcmp(l[z].cod[i],"write")==0){ 			//"write" Reg1 
					strcpy(PosLeitura[contLei], "00100");
					char auxiliarLeitura[15];
					auxiliarEscrita(11,auxiliarLeitura,l[z].cod[i+1]);
					strcat(PosLeitura[contLei],auxiliarLeitura);

					contLei++;
					continue;

				} else if(strcmp(l[z].cod[i],"add")==0){			//"add" Reg1 Reg2
					strcpy(PosLeitura[contLei], "00101");
					char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg 1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					char auxiliarLeitura2[15];
					auxiliarEscrita(9,auxiliarLeitura2,l[z].cod[i+2]);		//DECIDINDO Reg 2
					strcat(PosLeitura[contLei],auxiliarLeitura2);

					contLei++;
					continue;

				} else if(strcmp(l[z].cod[i],"subtract")==0){				//"subtract" Reg 1 Reg2
					strcpy(PosLeitura[contLei], "00110");
					char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]); 		//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					char auxiliarLeitura2[15];
					auxiliarEscrita(9,auxiliarLeitura2,l[z].cod[i+2]);		//DECIDINDO Reg2
					strcat(PosLeitura[contLei],auxiliarLeitura2);

					contLei++;
					continue;

				} else if(strcmp(l[z].cod[i],"multiply")==0){				//"multiply" Reg1 Reg2
					strcpy(PosLeitura[contLei], "00111");
					char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg 1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					char auxiliarLeitura2[15];
					auxiliarEscrita(9,auxiliarLeitura2,l[z].cod[i+2]);		//DECIDINDO Reg 2
					strcat(PosLeitura[contLei],auxiliarLeitura2);

					contLei++;
					continue;

				} else if(strcmp(l[z].cod[i],"divide")==0){					//"divide" Reg1 Reg2
					strcpy(PosLeitura[contLei],"01000");
					char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					char auxiliarLeitura2[15];
					auxiliarEscrita(9,auxiliarLeitura2,l[z].cod[i+2]);		//DECIDINDO Reg2
					strcat(PosLeitura[contLei],auxiliarLeitura2);

					contLei++;
					continue;

				} else if(strcmp(l[z].cod[i],"move")==0){					//"move" Reg1 Reg2
					strcpy(PosLeitura[contLei],"01100");
					char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					char auxiliarLeitura2[15];
					auxiliarEscrita(9,auxiliarLeitura2,l[z].cod[i+2]);		//DECIDINDO Reg2
					strcat(PosLeitura[contLei],auxiliarLeitura2);

					contLei++;
					continue;

				} else if(strcmp(l[z].cod[i],"push")==0){					//"push" Reg1 
					strcpy(PosLeitura[contLei],"01101");
					char auxiliarLeitura[15];
					auxiliarEscrita(11,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);
	
					contLei++;
					continue;

				} else if(strcmp(l[z].cod[i],"pop")==0){					//"pop" Reg1 
					strcpy(PosLeitura[contLei],"01110");
					char auxiliarLeitura[15];
					auxiliarEscrita(11,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					contLei++;
					continue;

				}  else if(strcmp(l[z].cod[i],"copytop")==0){				//"copytop" Reg1 
					strcpy(PosLeitura[contLei],"10110");
					char auxiliarLeitura[15];
					auxiliarEscrita(11,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					contLei++;
					continue;

				 //@@@@CONJUNTO DE INSTRUÇÕES QUE -->> PRECISAM --<< DE ENDEREÇO DE MEMÓRIA@@@@@@@

				 } else if(strcmp(l[z].cod[i],"load")==0){					//"load" Reg 1 >>Endereço<< 
				  	strcpy(PosLeitura[contLei],"00001");
				  	char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);		//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);
				

					for(int t=0; t<p->cont; t++){
						if(strcmp(l[z].cod[i+2],p->label[t])==0){
							strcat(PosLeitura[contLei],p->numeroReferencia[t]);		//DECIDINDO >>Endereço<<
							t = p->cont;
						}
					}
					contLei++;
					continue;
	
				} else if(strcmp(l[z].cod[i],"store")==0){							//"store" Reg 1 >>Endereço<< 
				  	strcpy(PosLeitura[contLei],"01001");
					char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);				//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					for(int t=0; t<p->cont; t++){
						if(strcmp(l[z].cod[i+2],p->label[t])==0){
							strcat(PosLeitura[contLei],p->numeroReferencia[t]);		//DECIDINDO >>Endereço<<
							t = p->cont;
						}
					}
					contLei++;
					continue; 

				} else if(strcmp(l[z].cod[i],"jump")==0){							//"jump" >>Endereço<< 
				  	strcpy(PosLeitura[contLei],"0100100");

				  	for(int t=0; t<p->cont; t++){
						if(strcmp(l[z].cod[i+1],p->label[t])==0){
							strcat(PosLeitura[contLei],p->numeroReferencia[t]);		//DECIDINDO >>Endereço<<
							t = p->cont;
						}
					}
					contLei++;
					continue; 
				
				} else if(strcmp(l[z].cod[i],"jmpz")==0){							//"jmpz" Reg 1 >>Endereço<< 
				  	strcpy(PosLeitura[contLei],"01010");
					char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);				//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

				  	for(int t=0; t<p->cont; t++){
						if(strcmp(l[z].cod[i+2],p->label[t])==0){
							strcat(PosLeitura[contLei],p->numeroReferencia[t]);		//DECIDINDO >>Endereço<<
							t = p->cont;
						}
					}
					contLei++;
					continue; 

				} else if(strcmp(l[z].cod[i],"jmpn")==0){								//"jmpn" Reg 1 >>Endereço<< 
				  	strcpy(PosLeitura[contLei],"01011");
				 	char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);					//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

				  	for(int t=0; t<p->cont; t++){
						if(strcmp(l[z].cod[i+2],p->label[t])==0){
							strcat(PosLeitura[contLei],p->numeroReferencia[t]);			//DECIDINDO >>Endereço<<
							t = p->cont;
						}
					}
					contLei++;
					continue; 

				} else if(strcmp(l[z].cod[i],"call")==0){							//"call" >>Endereço<< 
				  	strcpy(PosLeitura[contLei],"0111100");
				  	for(int t=0; t<p->cont; t++){
						if(strcmp(l[z].cod[i+1],p->label[t])==0){
							strcat(PosLeitura[contLei],p->numeroReferencia[t]);		//DECIDINDO >>Endereço<<
							t = p->cont;
						}
					}
					contLei++;
					continue; 
				
				} else if(strcmp(l[z].cod[i],"load_c")==0){				//"load_c" Reg 1 >>Endereço<< OU CONSTANTE
				  	strcpy(PosLeitura[contLei],"10011");
				  	char auxiliarLeitura[15];
					auxiliarEscrita(2,auxiliarLeitura,l[z].cod[i+1]);				//DECIDINDO Reg1
					strcat(PosLeitura[contLei],auxiliarLeitura);

					for(int t=0; t<p->cont; t++){
						if(strcmp(l[z].cod[i+2],p->label[t])==0){
							strcat(PosLeitura[contLei],p->numeroReferencia[t]);		//DECIDINDO >>Endereço<<
							t = p->cont;
							contLei++;
							continue; 
						}
					}

					int aux = atoi(l[z].cod[i+2]);
					char aux2[15];													//DECIDINDO >>Constante<<
					converteBinario(aux,aux2);
					strcat(PosLeitura[contLei],aux2);
					contLei++;
					continue;
				 
				}

				//@@@@CONJUNTO DE INSTRUÇÕES QUE -->> NÃO USAM REGISTRADORES OU ENDEREÇOS DE MEMÓRIA --<< @@@@@@@

				  else if(strcmp(l[z].cod[i],"stop")==0){				//"stop"
				  	strcpy(PosLeitura[contLei],"0000000000000000");

				  	contLei++;
				  	continue;

				} else if(strcmp(l[z].cod[i],"return")==0){				//"return"
				  	strcpy(PosLeitura[contLei],"1000000000000000");

				  	contLei++;
				  	continue;		

				} else if(strcmp(l[z].cod[i],".data")==0){				//.data QUANTIDADE_DE_BITS VALOR A SER TRANSFORMADO EM BINÁRIO

					int aux = atoi(l[z].cod[i+1]);						//LEIO A QUANTIDADE DE BITS(SEMPRE MULTIPLO DE 2)
					int j=0;
					for(int i=0; i<aux-1; i++){
						sprintf(PosLeitura[contLei],"00000000");
						j++;
						if(j==2){
							contLei++;
							j=0;
						}
					}
					int aux2 = atoi(l[z].cod[i+2]);		//LEIO O VALOR INTEIRO A SER TRANSFORMADO
					char auxA[10];
					converteBinario(aux2,auxA);		//O CONVERTO EM BINÁRIO
					int r =1;
					int b=0;
					char auxB[10];
					while(b<strlen(auxA)){
						auxB[b] = auxA[b+1];			//O ADICIONO EM UM AUXILIAR, PRA PEGAR SOMENTE OS 8 BITS-->
						b++;							//--> E NÃO 9, QUE É O QUE A "converterBinario" FORNECE.
					}
					fflush(stdin);
					strcat(PosLeitura[contLei],auxB);	
					contLei++;
					continue;

				}

	}


	FILE *arq;
	nomeArquivo[strlen(nomeArquivo)-1] = '\0';
	char auxiliarTipo[] = "mif";
	strcat(nomeArquivo,auxiliarTipo);
	arq = fopen(nomeArquivo, "w");								//ABRINDO O ARQUIVO					
	if(arq==NULL){
		printf("Arquivo nulo\n");
		return;
	}

	fprintf(arq,"DEPTH = 128;\n");
	fprintf(arq,"WIDTH = 8;\n");
	fprintf(arq,"ADDRESS_RADIX = HEX;\n");						//DEFINIÇÕES DO MONTADOR
	fprintf(arq, "DATA_RADIX = BIN;\n");
	fprintf(arq, "CONTENT\n");
	fprintf(arq, "BEGIN\n\n\n");
	
	int h=0;
	int g=0;
	int r=0;
	char final[contLei*2][8];							//COMO EM 'PosLeitura' EU LI 16 BITS POR POSIÇÃO DO VETOR-->
	for(int y=0; y<contLei; y++){						//-->(OU 16 BITS POR LINHA), EU AGORA VOU IMPRIMIR 8 BITS EM-->
		int v=0;										//--> CADA POSIÇÃO
		int h=0;
		while(v!=16){
			final[g][h] = PosLeitura[y][v];
			v++;
			h++;
			if(v==8){
				final[g][h] = '\0';
				if(g<16){
					printf("0%X         :  %s;\n",g,final[g]);
					fprintf(arq,"0%X         :  %s;\n",g,final[g]);
				}else{
					printf("%X         :  %s;\n",g,final[g]);
					fprintf(arq,"%X         :  %s;\n",g,final[g]);
				}
				g++;
				h=0;
			}
		}
		final[g][h] = '\0';
		if(g<16){
			printf("0%X         :  %s;\n",g,final[g]);
			fprintf(arq,"0%X         :  %s;\n",g,final[g]);
		}else{
			printf("%X         :  %s;\n",g,final[g]);
			fprintf(arq,"%X         :  %s;\n",g,final[g]);
		}
		g++;	
	}

	if(g<16){
		fprintf(arq,"[0%X..%X]   :  00000000;\n",g,127);				//COMPLETANDO AS 128 LINHAS DO CÓDIGO
		printf("[0%X..%X]   :  00000000;\n",g,127);
	}else{
		fprintf(arq,"[%X..%X]   :  00000000;\n",g,127);					//COMPLETANDO AS 128 LINHAS DO CÓDIGO
		printf("[%X..%X]   :  00000000;\n",g,127);
	}
	fprintf(arq,"END;\n");
	printf("END;\n");
	fclose(arq);
}