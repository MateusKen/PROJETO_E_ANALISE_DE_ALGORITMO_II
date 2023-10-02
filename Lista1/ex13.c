#include <stdio.h>
#include <stdbool.h>

#define N 8

// Função para verificar se uma posição é válida no tabuleiro de xadrez
bool valida(int x, int y, int sol[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && sol[x][y] == -1);
}

// Função recursiva para encontrar o percurso do cavalo
bool resolveRec(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]) {
    int k, next_x, next_y;
    if (movei == N * N)
        return true;

    // Tenta todos os próximos movimentos a partir de (x, y)
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (valida(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (resolveRec(next_x, next_y, movei + 1, sol, xMove, yMove))
                return true;
            else
                sol[next_x][next_y] = -1; // Volte atrás
        }
    }
    return false;
}

// Função principal para resolver o problema do percurso do cavalo
bool resolve(int x0, int y0) {
    int sol[N][N];
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Inicializa o tabuleiro
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            sol[x][y] = -1;
        }
    }
    // A posição inicial
    sol[x0][y0] = 0;

    // Começa a busca a partir da posição inicial
    if (!resolveRec(x0, y0, 1, sol, xMove, yMove)) {
        printf("Não há solução possível.\n");
        return false;
    } else {
        printf("Solução encontrada:\n");
        for (int x = 0; x < N; x++) {
          for (int y = 0; y < N; y++) {
            printf("%2d ", sol[x][y]);
          }
        printf("\n");
        }
        return true;
    }
}

int main() {
    int x0, y0;
    
    printf("Informe a posição inicial x0: ");
    scanf("%d", &x0);

    printf("Informe a posição inicial y0: ");
    scanf("%d", &y0);
  
    x0 = x0 - 1;
    y0 = y0 - 1;
  
    if (x0 < 0 || x0 >= N || y0 < 0 || y0 >= N) {
        printf("Posição inicial inválida.\n");
        return 1;
    }

    resolve(x0, y0);

    return 0;
}
