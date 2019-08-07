#include <stdio.h>

int main() {
    char string[50];
    int tam=0;

    scanf("%s", string);

    for (int i=0; i<50; i++){
        if (string[i]=='\0') {
            tam=i;
            break;
        }
    }
    printf("O tamanho da string %s é: %d\nSeu endereço é: %p\n", string, tam, &string[0]);
    return 0;
}