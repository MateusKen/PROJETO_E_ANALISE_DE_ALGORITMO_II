#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void insertion_sort(int *v, int n) {
  int i, j, aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    for (j = i - 1; j >= 0 && v[j] > aux; j--) {
      v[j + 1] = v[j];
    }
    v[j + 1] = aux;
  }
}

int somaV(int vet[], int n){
  int cont = 0;
  for(int i = 0; vet[i]!='\0'; i++) cont += vet[i];
  return cont;
}

void printVet(int *vet[], int n){
  printf("[");
  for(int i =0; i < n; i++){
    if(i == n-1){
      printf("%d", *vet[i]);
    }
    printf("%d,", *vet[i]);
  }
  printf("]\n");
}

int lenght(int arr[])
{
    int cont = 0;
    for(int i = 0; arr[i]!='\0'; i++)
    {
      cont++;
    }
    return cont;
}


void backup(int a[], int b[], int vet[], int n, int total){
  if((lenght(a)+lenght(b)) == n){ // caso base
    printf("%d GB\n", total);
    printf("Pendrive A (%d GB)\n", total/2);
    for(int i = 0; i < lenght(a); i++)
      printf("%d GB", a[i]);
    printf("Pendrive B (%d GB)\n", total/2);
    for(int i = 0; i < lenght(b); i++)
      printf("%d GB", b[i]);
  }
  
  for(int i = 0; i < lenght(vet); i++){
    a[i] = vet[i];
    if(somaV(a, n) <= total/2) backup(a, b, vet, n, total); // solução válida
    else{
      a[i] = 0;
      b[i] = vet[i];
    }
  }
}

int main(void) {
  FILE* ptr;
  ptr = fopen("file/backup.txt", "r");
  if (NULL == ptr) 
  {
    printf("file can't be opened \n");
    exit(1);
  }

  int x, total, n, obj;
  /*
  x: é o número de pendrives
  total: é o total de armazenamento dos dois pendrives
  n: é o número de arquivos
  obj: é a variável que guarda o tamanho de cada arquivo
  */
  
  fscanf(ptr, "%d", &x); 
  fscanf(ptr, "%d %d", &total, &n);

  int a[n]; // inicia pendrive A
  int b[n]; // inicia pendrive B
  
  do{
    int vet[n]; // vetor que guarda tamanho de cada arquivo
    for(int i = 0; i < n; i++){
      fscanf(ptr, "%d", &obj);
      vet[i] = obj;
    }
    insertion_sort(vet, n); // ordena o vetor dos arquivos
    
}while(fscanf(ptr, "%d %d", &total, &n) != EOF); // para no fim do arquivo
  return 0;
}
