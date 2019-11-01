#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);

    numero % 2 == 0 ? printf("numero %d é par\n", numero) : printf("numero %d é impar\n", numero);

    return 0;
}
