#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int tamanho = 0;
    char *vetor;
    scanf("%d", &tamanho);
    getchar();
    vetor = CriaVetor(tamanho);
    ImprimeString(vetor, tamanho);
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);

    return 0;
}
