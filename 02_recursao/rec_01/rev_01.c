#include <stdio.h>
#include <string.h> // Usada para a função strlen

/**
 * @brief Imprime uma string de trás para frente utilizando recursão.
 * * @param string Um ponteiro para o início da string a ser impressa.
 */
void ImprimeInvertido(char* string) {
    // Caso Base: Se a string estiver vazia (ou chegamos ao fim dela), 
    // não fazemos nada e simplesmente retornamos.
    // O caractere nulo '\0' marca o final de uma string em C.
    if (*string == '\0') {
        return;
    }

    // Passo Recursivo: Chamamos a função para o restante da string.
    // 'string + 1' é um ponteiro para o próximo caractere da string.
    ImprimeInvertido(string + 1);

    // Ação: Após todas as chamadas recursivas terem retornado,
    // imprimimos o caractere da chamada atual.
    printf("%c", *string);
}

int main() {
    // Buffer para armazenar uma palavra. 
    // O tamanho é 1001 para acomodar 1000 caracteres mais o terminador nulo '\0'.
    char palavra[1001]; 
    int i = 0; // Índice para construir a palavra no buffer.
    char caractere; // Variável para ler cada caractere da entrada.

    printf("Digite o texto e pressione Enter. Para finalizar, pressione Ctrl+D (Linux) ou Ctrl+Z (Windows).\n");

    // Loop que lê a entrada, um caractere de cada vez, até o final do arquivo (EOF).
    while ((caractere = getchar()) != EOF) {
        // Se o caractere não for um espaço nem uma quebra de linha, 
        // ele faz parte de uma palavra.
        if (caractere != ' ' && caractere != '\n' && caractere != '\t') {
            palavra[i] = caractere;
            i++;
        } else {
            // Se encontramos um espaço ou quebra de linha, a palavra terminou.
            // Primeiro, finalizamos a string da palavra com o caractere nulo.
            palavra[i] = '\0';

            // Se a palavra não estiver vazia (para o caso de múltiplos espaços),
            // chamamos a função para imprimi-la invertida.
            if (i > 0) {
                ImprimeInvertido(palavra);
            }

            // Imprimimos o caractere de separação (espaço, quebra de linha, etc.).
            printf("%c", caractere);

            // Resetamos o índice para começar a próxima palavra.
            i = 0;
        }
    }

    // Tratamento para a última palavra do texto, caso o texto não termine
    // com um espaço ou quebra de linha.
    if (i > 0) {
        palavra[i] = '\0';
        ImprimeInvertido(palavra);
    }
    
    // Imprime uma quebra de linha ao final para formatação.
    printf("\n");

    return 0;
}