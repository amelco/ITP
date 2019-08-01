#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);

    if (numero % 2 == 0) // par
        printf("numero %d é par\n", numero);
    else { // ímpar
        printf("numero %d ", numero);
        printf("é impar\n");
    }

    return 0;
}
