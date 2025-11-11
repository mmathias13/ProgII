#include "data.h"
#include <stdio.h>

/**
 * @brief Inicializa uma data com os valores passados como parâmetro.
 *
 * Faz clamp de mês (1..12) e dia (1..qtdDiasNoMes). Ano é copiado como veio.
 */
void InicializaDataParam(int dia, int mes, int ano, tData *data){
    // Define ano antes (bissexto depende do ano)
    data->ano = ano;

    // Normaliza mês
    if (mes < 1)       data->mes = 1;
    else if (mes > 12) data->mes = 12;
    else               data->mes = mes;

    // Limita o dia com base no mês/ano atuais
    int maxDia = InformaQtdDiasNoMes(data);
    if (dia < 1)           data->dia = 1;
    else if (dia > maxDia) data->dia = maxDia;
    else                   data->dia = dia;
}

/**
 * @brief Lê uma data do usuário (dia mes ano) e inicializa a estrutura.
 */
void LeData(tData *data){
    int d, m, a;
    if (scanf("%d %d %d", &d, &m, &a) != 3){
        // Entrada inválida -> padrão seguro
        d = 1; m = 1; a = 0;
    }
    InicializaDataParam(d, m, a, data); // passa valores, não endereços
}

/**
 * @brief Imprime data no formato dd/mm/aaaa (sem quebra de linha).
 * O main já imprime '\n' depois.
 */
void ImprimeData(tData *data){
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

/**
 * @brief Verifica se o ano é bissexto.
 * Regras: múltiplo de 400 ou (múltiplo de 4 e não de 100).
 */
int EhBissexto(tData *data){
    int ano = data->ano;
    return (ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0));
}

/**
 * @brief Retorna a quantidade de dias do mês da data.
 */
int InformaQtdDiasNoMes(tData *data){
    switch (data->mes){
        case 1:  return 31;
        case 2:  return EhBissexto(data) ? 29 : 28;
        case 3:  return 31;
        case 4:  return 30;
        case 5:  return 31;
        case 6:  return 30;
        case 7:  return 31; // conserta 'data-> mes'
        case 8:  return 31;
        case 9:  return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 30; // fallback se mês vier inválido
    }
}

/**
 * @brief Avança a data para o dia seguinte.
 */
void AvancaParaDiaSeguinte(tData *data){
    int maxDia = InformaQtdDiasNoMes(data);
    if (data->dia >= maxDia){
        data->dia = 1;
        if (data->mes >= 12){
            data->mes = 1;
            data->ano++;
        } else {
            data->mes++;
        }
    } else {
        data->dia++;
    }
}

/**
 * @brief Compara duas datas.
 */
int EhIgual(tData *data1, tData *data2){
    return (data1->dia == data2->dia) &&
           (data1->mes == data2->mes) &&
           (data1->ano == data2->ano);
}
