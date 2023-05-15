// Discente: Pedro Peixoto Viana de Oliveira.
// Data: Novembro/2022

#include <stdio.h>
#include<conio.h>

char listaJogoDaVelha[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int qtdJogadas = 0;
int coordenadaXY[2];
int pontuacaoXO[3] = {0, 0, 0}; // jogador x, jogador o, empate


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


void imprimirPontuacao() {
    printf("-------------------------------------------\n");
    printf("| Jogador X: %d | Jogador O: %d | Empate: %d |\n", pontuacaoXO[0], pontuacaoXO[1], pontuacaoXO[2]);
    printf("-------------------------------------------\n\n");
}


char verificarJogadorAtual() {
    int totalDePontos = pontuacaoXO[0] + pontuacaoXO[1] + pontuacaoXO[2];
    
    if (totalDePontos % 2 == 0) { // se o número de pontos for par, então quem começa é o X
        if (qtdJogadas % 2 == 0) return 'X'; // quem começa é o X
        else return 'O';
    } else { // se o número de pontos for ímpar, então quem começa é o O e depois o X e depois o O...
        if (qtdJogadas % 2 == 0) return 'O'; // quem começa é o O
        else return 'X';
    }
    
}


void imprimirDadosDaPartida() {
    printf("\n- Qtd. Jogadas -> %d\n", qtdJogadas);
    char jogadorAtual = verificarJogadorAtual();
    printf("- Jogador atual -> %c\n", jogadorAtual);
}


void imprimirTelaJogo() {
    imprimirPontuacao();
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
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (coordenadaXY[0] == i && coordenadaXY[1] == j) {
                listaJogoDaVelha[i][j] = JogadorAtual;
                break;
            }
        }
    }
}


void limparTela() {
    for (int i = 0; i < 50; i++) {
        printf("\n");  
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
    // Empate
    } else if (!(listaJogoDaVelha[0][0] == ' ') && !(listaJogoDaVelha[0][1] == ' ') && !(listaJogoDaVelha[0][2] == ' ') && !(listaJogoDaVelha[1][0] == ' ') && !(listaJogoDaVelha[1][1] == ' ') && !(listaJogoDaVelha[1][2] == ' ') && !(listaJogoDaVelha[2][0] == ' ') && !(listaJogoDaVelha[2][1] == ' ') && !(listaJogoDaVelha[2][2] == ' ')) {
        verificador = 2;
    }
    
    if (verificador == 1) {
        if (verificarJogadorAtual() == 'X') pontuacaoXO[0]++; else pontuacaoXO[1]++;
        limparTela();
        imprimirPontuacao();
        imprimirJogoDaVelha();
        printf("\nTemos um vencedor: o jogador %c ganhou o jogo!", JogadorAtual);
        return 1;
    } else if (verificador == 2) {
        pontuacaoXO[2]++;
        limparTela();
        imprimirPontuacao();
        imprimirJogoDaVelha();
        printf("\nOcorreu um empate: nenhum dos jogadores venceu.");
        return 1;
    } else {
        return 0;
    }
}


void reiniciarJogo() {
    qtdJogadas = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            listaJogoDaVelha[i][j] = ' '; // limpando o bloco
        }
    }
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
        
        if ((listaJogoDaVelha[coordenadaXY[0]][coordenadaXY[1]] == ' ')) { // verificando se já está preenchido
        
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
