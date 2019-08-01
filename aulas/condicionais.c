#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);
    
    int val2 = numero > 2;
    printf("%d\n", val2);
    
    if (numero){
        printf("numero %d é verdadeiro\n", numero);
    } else {
        printf("numero %d é falso\n", numero);
    }
    
    if (numero % 2 == 0) // par
        printf("numero %d é par\n", numero);
    if (numero % 2 != 0){ // ímpar
        printf("numero %d ", numero);
        printf("é impar\n");
    }
    return 0;
}
