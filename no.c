#include "no.h"

No *novoNo(Senha senha) {
    No *novo = (No *) malloc(sizeof(No));
    novo->senha = senha;
    novo->proximo = NULL;
    return novo;
}