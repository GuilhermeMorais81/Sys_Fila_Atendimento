#include "Senha.h"

Senha novaSenha(int contadorSenha, int tipo) {
    Senha novo;
    novo.numero = contadorSenha;
    novo.tipo = tipo;
    return novo;
}