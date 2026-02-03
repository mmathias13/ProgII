#include "pacote.h"
#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes {
    tPacote **pacotes;
    int numPacotes;
};

tGerenciador* CriaGerenciador() {
    tGerenciador *geren = malloc(sizeof(tGerenciador));
    if (geren == NULL) {
        printf("Erro de alocação!\n");
        return NULL;
    }
    geren->pacotes = NULL;     // <-- ESSENCIAL
    geren->numPacotes = 0;
    return geren;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac) {
    tPacote **tmp = realloc(geren->pacotes, (geren->numPacotes + 1) * sizeof(tPacote*));
    if (tmp == NULL) {
        printf("Erro de realocação!\n");
        exit(1);
    }
    geren->pacotes = tmp;

    geren->pacotes[geren->numPacotes] = pac;
    geren->numPacotes++;
}

void DestroiGerenciador(tGerenciador* geren) {
    for (int i = 0; i < geren->numPacotes; i++) {
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);  // <-- NÃO COMENTAR
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx) {
    ImprimePacote(geren->pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren) {
    for (int i = 0; i < geren->numPacotes; i++) {
        ImprimePacote(geren->pacotes[i]);
    }
}
