#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int M, N;
int mapa[MAX][MAX];
int visitado[MAX][MAX];
char direcao[5];
int caminho[MAX * MAX][2];
int achou = 0;
int tam_caminho = 0;

// Direções: cima, baixo, direita, esquerda
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Retorna o índice da direção correspondente ao caractere
int direcao_index(char c) {
    switch (c) {
        case 'C': return 0;  // cima
        case 'B': return 1;  // baixo
        case 'D': return 2;  // direita
        case 'E': return 3;  // esquerda
        default: return -1;
    }
}

void dfs(int x, int y, int xf, int yf) {
    if (achou || x < 0 || x >= M || y < 0 || y >= N || mapa[x][y] == 1 || visitado[x][y])
        return;

    visitado[x][y] = 1;
    caminho[tam_caminho][0] = x + 1; // para imprimir a posição 1-indexada
    caminho[tam_caminho][1] = y + 1;
    tam_caminho++;

    if (x == xf && y == yf) {
        achou = 1;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int dir = direcao_index(direcao[i]);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dfs(nx, ny, xf, yf);
        if (achou) return;
    }
}

int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &mapa[i][j]);

    int xi, xj, xf, yf;
    scanf("%d %d %d %d", &xi, &xj, &xf, &yf);
    scanf("%s", direcao);

    dfs(xi - 1, xj - 1, xf - 1, yf - 1);

    for (int i = 0; i < tam_caminho; i++) {
        printf("(%d,%d) ", caminho[i][0], caminho[i][1]);
    }
    printf("\n");

    return 0;
}
