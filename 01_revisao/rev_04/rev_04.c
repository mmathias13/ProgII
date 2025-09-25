#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numeroDecimal = 0, vetorOctal[50], i = 0;

    scanf("%d", &numeroDecimal);

    if (numeroDecimal == 0){
        printf("0\n");
        return 0;
    }

    while (numeroDecimal > 0){
        vetorOctal[i] = numeroDecimal % 8;
        numeroDecimal = numeroDecimal / 8;
        i++; 
    }

    for (int j = i - 1; j >= 0; j--){
        printf("%d", vetorOctal[j]);
    }


    return 0;
}
