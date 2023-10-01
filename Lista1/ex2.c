#include <stdio.h>
#include <limits.h>

int max(int x, int y) {
  return x > y ? x : y;
}

int max_bitonic_array(int *arr, int n) {
  if (n == 1) {
    return arr[0];
  }

  int mid = n / 2;
  int left_max = max_bitonic_array(arr, mid);
  int right_max = max_bitonic_array(arr + mid, n - mid);

  return max(left_max, right_max);
}

int main() {
  int arr[] = {2, 5, 8, 7, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  int max = max_bitonic_array(arr, n);

  printf("O máximo elemento do bitonic array é: %d\n", max);

  return 0;
}
