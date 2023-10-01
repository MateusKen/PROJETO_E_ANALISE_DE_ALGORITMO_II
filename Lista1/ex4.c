#include <stdio.h>

int contaSequencia(int vet[], int n){
  int p = vet[0], cont = 1;
  for(int i=0; i<n; i++){
    if(vet[i]!=p){
      cont++;
      p = vet[i];
    }
  }
  return cont;
}

int main() {
  int a[] = {5,2,2,3,4,4,4,4,4,1,1};
  int n = 11;
  printf("O vetor possui: %d subsequencias\n", contaSequencia(a,n));

  int b[] = {3,3,−1,−1,−1,12,12,12,3,3};
  n = 10;
  printf("O vetor possui: %d subsequencias\n", contaSequencia(b,n));

  return 0;
}
