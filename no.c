#include "no.h"

No *novoNo(int senha) {
    No *novo = (No *) malloc(sizeof(No));
    novo->senha = senha;
    novo->proximo = NULL;
    return novo;
}