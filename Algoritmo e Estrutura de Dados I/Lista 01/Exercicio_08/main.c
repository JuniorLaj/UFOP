#include "ListaSites.c"


int main(){

tipoItem k;
tipoItem k2;
tipoItem k3;
tipoItem k4;
tipoLista l1;

flvazia(&l1);

strcpy(k.nome,"Facebook");
strcpy(k.site,"https://www.facebook.com/");
addLista(&l1, k);

strcpy(k2.nome,"Google imagens");
strcpy(k2.site,"https://www.google.com.br/imghp?hl=pt-PT");
addLista(&l1, k2);

strcpy(k3.nome,"Google site");
strcpy(k3.site,"https://www.google.com.br");
addLista(&l1, k3);

strcpy(k4.nome,"YouTube");
strcpy(k4.site,"https://www.youtube.com.br/");
addLista(&l1, k4);

imprimeLista(&l1);

char nome22[] = "Google imagens";
buscaLista(&l1, nome22);
char nome[] = "Google imagens";
buscaLista(&l1, nome);

char nome2[] = "Google site";
buscaLista(&l1, nome2);

char nome3[] = "Facebook";
buscaLista(&l1, nome3);
char nome4[] = "YouTube";
buscaLista(&l1, nome4);
char nome5[]= "YouTube";
buscaLista(&l1, nome5);


imprimeLista(&l1);


return 0;

}
