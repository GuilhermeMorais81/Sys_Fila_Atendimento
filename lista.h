#include "no.h"
#define GREEN_BEGIN "\033[0;32m"
#define COLOR_END "\033[0m"
#define YELLOW_BEGIN "\033[1;33m"
#define MENS_FILA_VAZIA YELLOW_BEGIN"Nao existe ninguem na fila...\n"COLOR_END

typedef struct Lista {
    No *primeiro;
} Lista;

void novaLista(Lista *lista);
int estaVazia(Lista *lista);
void insere_Inicio(Lista *lista, int novaSenha);
void exibe_Lista(Lista *lista);
void insere_Fim(Lista *lista, int novaSenha);
int remove_Inicio(Lista *lista);
int remove_Fim(Lista *lista);
int tamanho_lista(Lista *lista);