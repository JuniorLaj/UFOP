#include "PilhadePalavras.c"
#include <string.h>

int main(){

tipoPilha p1;

fpilhaVazia(&p1);

tipoItem k;

char ss[] = "4mutumutumutum 4";

emPilhaPartes(&p1, ss);

palindromStrings(p1);

return 0;
}
