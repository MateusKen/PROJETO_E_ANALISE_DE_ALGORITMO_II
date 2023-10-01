#include <stdio.h>

int max(int x, int y) {
  return x > y ? x : y;
}

int comprimento_segmento_crescente(int *sequencia, int n) {
  int comprimento_maximo = 1;
  int comprimento_atual = 1;

  for (int i = 1; i < n; i++) {
    if (sequencia[i] >= sequencia[i - 1]) {
      comprimento_atual += 1;
    } else {
      comprimento_atual = 1;
    }

    comprimento_maximo = max(comprimento_maximo, comprimento_atual);
  }

  return comprimento_maximo;
}
// a complexidade do algoritmo é O(n)

int main() {
  int sequencia[] = {5, 10, 3, 2, 4, 7, 9, 8, 5};
  int n = sizeof(sequencia) / sizeof(sequencia[0]);

  int comprimento = comprimento_segmento_crescente(sequencia, n);

  printf("O comprimento do segmento crescente máximo é %d\n", comprimento);

  return 0;
}
