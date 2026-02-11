#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno
{
    char nome[100];
    char nascimento[100];
    char curso[100];
    char periodoIngresso[100];
    int conclusao;
    float coeficiente;
};


Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **alunos = (Aluno **)malloc(numeroAlunos * sizeof(Aluno*));
    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *a = (Aluno *)malloc(sizeof(Aluno));

    strcpy(a->nome, nome);
    strcpy(a->nascimento, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodoIngresso, periodoIngresso);
    a->conclusao = percConclusao;
    a->coeficiente = CRA;


    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[100], nascimento[100], curso[100], periodoIngresso[100];
    int conclusao;
    float coeficiente;

    for (int i = 0; i < numeroAlunos; i++){
        scanf("%*[^a-zA-Z]"); //Limpa o buffer
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", nascimento);
        scanf("%[^\n]\n", curso);
        scanf("%[^\n]\n", periodoIngresso);
        scanf("%d\n", &conclusao);
        scanf("%f\n", &coeficiente);

        vetorAlunos[i] = CriaAluno(nome, nascimento, curso, periodoIngresso, conclusao, coeficiente);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for (int i = 0; i < numeroAlunos; i++){
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    int i; int tamanhoString;
    int qtdBytes = 0;
    FILE *fp;
    fp = fopen(fileName, "wb");

    //Salva quantidade de alunos
    qtdBytes += sizeof(int) * fwrite(&numeroAlunos, sizeof(int), 1, fp);

    //Escrevendo alunos
    for (i = 0; i < numeroAlunos; i++){
        //Salvando o nome
        tamanhoString = strlen(alunos[i]->nome);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->nome, sizeof(char), tamanhoString, fp);

        //Salvnado data de nascimento
        tamanhoString = strlen(alunos[i]->nascimento);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->nascimento, sizeof(char), tamanhoString, fp);

        //Salvando o curso
        tamanhoString = strlen(alunos[i]->curso);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->curso, sizeof(char), tamanhoString, fp);

        //Salvnado o periodo
        tamanhoString = strlen(alunos[i]->periodoIngresso);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->periodoIngresso, sizeof(char), tamanhoString, fp);

        //Salvnado percentual conclusão
        qtdBytes += (fwrite(&(alunos[i]->conclusao), sizeof(int), 1, fp)) * sizeof(int);

        //Salvando CR
        qtdBytes += (fwrite(&(alunos[i]->coeficiente), sizeof(float), 1, fp)) * (sizeof(float));
    }
    printf("Numero de bytes salvos: %d\n", qtdBytes);
    fclose(fp);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {

    FILE *fp = fopen(fileName, "rb");
    int numAlunos, auxTamanho, i;
    char nome[100], dataNasc[100], curso[100], periodo[100];
    int prctConclusao; float CRA;

    // Preenchendo os 100 primeiros bytes com 0 que, em termos de char, equivale a \0.
    // Lembrando que se fosse int, seria diferente, pois o memset funciona apenas com bytes
    prctConclusao = 0;
    CRA = 0;

    // Lendo numero de alunos
    fread(&numAlunos, sizeof(int), 1, fp);

    for(i = 0; i < numAlunos; i++) {
        memset(nome, 0, 100);
        memset(dataNasc, 0, 100);
        memset(curso, 0, 100);
        memset(periodo, 0, 100);

        // Lendo o nome
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(nome, sizeof(char), auxTamanho, fp);

        // Lendo a data de nascimento
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(dataNasc, sizeof(char), auxTamanho, fp);

        // Lendo curso
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(curso, sizeof(char), auxTamanho, fp);

        // Lendo periodo
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(periodo, sizeof(char), auxTamanho, fp);

        // Lendo perc aprovacao
        fread(&prctConclusao, sizeof(int), 1, fp);

        // Lendo cra
        fread(&CRA, sizeof(float), 1, fp);

        alunos[i] = CriaAluno(nome, dataNasc, curso, periodo, prctConclusao, CRA);
    }

    fclose(fp);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos) {
    int i;
    for(i = 0; i < numeroAlunos; i++) {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->nascimento);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->conclusao);
        printf("CRA: %.2f\n", alunos[i]->coeficiente);
    }
}
