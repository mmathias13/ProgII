#include "ponto.h"
#include <stdio.h>

int main()
{

    Ponto p1, p2;
    scanf("%f %f %f %f", &p1.x, &p1.y, &p2.x, &p2.y);
    float distancia = 0;
    distancia = pto_distancia(p1, p2);
    printf("%g", distancia);

    return 0;
}