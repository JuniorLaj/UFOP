#include <stdio.h>
#include <stdlib.h>
#include "FilaPares.c"

int main(){

tipoLista l1;
flvazia(&l1);
tipoItem x;
imprimeLista(&l1);

x.chave = 14;
insereLista(&l1,x);
x.chave = 15;
insereLista(&l1,x);
x.chave = 65;
insereLista(&l1,x);
x.chave = 444;
insereLista(&l1,x);
x.chave = 13;
insereLista(&l1,x);
x.chave = 14;
insereLista(&l1,x);
x.chave = 144;
insereLista(&l1,x);

imprimeLista(&l1);

removePar(&l1);

imprimeLista(&l1);

return 0;
}
