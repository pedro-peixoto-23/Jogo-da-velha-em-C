#include <stdio.h>
#include<conio.h>

char listaJogoDaVelha[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int qtdJogadas = 0;
int coordenadaXY[2];

void imprimirJogoDaVelha() {
        printf("    0   1   2 \n");
        printf("  -------------\n");
        printf("0 | %c | %c | %c | 0\n", listaJogoDaVelha[0][0], listaJogoDaVelha[0][1], listaJogoDaVelha[0][2]);
        printf("  -------------\n");
        printf("1 | %c | %c | %c | 1\n", listaJogoDaVelha[1][0], listaJogoDaVelha[1][1], listaJogoDaVelha[1][2]);
        printf("  -------------\n");
        printf("2 | %c | %c | %c | 2\n", listaJogoDaVelha[2][0], listaJogoDaVelha[2][1], listaJogoDaVelha[2][2]);
        printf("  -------------");
        printf("\n    0   1   2 \n");
        
}

char verificarJogadorAtual() {
    if (qtdJogadas % 2 == 0) {
        return 'x';
    } else {
        return 'O';
    }
}

void imprimirDadosDaPartida() {
    printf("\n- Qtd. Jogadas -> %d\n", qtdJogadas);
    char jogadorAtual = verificarJogadorAtual();
    printf("- Jogador atual -> %c\n", jogadorAtual);
}

void imprimirTelaJogo() {
    imprimirJogoDaVelha();
    verificarJogadorAtual();
    imprimirDadosDaPartida();
}

int verificarCoordenadaDoUsuario() {
    if (coordenadaXY[0] > 2 || coordenadaXY[0] < 0) {
        return 0;
    } else if (coordenadaXY[1] > 2 || coordenadaXY[1] < 0) {
        return 0;
    } else {
        return 1;
    }
}

void inserirElementoNaLista() {
    char JogadorAtual = verificarJogadorAtual();
    
    if (coordenadaXY[0] == 0 && coordenadaXY[1] == 0) {
        listaJogoDaVelha[0][0] = JogadorAtual;
    } else if (coordenadaXY[0] == 0 && coordenadaXY[1] == 1) {
        listaJogoDaVelha[0][1] = JogadorAtual;
    } else if (coordenadaXY[0] == 0 && coordenadaXY[1] == 2) {
        listaJogoDaVelha[0][2] = JogadorAtual;
    } else if (coordenadaXY[0] == 1 && coordenadaXY[1] == 0) {
        listaJogoDaVelha[1][0] = JogadorAtual;
    } else if (coordenadaXY[0] == 1 && coordenadaXY[1] == 1) {
        listaJogoDaVelha[1][1] = JogadorAtual;
    } else if (coordenadaXY[0] == 1 && coordenadaXY[1] == 2) {
        listaJogoDaVelha[1][2] = JogadorAtual;
    } else if (coordenadaXY[0] == 2 && coordenadaXY[1] == 0) {
        listaJogoDaVelha[2][0] = JogadorAtual;
    } else if (coordenadaXY[0] == 2 && coordenadaXY[1] == 1) {
        listaJogoDaVelha[2][1] = JogadorAtual;
    }else if (coordenadaXY[0] == 2 && coordenadaXY[1] == 2) {
        listaJogoDaVelha[2][2] = JogadorAtual;
    }
}


int verificarVencedorOuEmpate() {
    char JogadorAtual = verificarJogadorAtual();
    int verificador = 0;
    
    // Vencedor nas linhas
    if (listaJogoDaVelha[0][0] == JogadorAtual && listaJogoDaVelha[0][1] == JogadorAtual && listaJogoDaVelha[0][2] == JogadorAtual) {
        verificador = 1;
    } else if (listaJogoDaVelha[1][0] == JogadorAtual && listaJogoDaVelha[1][1] == JogadorAtual && listaJogoDaVelha[1][2] == JogadorAtual) {
        verificador = 1;
    } else if (listaJogoDaVelha[2][0] == JogadorAtual && listaJogoDaVelha[2][1] == JogadorAtual && listaJogoDaVelha[2][2] == JogadorAtual) {
        verificador = 1;
    // Vencedor nas colunas
    } else if (listaJogoDaVelha[0][0] == JogadorAtual && listaJogoDaVelha[1][0] == JogadorAtual && listaJogoDaVelha[2][0] == JogadorAtual) {
        verificador = 1;
    } else if (listaJogoDaVelha[0][1] == JogadorAtual && listaJogoDaVelha[1][1] == JogadorAtual && listaJogoDaVelha[2][1] == JogadorAtual) {
        verificador = 1;
    } else if (listaJogoDaVelha[0][2] == JogadorAtual && listaJogoDaVelha[1][2] == JogadorAtual && listaJogoDaVelha[2][2] == JogadorAtual) {
        verificador = 1;
    // Vencedor nas diagonais
    } else if (listaJogoDaVelha[0][0] == JogadorAtual && listaJogoDaVelha[1][1] == JogadorAtual && listaJogoDaVelha[2][2] == JogadorAtual) {
        verificador = 1;
    } else if (listaJogoDaVelha[2][0] == JogadorAtual && listaJogoDaVelha[1][1] == JogadorAtual && listaJogoDaVelha[0][2] == JogadorAtual) {
        verificador = 1;
    } else if (!(listaJogoDaVelha[0][0] == ' ') && !(listaJogoDaVelha[0][1] == ' ') && !(listaJogoDaVelha[0][2] == ' ') && !(listaJogoDaVelha[1][0] == ' ') && !(listaJogoDaVelha[1][1] == ' ') && !(listaJogoDaVelha[1][2] == ' ') && !(listaJogoDaVelha[2][0] == ' ') && !(listaJogoDaVelha[2][1] == ' ') && !(listaJogoDaVelha[2][2] == ' ')) {
        verificador = 2;
    }
    
    if (verificador == 1) {
        limparTela();
        imprimirJogoDaVelha();
        printf("\nTemos um vencedor: o jogador %c ganhou o jogo!", JogadorAtual);
        return 1;
    } else if (verificador == 2) {
        limparTela();
        imprimirJogoDaVelha();
        printf("\nOcorreu um empate: nenhum dos jogadores venceu.");
        return 1;
    } else {
        return 0;
    }
}

void limparTela() {
    for (int i = 0; i < 50; i++) {
        printf("\n");  
    }
}

void reiniciarJogo() {
    qtdJogadas = 0;
    listaJogoDaVelha[0][0] = ' ';
    listaJogoDaVelha[0][1] = ' ';
    listaJogoDaVelha[0][2] = ' ';
    listaJogoDaVelha[1][0] = ' ';
    listaJogoDaVelha[1][1] = ' ';
    listaJogoDaVelha[1][2] = ' ';
    listaJogoDaVelha[2][0] = ' ';
    listaJogoDaVelha[2][1] = ' ';
    listaJogoDaVelha[2][2] = ' ';
}

int main() {
    
    while (1) {
        limparTela();
        
        imprimirTelaJogo(listaJogoDaVelha, qtdJogadas);
        
        printf("\nLinha: ");
        scanf("%d", &coordenadaXY[0]);
        
        printf("coluna: ");
        scanf("%d", &coordenadaXY[1]);
        
        if (verificarCoordenadaDoUsuario(coordenadaXY) == 0) {
            continue;
        }
        
        if ((listaJogoDaVelha[coordenadaXY[0]][coordenadaXY[1]] == ' ')) { // ja existe na lista
        
            inserirElementoNaLista();
            
            if (verificarVencedorOuEmpate() == 1) {
                int verificador;
                
                printf("\n\nDeseja comecar um novo jogo? (1-sim / 2-nao): ");
                scanf("%d", &verificador);
                
                if (verificador == 1) {
                    reiniciarJogo();
                    continue;
                } else {
                    break;    
                }
            }
            
            qtdJogadas++;
        }
    }

    return 0;
}
