#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.c"

int main()
{
	//CRIANDO FILA E ADICIONANDO ITENS E FAZENDO TESTES(DESENFILEIRA E ENFILEIRA NOVAMENTE)
    tipoFila f1;
    ffVazia(&f1);

    tipoItem x;
    x.chave = 10;
    enfileira(x, &f1);
    x.chave = 2;
    enfileira(x, &f1);
   x.chave = 5;
    enfileira(x, &f1);
    x.chave = 7;
    enfileira(x, &f1);
       x.chave = 1;
    enfileira(x, &f1);

    imprime(f1);
    desenfileira(&f1, &x);
    imprime(f1);
	 x.chave = 4;
    enfileira(x, &f1);
     imprime(f1);

     x.chave = 431;
    enfileira(x, &f1);
    desenfileira(&f1, &x);
    imprime(f1);
	x.chave = 31;
    enfileira(x, &f1);

    imprime(f1);
    return 0;
}
