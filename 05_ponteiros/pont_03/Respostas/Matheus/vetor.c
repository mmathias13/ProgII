#include "vetor.h"
/**
 * @brief Lê dados do usuário e armazena em um vetor.
 *
 * Esta função recebe como parâmetro um vetor e seu tamanho, e lê do usuário os valores a serem armazenados no vetor.
 *
 * @param vet Ponteiro para o vetor que receberá os valores lidos.
 * @param tam Tamanho do vetor.
 */
void LeDadosParaVetor(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vet[i]);
    }
}

#include <stdio.h>

void ImprimeDadosDoVetor(int *n, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar)
{
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] < *paraTrocar)
        {
            int temp = *paraTrocar;
            *paraTrocar = vet[i];
            vet[i] = temp;
        }
    }
}

void OrdeneCrescente(int *vet, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        // Vetor da posição i até o fim
        TrocaSeAcharMenor(&vet[i + 1], tam - i - 1, &vet[i]);
    }
}
