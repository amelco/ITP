#include <stdio.h>

int main(){
    int num[20];
    int soma = 0;
    float media = 0.0;

    for (int i=0; i<20; i++){
        scanf("%d", &num[i]);
        soma += num[i];
    }
    for (int i=0; i<20; i++){
        if (num[i]%5==0) printf("%d ", num[i]);
    }
    media = soma / 20.0;
    printf("\nNúmeros maiores que a média.\n");
    for (int i=0; i<20; i++){
        if (num[i]>media) printf("%d ", num[i]);
    }
    printf("\nNúmeros menores que a média.\n");
    for (int i=0; i<20; i++){
        if (num[i]<media) printf("%d ", num[i]);
    }
    printf("\n");
}