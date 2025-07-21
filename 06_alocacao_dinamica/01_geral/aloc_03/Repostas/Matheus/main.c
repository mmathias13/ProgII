#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main(){

    int tamanho = 0;
    scanf("%d", &tamanho);
    
    char *texto = CriaVetor(tamanho);
    LeVetor(texto, tamanho);

    ImprimeString(texto, tamanho);

    LiberaVetor(texto);

    return 0;
}