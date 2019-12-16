#include <stdio.h>
#include <stdlib.h>
struct No{
    int numero;
    struct No *esquerda;
    struct No *direita;
}No;
typedef struct No* Arvore;

void criarArvore(Arvore* pRaiz);
void insercao_Recursiva(Arvore *pRaiz, int numero2);
int totalNO_Recursivo(Arvore **pRaiz);
int altura_Recursiva(Arvore *pRaiz);
int somaArvBin_Recursiva(Arvore **pRaiz);
