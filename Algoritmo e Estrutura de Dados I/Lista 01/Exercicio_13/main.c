#include "Lista.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tLista lista;
  fazLista(&lista);
  printf("Imprime se a lista e vazia\n");
  if(ehVazia(lista))
    printf("Lista vazia\n");
  add(&lista, 1);
  add(&lista, 1);
  add(&lista, 1);
  /*add(&lista, 2);
  add(&lista, 5);
  add(&lista, 7);
  add(&lista, 8);
  add(&lista, 5);
  add(&lista, 9);
  add(&lista, 12);
  add(&lista, 1);
  add(&lista, 8);*/
  printf("Imprime lista\n");
  imprime(lista);
  removeRepetido(&lista);
  printf("Imprime nova lista sem repeticoes\n");
  imprime(lista);
  return 0;
}
