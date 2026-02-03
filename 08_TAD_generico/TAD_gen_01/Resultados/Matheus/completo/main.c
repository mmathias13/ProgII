#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int type, numElem;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:\n");
    printf("Digite o vetor:\n");
    scanf("%d %d", &type, &numElem);
    tGeneric *gen = CriaGenerico(type, numElem);    
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);
    


    return 0;
}
