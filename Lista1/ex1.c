#include <stdio.h>

//(a) Escreva uma função recusiva para computar o mdc(x, y).

int mdc(int x, int y){
  if(x == y) return x;
  else if(x%2==0 && y%2==0) return 2*mdc(x/2,y/2);
  else if(x%2==0 && y%2!=0) return mdc(x/2,y);
  else if(x%2!=0 && y%2==0) return mdc(x,y/2);
  else if(x%2!=0 && y%2!=0 && x>y) return mdc(x-y/2,y);
  else if(x%2!=0 && y%2!=0 && x<y) return mdc(x,y-x/2);
}

//(b) Verifique suas funções para as seguintes entradas:
int main(void) {
  printf("%d\n",mdc(270,192));
  printf("%d\n",mdc(35,10));
  printf("%d\n",mdc(10,15));
  printf("%d\n",mdc(31,2));
  
  return 0;
}