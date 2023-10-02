#include <stdio.h>

void imprimeSucessoesGols(int m, int n, char *sucessao, int posicao) {
    if (m == 0 && n == 0) {
        sucessao[posicao] = '\0';
        printf("%s\n", sucessao);
        return;
    }

    if (m > 0) {
        sucessao[posicao] = 'A';
        imprimeSucessoesGols(m - 1, n, sucessao, posicao + 1);
    }

    if (n > 0) {
        sucessao[posicao] = 'B';
        imprimeSucessoesGols(m, n - 1, sucessao, posicao + 1);
    }
}


int main() {
    int m, n;
    printf("Digite o número de gols de A: ");
    scanf("%d", &m);
    printf("Digite o número de gols de B: ");
    scanf("%d", &n);


    //String com (m + n) caracteres, representando as sequencias possiveis de gols
    char sucessao[m + n];
    
    imprimeSucessoesGols(m, n, sucessao, 0);

    return 0;
}
