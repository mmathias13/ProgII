#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{

    int tamanho = 0;
    scanf("%d", &tamanho);

    int *vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);

    float media = CalculaMedia(vetor, tamanho);
    printf("%.2f", media);

    free(vetor);

    return 0;
}