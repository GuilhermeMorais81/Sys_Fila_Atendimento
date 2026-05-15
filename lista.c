#include "lista.h"

void novaLista(Lista *lista) {
    lista->primeiro = NULL;
}

int estaVazia(Lista *lista) {
    return lista->primeiro == NULL;
}

void insere_Inicio(Lista *lista, int novaSenha) {
    No *novo = novoNo(novaSenha);
    if(!estaVazia(lista)) novo->proximo = lista->primeiro;
    lista->primeiro = novo;
}

void exibe_Lista(Lista *lista) {
    if(estaVazia(lista)) printf(MENS_FILA_VAZIA);
    else {
        No *runner = lista->primeiro;
        while(runner != NULL) {
            printf("%d -> ", runner->senha);
            runner = runner->proximo;
        }
        printf("//\n");
    }
}

void insere_Fim(Lista *lista, int novaSenha) {
    No *novo = novoNo(novaSenha);
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

int remove_Inicio(Lista *lista) {
    int copiaSenha = lista->primeiro->senha;
    No *copiaEndereco = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
    free(copiaEndereco);
    return copiaSenha;
}

int remove_Fim(Lista *lista) {
    int copiaSenha;
    No *copiaEndereco;
    if(lista->primeiro->proximo == NULL) {
        copiaSenha = lista->primeiro->senha;
        copiaEndereco = lista->primeiro;
        lista->primeiro = NULL;
    }
    else {
        No *runner = lista->primeiro;
        while(runner->proximo->proximo != NULL) runner = runner->proximo;
        copiaSenha = runner->proximo->senha;
        copiaEndereco = runner->proximo;
        runner->proximo = NULL;
    }
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
