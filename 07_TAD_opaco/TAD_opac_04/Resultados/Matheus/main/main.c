#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(int argc, char const *argv[])
{
    int nAlunos = 0;
    scanf("%d", &nAlunos);

    for (int i = 0; i < nAlunos; i++){
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        if(VerificaAprovacao(aluno)){
            ImprimeAluno(aluno);
        }
        ApagaAluno(aluno);
    }

    return 0;
}
