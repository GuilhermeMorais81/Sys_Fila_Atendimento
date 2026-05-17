#include <stdio.h>
#include "Senha.h"

typedef struct No {
    Senha senha;
    struct No *proximo;
} No;

No *novoNo(Senha Senha);