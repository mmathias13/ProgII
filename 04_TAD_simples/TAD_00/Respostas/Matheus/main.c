#include "ponto.h"
#include <stdio.h>

// 11.1 até 11.10 P1 de Cálculo IV

int main(int argc, char const *argv[])
{
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0, distancia = 0;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    Ponto p1 = pto_cria(x1, y1);
    Ponto p2 = pto_cria(x2, y2);

    distancia = pto_distancia(p1, p2);
    printf("%g\n", distancia);

    return 0;
}
