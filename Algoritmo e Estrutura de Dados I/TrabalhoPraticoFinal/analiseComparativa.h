#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	FILE *arquivo;
	int *vetor;
	int quantVet;
	unsigned long long int numComparacoes;
	unsigned long long int numTrocas;
}analiseComparativas;


void analiseComparativa();
void construirArquivos();
double insertionSort(analiseComparativas *p);
double selectionSort(analiseComparativas *p);
double shellSort(analiseComparativas *p);
//void quickSort(int a[], int l, int r,double *m, int *numComparacoes, int *numTrocas);

