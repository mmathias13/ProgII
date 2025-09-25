#include <stdio.h>
#include <math.h>

int main()
{
    float xAlvo = 0, yAlvo = 0, raioAlvo = 0;
    float xDisparo = 0, yDisparo = 0, raioDisparo = 0;

    scanf("%f %f %f", &xDisparo, &yDisparo, &raioDisparo);
    scanf("%f %f %f", &xAlvo, &yAlvo, &raioAlvo);

    float distancia = sqrt(pow(xAlvo - xDisparo, 2) + pow(yAlvo - yDisparo, 2));

    if (distancia <= raioAlvo + raioDisparo) {
        printf("ACERTOU\n");
    } else {
        printf("ERROU\n");
    }

    return 0;
}
