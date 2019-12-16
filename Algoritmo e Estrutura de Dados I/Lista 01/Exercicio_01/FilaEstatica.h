#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

#define MAX 10


typedef int tipoChave;
typedef int apontador;

typedef struct {
    tipoChave chave;
    //outros componentes
}tipoItem;

typedef struct{
    tipoItem item[MAX];
    apontador frente, tras;
}tipoFila;

void ffVazia(tipoFila *fila);
int vazia(tipoFila fila);
void enfileira(tipoItem x, tipoFila *fila);
void desenfileira(tipoFila *fila, tipoItem *x);
void imprime(tipoFila fila);
//void furaFila(tipoItem x, tipoFila *fila);
#endif // FILAESTATICA_H_INCLUDED
