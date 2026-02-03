#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>


struct generic{
    Type type;
    void *dado;
    int tamanho;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *tipo = (tGeneric*)malloc(sizeof(tGeneric));
    if (tipo == NULL){
        printf("Erro de alocação \n");
        return 1;
    }
    tipo->tamanho = numElem;
    tipo->type = type;
    if (tipo->type == FLOAT){
        tipo->dado = malloc(numElem * sizeof(float));
    }
    if (tipo->type == INT){
        tipo->dado = malloc(numElem * sizeof(int));
    }

    return tipo;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->dado);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    int i = 0;
    for (int i = 0; i < gen->tamanho; i++){
        if (gen->type == FLOAT){
            scanf("%f", (float *)gen->dado + i);
        }
        if (gen->type == INT){
            scanf("%d", (int *)gen->dado + i);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    int i = 0;
    for (int i = 0; i < gen->tamanho; i++){
        if (gen->type == INT){
            printf("%d ", *((int*)gen->dado + i));
        } 
        if (gen->type == FLOAT){
            printf("%.2f ", *((float*)gen->dado + i));
        }
    }
}