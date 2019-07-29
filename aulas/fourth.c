#include <stdio.h>

int main(){
    int a = 55;
    int b = 3;
    int soma = a + b;
    int subtracao = a - b;
    int produto = a * b;
    float quociente = a / b;
    int resto = a % b;

    printf("%d, %d, %d, %f, %d\n", soma, subtracao, produto, quociente, resto);
    
    return 0;
}