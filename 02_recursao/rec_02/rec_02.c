#include <stdio.h>

int SomaElementosPares(int *vet, int numElementos)
{
    int soma = 0;
    for (int i = 0; i < numElementos; i++)
    {
        if (vet[i] % 2 == 0)
        {
            soma += vet[i];
        }
    }
    return soma;
}

int main()
{
    int N = 0, count = 0;
    scanf("%d", &N);
    while (count < N)
    {
        int size = 0;
        scanf("%d", &size);
        int vet[size];
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &vet[i]);
        }
        int soma = SomaElementosPares(vet, size);
        printf("%d\n", soma);
        count++;
    }
    return 0;
}