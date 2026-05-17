#include "lista.h"

Lista filaAtendimento;
int geradorSenha = 0;
int geradorSenhaVip = 99;

int receberOpcao(char *mensagem);
void exibirMenu();
void direcionarUsuario(int opcao);
void init();
void emitirSenha();
void chamarProximo();
void exibirTamLista();
void emitirSenhaVip();

int main() {
    init();
    return 0;
}

int receberOpcao(char *mensagem) {
    int input;
    printf("%s\n", mensagem);
    scanf("%d", &input);
    return input;
}

void exibirMenu() {
    int opcao = 0;
    while(opcao != 6) {
        printf("\n==> SISTEMA DE FILA DE ATENDIMENTO\n\n");
        printf("1 - Emitir nova senha\n");
        printf("2 - Chamar proximo\n");
        printf("3 - Ver fila Atual\n");
        printf("4 - Quantas pessoas estao na fila?\n");
        printf("5 - Emitir senha VIP\n");
        printf("6 - Sair\n");
    
        opcao = receberOpcao("Selecione uma das opcoes acima:");
        direcionarUsuario(opcao);
    }
}

void direcionarUsuario(int opcao) {
    switch(opcao) {
        case 1:
            emitirSenha();
            break;
        case 2:
            chamarProximo();
            break;
        case 3:
            exibe_Lista(&filaAtendimento);
            break;
        case 4:
            exibirTamLista();
            break;
        case 5:
            emitirSenhaVip();
            break;
        case 6:
            break;
        default:
            printf(YELLOW_BEGIN "Essa opcao nao existe...\n" COLOR_END);
    }
}

void init() {
    novaLista(&filaAtendimento);
    exibirMenu();
}

void emitirSenha() {
    insere_Fim(&filaAtendimento, ++geradorSenha);
    printf(GREEN_BEGIN"Senha %d foi adicionada\n"COLOR_END, geradorSenha);
}

void chamarProximo() {
    if(!estaVazia(&filaAtendimento)) {
        printf(GREEN_BEGIN"Senha %d foi atendida e saiu da fila"COLOR_END, remove_Inicio(&filaAtendimento).numero);
    } 
    else printf(MENS_FILA_VAZIA);
}

void exibirTamLista() {
    if(!estaVazia(&filaAtendimento)) printf(GREEN_BEGIN"%d pessoa(s)\n"COLOR_END, tamanho_lista(&filaAtendimento));
    else printf(MENS_FILA_VAZIA);
}

void emitirSenhaVip() {
    insere_vip(&filaAtendimento, ++geradorSenhaVip);
    printf(GREEN_BEGIN"Senha VIP %d foi adicionada\n"COLOR_END, geradorSenhaVip);
}

