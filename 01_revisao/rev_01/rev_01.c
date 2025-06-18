#include <stdio.h>
#include <math.h>

int main()
{

    float Xalvo = 0, Yalvo = 0, Ralvo = 0, Xdisparo = 0, Ydisparo = 0, Rdisparo = 0;
    scanf("%f %f %f %f %f %f", &Xalvo, &Yalvo, &Ralvo, &Xdisparo, &Ydisparo, &Rdisparo);
    if (sqrt(pow(Xalvo - Xdisparo, 2) + pow(Yalvo - Ydisparo, 2)) <= Rdisparo + Ralvo)
    {
        printf("ACERTOU");
    }
    else
        printf("ERROU");

    return 0;
}