#include <stdio.h>

void intercala(int *seq1, int n1, int *seq2, int n2, int *res) {
  int i = 0, j = 0, k = 0;

  while (i < n1 && j < n2) {
    if (seq1[i] <= seq2[j]) {
      res[k++] = seq1[i++];
    } else {
      res[k++] = seq2[j++];
    }
  }

  while (i < n1) {
    res[k++] = seq1[i++];
  }

  while (j < n2) {
    res[k++] = seq2[j++];
  }
}
// a complexidade do algoritmo é de O(n+m)

int main() {
  int seq1[] = {1, 3, 5, 7};
  int n1 = sizeof(seq1) / sizeof(seq1[0]);
  int seq2[] = {2, 4, 6, 8};
  int n2 = sizeof(seq2) / sizeof(seq2[0]);
  int res[n1 + n2];

  intercala(seq1, n1, seq2, n2, res);

  for (int i = 0; i < n1 + n2; i++) {
    printf("%d ", res[i]);
  }

  printf("\n");

  return 0;
}
