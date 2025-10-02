#include <stdio.h>
#include "esfera_utils.h"

int main(int argc, char const *argv[])
{
    float area = 0, volume = 0, raio = 0;

    scanf("%f", &raio);
    area = calcula_area(raio);
    volume = calcula_volume(raio);

    printf("Area: %.2f\nVolume: %.2f\n", area, volume);

    return 0;
}
