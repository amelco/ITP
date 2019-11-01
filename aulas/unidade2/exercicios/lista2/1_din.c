#include <stdio.h>
#include <stdlib.h>

typedef struct matriz_t {
    int nl;
    int nc;
    int** values;
} matriz;

void aloca_matriz(matriz* A) {
    printf("Aloca\n");
    A->values = malloc(sizeof(int*) * A->nl);
    printf("!!!!!!");
    for (int i=0; i<A->nc; i++) {
        printf("%d ", i);
        A->values[i] = malloc(sizeof(int) * A->nc);
    }
}

void desaloca_matriz(matriz* A) {
    printf("desaloca\n");
    for (int i=0; i<A->nc; i++)
        free(A->values[i]);
    free(A->values);
}

void print_matriz(matriz* A) {
    printf("imprime\n");
    for (int i=0; i<A->nl; i++) {
        for (int j=0; j<A->nc; j++)
            printf("%3d", A->values[i][j]);
        printf("\n");
    }
}

int main() {
    printf("!@!!\n");
    matriz A;
    A.nl = 4;
    A.nc = 2;

    aloca_matriz(&A);
    for (int i=0; i<A.nl; i++)
        for (int j=0; j<A.nc; j++)
            A.values[i][j] = i+j;
    print_matriz(&A);
    desaloca_matriz(&A);

    return 0;
}