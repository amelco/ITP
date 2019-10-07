#include <stdio.h>

void imprime(int vet[], int t) {
    if (t==0)
        printf("%d\n", vet[t]);
    else {
        printf("%d ", vet[t]);
        imprime(vet, t-1);
    }
}

int main() {
    int vet[] = {0, 1, 2, 3, 4, 5, 6};

    imprime(vet, 6);

    return 0;
}