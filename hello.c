#include <stdio.h>

int soma(int a, int b){
    return a + b;
}

int main(){
    int a;
    int b;
    printf("Digite um inteiro:");
    scanf("%d", &a);
    printf("Digite outro inteiro:");
    scanf("%d", &b);
    printf("%d + %d é %d\n", a, b, soma(a, b));

    return 0;
}