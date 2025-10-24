#include "jogador.h"
#include "jogada.h"

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 *
 * @param idJogador o id do jogador (1 ou 2).
 *
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    if (idJogador == 1)
    {
        jogador.id = ID_JOGADOR_1;
    }
    else
    {
        jogador.id = ID_JOGADOR_2;
    }

    return jogador;
}

/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 *
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;

    printf("Digite uma posicao (x e y):\n");

    jogada = LeJogada();

    if (FoiJogadaBemSucedida(jogada))
    {
        // Implementar se a jogada foi bem-sucedida
    }
    else if (!(EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y)))
    {
        printf("Posicao invalida (OCUPADA - [%d,%d] )\n", jogada.x, jogada.y);
    }
    else
    {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d %d] )!\n", jogada.x, jogada.y);
    }
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 *
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    // Verificação se o jogador 1 venceu:
    if (jogador.id == ID_JOGADOR_1)
    {
        // Verificação de vitória para primeira coluna:
        if ((tabuleiro.posicoes[0][0] == tabuleiro.peca1) &&
            (tabuleiro.posicoes[1][0] == tabuleiro.peca1) &&
            (tabuleiro.posicoes[2][0] == tabuleiro.peca1))
        {
            return 1;
            // Verificação de vitória para segunda coluna:
        }
        else if ((tabuleiro.posicoes[0][1] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[2][1] == tabuleiro.peca1))
        {
            return 1;
        }
        // Verificação para vitória para terceira coluna:
        else if ((tabuleiro.posicoes[0][2] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[1][2] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[2][2] == tabuleiro.peca1))
        {
            return 1;
        }
        // Verificação para vitória para primeira linha:
        else if ((tabuleiro.posicoes[0][0] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[0][1] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[0][2] == tabuleiro.peca1))
        {
            return 1;
        }
        // Verificação para vitória para segunda linha:
        else if ((tabuleiro.posicoes[1][0] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[1][2] == tabuleiro.peca1))
        {
            return 1;
        }
        // Verificação para vitória para terceira linha:
        else if ((tabuleiro.posicoes[2][0] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[2][1] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[2][2] == tabuleiro.peca1))
        {
            return 1;
        }
        // Verificação para vitória da diagonal (esquerda para direita):
        else if ((tabuleiro.posicoes[0][0] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[2][2] == tabuleiro.peca1))
        {
            return 1;
        }
        // Verificação para vitória da diagonal (direita para esquerda):
        else if ((tabuleiro.posicoes[0][2] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca1) &&
                 (tabuleiro.posicoes[2][0] == tabuleiro.peca1))
        {
            return 1;
        }
    }
    // Verificação de vitória para o jogador 2:
    else
    {
        // Verificação de vitória para primeira coluna:
        if ((tabuleiro.posicoes[0][0] == tabuleiro.peca2) &&
            (tabuleiro.posicoes[1][0] == tabuleiro.peca2) &&
            (tabuleiro.posicoes[2][0] == tabuleiro.peca2))
        {
            return 1;
            // Verificação de vitória para segunda coluna:
        }
        else if ((tabuleiro.posicoes[0][1] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[2][1] == tabuleiro.peca2))
        {
            return 1;
        }
        // Verificação para vitória para terceira coluna:
        else if ((tabuleiro.posicoes[0][2] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[1][2] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[2][2] == tabuleiro.peca2))
        {
            return 1;
        }
        // Verificação para vitória para primeira linha:
        else if ((tabuleiro.posicoes[0][0] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[0][1] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[0][2] == tabuleiro.peca2))
        {
            return 1;
        }
        // Verificação para vitória para segunda linha:
        else if ((tabuleiro.posicoes[1][0] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[1][2] == tabuleiro.peca2))
        {
            return 1;
        }
        // Verificação para vitória para terceira linha:
        else if ((tabuleiro.posicoes[2][0] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[2][1] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[2][2] == tabuleiro.peca2))
        {
            return 1;
        }
        // Verificação para vitória da diagonal (esquerda para direita):
        else if ((tabuleiro.posicoes[0][0] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[2][2] == tabuleiro.peca2))
        {
            return 1;
        }
        // Verificação para vitória da diagonal (direita para esquerda):
        else if ((tabuleiro.posicoes[0][2] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[1][1] == tabuleiro.peca2) &&
                 (tabuleiro.posicoes[2][0] == tabuleiro.peca2))
        {
            return 1;
        }
    }

    return 0;
}
