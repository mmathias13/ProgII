#include <stdio.h>
#include "matrix_utils.h"

int main()
{

    int op = 0, rows1 = 0, cols1 = 0, rows2 = 0, cols2 = 0;
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows1, cols1, matrix1);
    matrix_read(rows2, cols2, matrix2);

    do
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (possible_matrix_sum(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols2];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            }
            else
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            break;
        case 2:
            if (possible_matrix_sub(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols2];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            }
            else
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            break;
        case 3:
            if (possible_matrix_multiply(cols1, rows2))
            {
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1[rows1][cols1], rows2, cols2, matrix2[rows2][cols2], result[rows1][cols2]);
            }
            else
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            break;
        case 4:
            int scalar = 0, qualMatriz = 0;
            scanf("%d %d", &scalar, &qualMatriz);
            if (qualMatriz == 1)
            {
                scalar_multiply(rows1, cols1, matrix1, scalar);
            }
            else if (qualMatriz == 2)
            {
                scalar_multiply(rows2, cols2, matrix2, scalar);
            }
            break;
        case 5:
            int result[rows1][cols1];
            transpose_matrix(rows1, cols1, matrix1, result);
            break;
        }
    } while (op != 6);

    return 0;
}