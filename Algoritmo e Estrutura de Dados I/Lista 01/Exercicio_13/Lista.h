#define tipoChave  int

typedef struct tipoItem{
  tipoChave chave;
} tipoItem;

typedef struct celula *apontador;

typedef struct celula{
  tipoItem item;
  apontador proximo;
} celula;

typedef struct tLista{
  apontador inicio, fim;
  int count;
} tLista;

void fazLista(tLista *lista);

int ehVazia(tLista lista);

void add(tLista *lista, tipoChave x);

void removes(tLista *lista, tipoChave *x);

void imprime(tLista lista);

void removeRepetido(tLista *lista);
