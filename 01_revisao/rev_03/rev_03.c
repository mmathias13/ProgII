#include <stdio.h>

int main(int argc, char const *argv[])
{
    int qtdLivros = 0, qtdLivrosParaComprar = 0;

    scanf("%d", &qtdLivros);

    int vetorLivros[qtdLivros];

    //Trecho para leitura do vetor de livros
    for (int i = 0; i < qtdLivros; i++)
    {
        scanf("%d", &vetorLivros[i]);
    }

    //Trecho para comparação entre cada livro com os outros do vetor
    for (int i = 0; i < qtdLivros; i++)
    {
        int contadorLivrosIguais = 0;
        for (int j = 0; j < qtdLivros; j++)
        {
            if (vetorLivros[i] == vetorLivros[j])
            {
                contadorLivrosIguais += 1;
            }
        }
        if (contadorLivrosIguais == 1){
            qtdLivrosParaComprar += 1;
            printf("%d ", vetorLivros[i]);
        }
    }

    //Se não houver nenhum livro repetido: printa "NENHUM"
    if (qtdLivrosParaComprar == 0){
        printf("NENHUM\n");
    }

    return 0;
}