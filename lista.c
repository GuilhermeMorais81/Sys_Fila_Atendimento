#include "lista.h"
#define FALSE 0
#define TRUE 1

void novaLista(Lista *lista) {
    lista->primeiro = NULL;
}

int estaVazia(Lista *lista) {
    return lista->primeiro == NULL;
}

void insere_vip(Lista *lista, int contadorSenha) {
    Senha senha = novaSenha(contadorSenha, VIP);
    No *novo = novoNo(senha);
   
    if(estaVazia(lista) || lista->primeiro->senha.tipo == COMUM) {
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
        return;
    }
    
    No *runner = lista->primeiro;
    while(runner->proximo != NULL && runner->proximo->senha.tipo == VIP) {
        runner = runner->proximo;
    }

    if(runner->proximo != NULL) {
        No *primeiroComum;
        primeiroComum = runner->proximo;
        novo->proximo = primeiroComum;
    }
    runner->proximo = novo;
}

void exibe_Lista(Lista *lista) {
    if(estaVazia(lista)) printf(MENS_FILA_VAZIA);
    else {
        No *runner = lista->primeiro;
        while(runner != NULL) {
            printf("%d -> ", runner->senha.numero);
            runner = runner->proximo;
        }
        printf("//\n");
    }
}

void insere_Fim(Lista *lista, int contadorSenha) {
    Senha senha = novaSenha(contadorSenha, COMUM);
    No *novo = novoNo(senha);
    if(estaVazia(lista)) {
        lista->primeiro = novo;
    }
    else {
        No *runner = lista->primeiro;
        while(runner->proximo != NULL) {
            runner = runner->proximo;
        }
        runner->proximo = novo;
    }
}

Senha remove_Inicio(Lista *lista) {
    Senha copiaSenha = lista->primeiro->senha;
    No *copiaEndereco = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
    free(copiaEndereco);
    return copiaSenha;
}

int tamanho_lista(Lista *lista) {
    int contador = 0;
    No *runner = lista->primeiro;
    while(runner != NULL) {
        contador++;
        runner = runner->proximo;
    }
    return contador;
}
