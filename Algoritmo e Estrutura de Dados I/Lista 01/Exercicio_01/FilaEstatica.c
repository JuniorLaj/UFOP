#include "FilaEstatica.h"


void ffVazia(tipoFila *fila)
{
    fila->frente = 1;
    fila->tras = fila->frente;
}

int vazia(tipoFila fila)
{
    return (fila.frente == fila.tras);
}

void enfileira(tipoItem x, tipoFila *fila)
{
    if (fila->tras % MAX + 1 == fila ->frente)
        printf("\nERROR: QUEUE IS FULL\n");
    else
    {
        fila->item[fila->tras - 1] = x;
        fila->tras = fila->tras % MAX + 1;
    }
}

void desenfileira(tipoFila *fila, tipoItem *x)
{
    if (vazia(*fila))
        printf("\nERROR: QUEUE IS EMPTY");
    else
    {
        *x = fila->item[fila->frente - 1];
        fila->frente = fila->frente % MAX + 1;
    }
}

void imprime(tipoFila f)
{
    if(vazia(f))
        return;
    printf("\n\n*********************IMPRIMINDO OS ITENS*********************\n");

    int i = f.frente;
    while(i != f.tras)
    {
        printf("%d, ", f.item[i-1]);
        i = i%MAX + 1;
    }

    printf("\n***************************FIM DA IMPRESSAO***************************\n\n");
}
void furaFila(tipoItem x, tipoFila *fila){
    if (fila->tras % MAX + 1 == fila ->frente)
        printf("\nERROR: QUEUE IS FULL\n");
    else
    {
        if(fila->frente%MAX-1==0){
            fila->frente = MAX;
        } else{
        	fila->frente = fila->frente%MAX -1;
		}

        fila->item[fila->frente - 1] = x;

    }

}
