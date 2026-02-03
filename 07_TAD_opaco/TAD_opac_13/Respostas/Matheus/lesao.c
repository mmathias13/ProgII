#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesao.h"

struct lesao
{
    char id[TAM_ID];
    char diagnostico[TAM_DIAG];
    char regiao[TAM_REG];
    int porcentagem;
};

/**
 * @brief Cria uma estrutura do tipo lesão
 * 
 * @return ponteiro para estrutura do tipo lesão
 */ 
tLesao* CriaLesao(){
    tLesao *l = (tLesao *)malloc(sizeof(tLesao*));
    if (l == NULL)
        exit(1);
    l->porcentagem = 0;

    return l;
}

/**
 * @brief Lê informações sobre uma lesão da entrada padrão.
 * 
 * @param l ponteiro para lesão que terá seus dados preenchidos
 */
void LeLesao(tLesao* l){
    scanf("%s\n", l->id);
    scanf("%s\n", l->diagnostico);
    scanf("%s\n", l->regiao);
    scanf("%d\n", &l->porcentagem);
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tLesao.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao a ser liberada.
 */
void LiberaLesao(tLesao* l){
    free(l);
}

/**
 * @brief Retorna o identificador da lesão.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna uma string contendo o identificador da lesão.
 */
char* GetIdLesao(tLesao* l){
    return l->id;
}

/**
 * @brief Verifica se a lesão precisa de cirurgia.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna 1 se a lesão precisa de cirurgia e 0 caso contrário.
 */
int PrecisaCirurgiaLesao(tLesao* l){
    return (l->porcentagem > 50);
}