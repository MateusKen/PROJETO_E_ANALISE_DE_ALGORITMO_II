#include <stdio.h>

void Binario(int n, char *binario, int posicao) {
    if (posicao == n) {
        printf("%s\n", binario);
        return;
    }

    binario[posicao] = '0';
    Binario(n, binario, posicao + 1);

    binario[posicao] = '1';
    Binario(n, binario, posicao + 1);
}

int main() {
    int n;
    printf("Digite o tamanho do binário (n): ");
    scanf("%d", &n);

    //String com n caracteres
    char binario[n];

    Binario(n, binario, 0);

    return 0;
}
