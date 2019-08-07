#include <stdio.h>

int main(){
  int a;
  int cont = 0;
  
  printf("Digite um número:\n");
  scanf("%d", &a);
  
  int i = 1;
  while (i <= a){
    if (a % i == 0){
      cont++;
    }
    i++;
  }
  printf("O numero %d tem %d divisores\n", a, cont);
}
