#include <stdio.h>

int main(){
    int a, b;
    int soma = 0;
    
    printf("Digite um número:\n");
    scanf("%d", &a);
    
    do{
        printf("Digite outro número:\n");
        scanf("%d", &b);
    } while(b<=a);
    
    int i = a;

    do{
        soma += i;
        i++;
    } while(i <= b);

    printf("Soma = %d\n", soma);

    return 0;
}
