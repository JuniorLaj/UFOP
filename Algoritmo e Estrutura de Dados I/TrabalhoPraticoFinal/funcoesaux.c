#include "analiseComparativa.h"

clock_t Ticks[2];
double insertionSort(analiseComparativas *p){

	int escolhido,j,i;
	Ticks[0] = (double) clock();
	
    for (i = 1; i < p->quantVet; i++) {
		escolhido = p->vetor[i];
		j = i - 1;
		while ((j >= 0) && (p->vetor[j] > escolhido)) {
			p->numComparacoes++;
			p->vetor[j + 1] = p->vetor[j];
			p->numTrocas++;
			j--;
		}
		p->numComparacoes++;
		if(p->vetor[j+1]!=escolhido){
		p->vetor[j + 1] = escolhido;
		}
		
	}
	Ticks[1] = (double) clock();
	return((Ticks[1] - Ticks[0])*1000/CLOCKS_PER_SEC);
}

double selectionSort(analiseComparativas *p){ 
  int i, j, min, aux;
  Ticks[0] = (double) clock();
  for (i = 0; i < (p->quantVet-1); i++){
     min = i;
     for (j = (i+1); j < p->quantVet; j++){
     	p->numComparacoes++;
       if(p->vetor[j] < p->vetor[min]){
         min = j;
     	}
     }
     if (p->vetor[i] != p->vetor[min]) {
     	p->numTrocas++;
       aux = p->vetor[i];
       p->vetor[i] = p->vetor[min];
       p->vetor[min] = aux;
     }
  }
  Ticks[1] = (double) clock();
  return((Ticks[1] - Ticks[0])*1000/CLOCKS_PER_SEC);
}

double shellSort(analiseComparativas *p) {
    int i,j,valor;
    Ticks[0] = (double) clock();
    int aux = 1;
    while(aux < p->quantVet) {
        aux = 3*aux+1;
    }
    while (aux>1) {
        aux /= 3;
        for(i = aux; i < p->quantVet; i++) {
        	p->numComparacoes++;
            valor = p->vetor[i];
            j = i;
            while (j >= aux && valor < p->vetor[j - aux]) {
                p->vetor[j] = p->vetor[j - aux];
                p->numTrocas++;
                j = j - aux;
            }
            p->vetor[j] = valor;
        }
    }
	Ticks[1] = (double) clock();
  	return((Ticks[1] - Ticks[0])*1000/CLOCKS_PER_SEC);
}


void quickSort(int *a, int left, int right, long int *numTrocas, long int *numComparacoes) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i < j) {
        while(a[i] < x) {
            i++;
            (*numComparacoes)++;
        }
         (*numComparacoes)++;
        while(a[j] > x) {
            j--;
             (*numComparacoes)++;
        }
         (*numComparacoes)++;
        if(i <= j) {
            y = a[i];
            a[i] = a[j], a[j] = y, i++, j--;
             (*numTrocas)++;
        }
    }
     
    if(j > left) {
        quickSort(a, left, j, numTrocas,numComparacoes);
    }
    if(i < right) {
        quickSort(a, i, right, numTrocas,numComparacoes);
    }
}
  
void imprimeOrd(analiseComparativas p){
	int i;
	for(i=0; i<p.quantVet; i++){
		printf("%d, ", p.vetor[i]);
	}
	printf("\n");
}
