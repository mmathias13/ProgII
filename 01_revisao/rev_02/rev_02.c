#include <stdio.h>

int main()
{
    int N = 0, cont = 0;
    scanf("%d", &N);
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", cont + 1);
            cont++;
        }
        printf("\n");
    }
    return 0;
}