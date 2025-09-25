#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero = 0, contador = 1;

    scanf("%d", &numero);

    for (int i = 0; i <= numero; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", contador);
            contador++;
        }
        printf("\n");
    }

    return 0;
}
