#include <stdio.h>
#include <stdlib.h>
#include "Exercicio_11.h"

void fpVazia(TipoPilha *pilha){
    pilha->topoesq = 0;
    pilha->topodir = MAX-1;
}

void vVazia(TipoPilha pilha)
{
    if(pilha.topoesq==0 && pilha.topodir==MAX-1)
    {
        printf("As duas pilhas estao vazias");
        return 0;
    }
    else if(pilha.topoesq==0)
    {
        printf("Apenas a pilha esquerda esta vazia");
        return 1;
    }
    else if(pilha.topodir==MAX-1)
    {
        printf("Apenas a pilha direita esta vazia");
        return -1;
    }
}

void EmpilhaEsq(TipoPilha *pilha, TipoItem x)
{
    if(pilha->topoesq==pilha->topodir)
    {
        printf("Esta pilha está cheia");
    }
    else
    {
        pilha->item[pilha->topoesq]=x;
        pilha->topoesq++;
    }
}

void EmpilhaDir(TipoPilha *pilha, TipoItem x)
{
    if(pilha->topoesq==pilha->topodir)
    {
        printf("Esta pilha está cheia");
    }
    else
    {
        pilha->item[pilha->topodir]=x;
        pilha->topodir--;
    }
}

void RetiraEsq(TipoPilha *pilha, TipoItem *x)
{
    if(pilha->topoesq==0)
    {
        printf("A pilha esquerda esta vazia");
    }
    else
    {
        *x=pilha->item[pilha->topoesq-1];
        pilha->topoesq--;
    }
}

void RetiraDir(TipoPilha *pilha, TipoItem *x)
{
    if(pilha->topodir==MAX-1)
    {
        printf("A pilha direita esta vazia");
    }
    else
    {
        *x=pilha->item[pilha->topodir+1];
        pilha->topodir++;
    }
}

void ImprimeEsq(TipoPilha pilha)
{
    int i= pilha.topoesq -1;
    printf("Itens da pilha Esquerda: \n");
    while (i>=0)
    {
        printf("%d, ",pilha.item[i]);
        i--;
    }
}

void ImprimeDir(TipoPilha pilha)
{
    int i= pilha.topodir +1;
    printf("\n\nItens da pilha Direita: \n");
    while (i<=MAX-1)
    {
        printf("%d, ",pilha.item[i]);
        i++;
    }
}
