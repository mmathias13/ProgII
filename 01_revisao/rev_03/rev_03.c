#include <stdio.h>

int main()
{

    int N = 0, nãoTemIgual = 1;
    ;

    // Declara um vetor de tamanho N, e utiliza um for para ler os identificadores e armazená-los no vetor.
    scanf("%d", &N);
    int livros[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &livros[i]);
    }

    // Aninhamento de for para conseguir percorrer o vetor e comparar cada item com outro. Uso da flag nãoTemIgual para indicar se foi encontrado algum livro igual ou não.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j && livros[i] == livros[j])
            {
                nãoTemIgual = 0;
                break;
            }
        }
        if (nãoTemIgual)
        {
            printf("%d ", livros[i]);
        }
    }
    if (!nãoTemIgual)
        printf("NENHUM");

    return 0;
}