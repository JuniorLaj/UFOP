#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

typedef int apontador;

typedef struct{
	int chave;
}tipoItem;

typedef struct{
	apontador esquerda, direita;
	tipoItem item[MAX];
	apontador cont;

}tipoDeque;

void ffVazio(tipoDeque *deque);
int vazia(tipoDeque deque);
void insDir(tipoDeque *deque, tipoItem carta);
void insEsq(tipoDeque *deque, tipoItem carta);
void imprime(tipoDeque deque);
void remEsq(tipoDeque *deque, tipoItem *carta);
void remDir(tipoDeque *deque, tipoItem *carta);

