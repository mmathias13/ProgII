#include <stdio.h>

int main()
{
    int decimal;
    scanf("%d", &decimal);

    int octal[100];  // vetor para armazenar os dígitos octais
    int i = 0;

    if (decimal == 0) {
        printf("0\n");
        return 0;
    }

    // conversão
    while (decimal > 0)
    {
        octal[i] = decimal % 8;
        decimal /= 8;
        i++;
    }

    // imprime os dígitos de trás para frente
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }

    printf("\n");
    return 0;
}
