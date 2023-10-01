#include <stdio.h>

int max(int x, int y) {
  return x > y ? x : y;
}

int max_sum_kadane(int *seq, int n) {
  int max_sum = seq[0];
  int sum = seq[0];
  for (int i = 1; i < n; i++) {
    sum = max(sum + seq[i], seq[i]);
    max_sum = max(max_sum, sum);
  }
  return max_sum;
}

int main() {
  int seq[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
  int n = sizeof(seq) / sizeof(seq[0]);
  int max_sum = max_sum_kadane(seq, n);
  printf("A soma máxima do segmento é %d\n", max_sum);
  return 0;
}
