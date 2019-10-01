#include <stdio.h>
#include <stdlib.h>

int main() {
    int* vet;
    int tam;

    printf("tamanho do vetor: \n");
    scanf("%d", &tam);
    vet = (int*) malloc(sizeof(int) * tam);

    for (int i=0; i<tam; i++) 
        scanf("%d", &vet[i]);    
    
    for (int i=0; i<tam; i++) 
        printf("vet[%d] = %d\n", i, vet[i]);


    return 0;
}