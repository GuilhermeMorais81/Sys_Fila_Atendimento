#include <stdlib.h>
#define COMUM 0
#define VIP 1

typedef struct Senha {
    int numero;
    int tipo;
} Senha;

Senha novaSenha(int contadorSenha, int tipo);


