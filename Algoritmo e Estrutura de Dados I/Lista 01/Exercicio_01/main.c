#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.c"

int main()
{
    tipoFila f1;
    ffVazia(&f1);

    tipoItem x;
    x.chave = 3;
    enfileira(x, &f1);
    x.chave = 4;
    enfileira(x, &f1);
	 x.chave = 5;
    enfileira(x, &f1);
    x.chave = 6;
    enfileira(x, &f1);
     x.chave = 7;
    enfileira(x, &f1);
    x.chave = 8;
    enfileira(x, &f1);
     x.chave = 9;
    enfileira(x, &f1);
    x.chave = 10;
    enfileira(x, &f1);
     x.chave = 11;
    enfileira(x, &f1);

    imprime(f1);
    desenfileira(&f1, &x);

    imprime(f1);
    x.chave = 80;
    furaFila(x,&f1);
    desenfileira(&f1, &x);
    x.chave = 79;
    furaFila(x,&f1);
    imprime(f1);
    return 0;
}
