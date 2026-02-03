#include "gerenciadorpacotes.h"
#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int op = -1, tipo, tamanho;
    printf("\n");
    tGerenciador *geren = CriaGerenciador();
    if (!geren) return 1;

    while (op != 3) {
        printf("Escolha uma opcao:\n");
        printf("\t(1) Cadastrar um novo pacote\n");
        printf("\t(2) Imprimir um pacote especifico\n");
        printf("\t(3) Imprimir todos os pacotes e sair\n");
        printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");

        /* Lê só a opção primeiro (isso evita quebrar quando a última entrada é só "3") */
        if (scanf(" %d", &op) != 1) {
            DestroiGerenciador(geren);
            return 0; // ou 1, dependendo do que seu professor espera
        }

        if (op == 1) {
            if (scanf(" %d %d", &tipo, &tamanho) != 2) {
                DestroiGerenciador(geren);
                return 1;
            }

            tPacote *p = CriaPacote(tipo, tamanho);
            if (!p) {
                DestroiGerenciador(geren);
                return 1;
            }

            LePacote(p);
            AdicionaPacoteNoGerenciador(geren, p);
        }
        else if (op == 2) {
            /* ignorar como você pediu */
            /* MAS: se o teste mandar tipo/tamanho aqui também, você tem que consumir: */
            /* scanf(" %d %d", &tipo, &tamanho); */
        }
        else if (op == 3) {
            ImprimirTodosPacotes(geren);
        }
        else {
            /* opcao inválida: só continua */
        }
    }

    DestroiGerenciador(geren);
    return 0;
}
