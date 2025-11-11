#include <stdio.h>
#include "evento.h"

void imprimeMenu() {
    printf("\n===== Menu =====\n");
    printf("1 - Cadastrar um evento\n");
    printf("2 - Exibir todos os eventos\n");
    printf("3 - Trocar data de um evento\n");
    printf("4 - Trocar a posicao entre dois eventos\n");
    printf("5 - Sair\n");
}

int main(void) {
    Evento eventos[MAX_EVENTOS];
    int numEventos = 0;
    int opcao = 0;
    int indiceA = 0, indiceB = 0; // declarar fora do switch evita problema de compilação

    while (1) {
        imprimeMenu();
        if (scanf("%d", &opcao) != 1) {
            // entrada inválida: limpa erro e consome linha
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Opcao invalida!\n");
            continue;
        }

        switch (opcao) {
            case 1:
                if (numEventos >= MAX_EVENTOS) {
                    printf("Limite de eventos atingido.\n");
                    break;
                }
                // consome o '\n' deixado pelo scanf da opcao
                {
                    int ch = getchar();
                    if (ch != '\n' && ch != EOF) {
                        // se não era newline, devolve (apenas para segurança)
                        ungetc(ch, stdin);
                    }
                }
                cadastrarEvento(eventos, &numEventos);
                break;

            case 2:
                exibirEventos(eventos, &numEventos);
                break;

            case 3:
                // A função trocarDataEvento, como definida, não recebe índice.
                // Apenas chamamos conforme sua assinatura.
                trocarDataEvento(eventos, &numEventos);
                break;

            case 4:
                if (scanf("%d %d", &indiceA, &indiceB) != 2) {
                    // limpa linha se entrada ruim
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    printf("Indices invalidos!\n");
                    break;
                }
                if (indiceA < 0 || indiceA >= numEventos ||
                    indiceB < 0 || indiceB >= numEventos) {
                    printf("Indices fora do intervalo!\n");
                    break;
                }
                trocarIndicesEventos(eventos, &indiceA, &indiceB, &numEventos);
                break;

            case 5:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}
