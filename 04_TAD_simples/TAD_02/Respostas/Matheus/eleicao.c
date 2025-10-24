#include "eleicao.h"

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    int qtdCargos;

    eleicao.presidentes[MAX_CANDIDATOS_POR_CARGO]; // Verificar
    eleicao.totalPresidentes = 0;

    eleicao.governadores[MAX_CANDIDATOS_POR_CARGO];
    eleicao.totalGovernadores = 0;

    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    eleicao.eleitores[MAX_ELEITORES];
    eleicao.totalEleitores = 0;

    scanf("%d\n", &qtdCargos);

    for (int i = 0; i < qtdCargos; i++)
    {
        
    }
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao);

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao);