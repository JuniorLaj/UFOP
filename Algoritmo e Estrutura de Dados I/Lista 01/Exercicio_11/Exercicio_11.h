#ifndef EXERCICIO_11_H_INCLUDED
#define EXERCICIO_11_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX 80

typedef int TipoChave;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef int apontador;

typedef struct{
    TipoItem item[MAX];
    apontador topoesq, topodir;
}TipoPilha;

void vVazia(TipoPilha pilha);
void EmpilhaEsq(TipoPilha *pilha, TipoItem x);
void EmpilhaDir(TipoPilha *pilha, TipoItem x);
void RetiraEsq(TipoPilha *pilha, TipoItem *x);
void RetiraDir(TipoPilha *pilha, TipoItem *x);
void ImprimeEsq(TipoPilha pilha);
void ImprimeDir(TipoPilha pilha);


#endif // EXERCICIO_11_H_INCLUDED
