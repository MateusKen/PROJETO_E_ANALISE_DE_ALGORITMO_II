#include <stdio.h>
#include <limits.h>

float RaizQ(float x, float x0, float e) {
  if (fabs(x * x0 - x) <= e) {
    return x0;
  } else {
    return RaizQ(x, (x0 + x / x0) / 2, e);
  }
}

int main() {
  float x = 13;
  float x0 = 3.2;
  float e = 0.001;

  float raiz = RaizQ(x, x0, e);

  printf("Raiz de %.2f com erro admissível de %.4f é %.4f\n", x, e, raiz);

  return 0;
}
