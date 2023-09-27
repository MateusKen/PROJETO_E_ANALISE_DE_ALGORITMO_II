#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int somaV(int vet[], int n){
  int cont = 0;
  for(int i = 0; i < n; i++) cont += vet[i];
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
    int count = 0;
    for(int i; arr[i]!='\0'; i++)
    {  
      count++;
    }
    return count;
}


bool valida(int** vet[], int total, int x, int n){
  for(int i = 0; i < x; i++){
    if(somaV(vet[i], n) > (total/x)) return false;
  }
  return true;
}


void backup(int** solucao[], int vet[], int n, int x, int total, int row, int col){
  if((lenght(solucao[0])+lenght(solucao[1])) == n){ // caso base
    printf("%d GB\n", total);
    printf("Pendrive A (%d GB)\n", total/2);
    for(int i = 0; i < lenght(solucao[0]); i++)
      printf("%d GB", solucao[0][i]);
    printf("Pendrive B (%d GB)\n", total/2);
    for(int i = 0; i < lenght(solucao[1]); i++)
      printf("%d GB", solucao[1][i]);
    return;
  }

  for(int i = 0; i < lenght(vet); i++){
    solucao[row][col] = vet[i];
    if(valida(solucao[row][col], total, x, n) == true){
      
    }
  }
  
}

int main(void) {
  FILE* ptr;
  ptr = fopen("file/backup.txt", "r");
  if (NULL == ptr) {
        printf("file can't be opened \n");
    exit(1);
    }

  int x, total, n, obj;
  fscanf(ptr, "%d", &x);
  
  int** solucao = (int**)malloc(x * sizeof(int*));
  
  fscanf(ptr, "%d %d", &total, &n);
  
  do{
    int *vet[n]; // vetor que guarda tamanho de cada arquivo
    for(int i = 0; i < x; i++){ //inicia a matriz de solucoes
      solucao[i] = (int*)malloc(n*sizeof(int));
    }
    
    for(int i = 0; i < n; i++){
      fscanf(ptr, "%d", &obj);
      *vet[i] = obj;
    }
    printf(vet, n);

    
}while(fscanf(ptr, "%d %d", &total, &n) != EOF); // para no fim do arquivo
  
  
  return 0;
}