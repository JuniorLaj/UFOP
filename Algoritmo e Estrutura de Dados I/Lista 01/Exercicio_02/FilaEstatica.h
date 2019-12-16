#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

#define MAX 5


typedef int tipoChave;
typedef int apontador;

typedef struct {
    tipoChave chave;
    //outros componentes
}tipoItem;

typedef struct{
    tipoItem item[MAX];
    apontador frente, tras;
    int cont;
}tipoFila;

void ffVazia(tipoFila *fila);
int vazia(tipoFila fila);
void enfileira(tipoItem x, tipoFila *fila);
void desempilha (tipoFila *fila, tipoItem *x);
void imprime(tipoFila fila);

#endif // FILAESTATICA_H_INCLUDED
