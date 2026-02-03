#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct pacote
{
    void *dado;
    Type tipo;
    int tamanho;
    int soma;
};

tPacote* CriaPacote(Type type, int numElem)
{
    tPacote *p = malloc(sizeof(tPacote));
    if (p == NULL) return NULL;

    p->tipo = type;
    p->tamanho = numElem;
    p->soma = 0;

    if (p->tipo == INT) {
        p->dado = malloc((size_t)numElem * sizeof(int));
    } else {
        p->dado = malloc((size_t)numElem * sizeof(char));
    }

    if (p->dado == NULL) {
        free(p);
        return NULL;
    }

    return p;
}

void DestroiPacote(tPacote* pac)
{
    if (pac == NULL) return;
    free(pac->dado);
    free(pac);
}

void LePacote(tPacote* pac)
{
    if (pac == NULL) return;

    for (int i = 0; i < pac->tamanho; i++) {
        if (pac->tipo == INT) {
            scanf(" %d", (int*)pac->dado + i);
        } else {
            scanf(" %c", (char*)pac->dado + i);
        }
    }
}

void CalculaSomaVerificacaoPacote(tPacote* pac)
{
    if (pac == NULL) return;

    pac->soma = 0;

    for (int i = 0; i < pac->tamanho; i++) {
        if (pac->tipo == INT) {
            pac->soma += *((int*)pac->dado + i);
        } else {
            pac->soma += (unsigned char)*((char*)pac->dado + i);
        }
    }
}

void ImprimePacote(tPacote* pac)
{
    if (pac == NULL) return;

    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->soma);

    for (int i = 0; i < pac->tamanho; i++) {
        if (pac->tipo == INT) {
            printf("%d ", *((int*)pac->dado + i));
        } else {
            printf("%c", *((char*)pac->dado + i));
        }
    }

    printf("\n");
}
