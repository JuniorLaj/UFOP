#include <stdio.h>
#include <stdlib.h>
#include "Exercicio_11.c"

int main()
{

    TipoPilha pilha;
    TipoItem x;

    fpVazia(&pilha);

    x.chave=11;
    EmpilhaEsq(&pilha, x);

    x.chave=22;
    EmpilhaEsq(&pilha, x);

    x.chave=40;
    EmpilhaEsq(&pilha, x);

    x.chave=50;
    EmpilhaEsq(&pilha, x);

    ImprimeEsq(pilha);

    x.chave=44;
    EmpilhaDir(&pilha, x);

    x.chave=77;
    EmpilhaDir(&pilha, x);

    x.chave=95;
    EmpilhaDir(&pilha, x);

    x.chave=31;
    EmpilhaDir(&pilha, x);

    ImprimeDir(pilha);

    return 0;
}
