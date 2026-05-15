#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int senha;
    struct No *proximo;
} No;

No *novoNo(int senha);