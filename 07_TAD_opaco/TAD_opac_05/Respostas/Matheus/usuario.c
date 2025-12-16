#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

struct Usuario{
    char nome[20];
    int cpf[12];
};

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario(){
    tUsuario *u = (tUsuario *)malloc(sizeof(tUsuario));
    if (u == NULL)
        exit(1);
    
    return u;
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user){
    free(user);
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user){
    scanf(" %s", user->nome);
    scanf("%s", user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}