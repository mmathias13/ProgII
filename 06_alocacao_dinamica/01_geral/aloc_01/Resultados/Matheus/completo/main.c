#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char const *argv[])
{

    int tamanho = 0, *vetor;
    float media = 0;

    scanf("%d", &tamanho);
    vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    media = CalculaMedia(vetor, tamanho);
    printf("%.2f\n", media);
    LiberaVetor(vetor);

    return 0;
}
