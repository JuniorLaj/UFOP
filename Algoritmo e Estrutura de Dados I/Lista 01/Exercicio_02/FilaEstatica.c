#include "FilaEstatica.h"


void ffVazia(tipoFila *fila)
{
    fila->frente = 1;
    fila->tras = 1;
    fila->cont = 0;

}

int vazia(tipoFila fila)
{
    return (fila.frente == fila.tras);
}

void enfileira(tipoItem x, tipoFila *fila){

    	if(fila->tras==MAX+1 && fila->frente!=1){
    		int i;
    		int cont;
    		for(i=0; i<fila->tras-2; i++){
    			fila->item[i] = fila->item[i+1];

			}
			fila->frente = 1;


			fila->item[fila->tras-2] = x;
			fila->cont++;
		}
		 else if (fila->tras==MAX+1){

        printf("Fila cheia!\n");
        return;
	}else{

			fila->item[fila->tras-1] = x;
			fila->tras++;
			fila->cont++;
	}
}

void desenfileira(tipoFila *fila, tipoItem *x){
    if(vazia(*fila))
        printf("Erro, fila vazia!\n");
        else{
        	tipoItem z;

            *x = fila->item[fila->frente-1];
            fila->frente++;
            //fila->item[fila->frente-1] = x.chaveZero;
            fila->cont--;

            /*int a=1;
            int i;
            for(i=0; i<fila->tras-1; i++){
               fila->item[i] = fila->item[i+a];
               }
            fila->tras--;
            */
        }
}

void imprime(tipoFila f)
{
    if(vazia(f))
        return;
    printf("\n\n*********************IMPRIMINDO OS ITENS*********************\n");

    int i = f.frente-1;
    while(i < f.tras-1)
    {
        printf("%d, ", f.item[i]);
        i++;
    }


    printf("\n***************************FIM DA IMPRESSAO***************************\n\n");
}

