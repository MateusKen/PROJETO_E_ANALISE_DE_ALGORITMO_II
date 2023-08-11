#include <stdio.h>
#include <assert.h>
/*
1. Escreva uma função recursiva que calcula o produto de a * b, em que a e b são inteiros
maiores que zero. considere que o produto pode ser definido como a somado a si mesmo
b vezes, usando uma definição recursiva temos

a ∗ b = a se b = 1
a ∗ b = a ∗ (b − 1) + a se b > 1
*/
int ex1(int a, int b){
  if (b == 1)return a;
  return ex1(a,b-1)+1;
}

/*
2. Escreva uma função recursiva, que devolve a soma dos n primeiros inteiros ímpares.
Definição recursiva:
somaImpares(n) = 
1 se n = 1
2 ∗ (n − 1) + somaImpares(n − 1) se n > 1
*/

int somaImpares(int n){
  if (n == 1)return 1;
  return (2*n-1) + somaImpares(n-1);
}

/*
3. Escreva uma função recursiva que calcule x^n
Definição recursiva:
x^n =
1 se n = 0
x ∗ x
(n−1) se n > 0
*/

int ex3(int x, int n){
  if (n == 0) return 1;
  return x*ex3(x, n-1);
}

/*
4. Usando as funções recursivas para calcular fatorial e potência, escrever a função recursiva
que devolve o resultado da seguinte expressão:
1 + x + (x^2)/2! + (x^3)/3! + · · · + (x^n)/n!
Definição recursiva:
somatoria(x, n) = 
1 se n = 0
potencia(x, n)/fatorial(n) + somatoria(x, n − 1) se n > 0
*/
int fatorial(int n){
  if (n == 1)return 1;
  return n*fatorial(n-1);
}

int somatoria(int x, int n){
  if (n == 0) return 1;
  return ex3(x, n)/fatorial(n) + somatoria(x, n-1);
}

/*
5. Dados um vetor de inteiros v (de n elementos), escreva uma função recursiva que inverta
a posição dos seus elementos.
Entrada: v = {1, 5, 2, 7, 6, 4}
Saída: v = {4, 6, 7, 2, 5, 1}
*/
 void troca(int v[], int i, int f){
   int aux = v[i];
   v[i] = v[f];
   v[f] = aux;
 }

 int inverteVetor(int v[], int i, int f){
   if (i < f){
     troca(v, i, f);
     inverteVetor(v, i+1, f-1);
   }
 }

/*
6. Escreva uma função recursiva que devolve o maior elemento do vetor de inteiros v (de n elementos).
*/

void maior(int v[], int i, int n, int maior){
  if (i == 0) maior = v[0];
  
}
int main(void) {
  assert(somaImpares(3) == 9);
  assert(ex3(3,2) == 9);
  return 0;
}
