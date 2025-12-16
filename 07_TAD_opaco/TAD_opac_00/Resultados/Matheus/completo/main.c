#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

int main(void) {
    float cx, cy, r, px, py;

    if (scanf("%f %f %f %f %f", &cx, &cy, &r, &px, &py) != 5) {
        return 0;
    }

    tCirculo c = Circulo_Cria(cx, cy, r);
    tPonto p = Pto_Cria(px, py);

    printf("%d\n", Circulo_Interior(c, p));

    Pto_Apaga(p);
    Circulo_Apaga(c);

    return 0;
}
