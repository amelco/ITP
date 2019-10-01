#include <stdio.h>
#include <stdlib.h>

int* make_vet(int n) {
    int* vet;

    vet = (int*)malloc(sizeof(int)*n);
    
    for (int i=0; i<n; i++) {
        vet[i] = rand() % 11;
    }
    
    return vet;
}

int main() {
    int *vet;

    vet = make_vet(5);

    for (int i=0; i<5; i++) {
        printf("%d\n", vet[i]);
    }

    free(vet);

    return 0;
}