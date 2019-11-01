#include <stdio.h>
#include <stdlib.h>

typedef struct matriz_t {
    int nl;
    int nc;
    float values[100][100];
} matriz;

void ini_rand(matriz* A) {
    for (int i=0; i<A->nl; i++)
        for (int j=0; j<A->nc; j++)
            A->values[i][j] = rand() % 11;
}   

void transposta(matriz* A, matriz* At) {
    At->nl = A->nc;
    At->nc = A->nl;

    for (int i=0; i<A->nl; i++)
        for (int j=0; j<A->nc; j++)
            At->values[i][j] = A->values[j][i];
}

void diagonais(matriz* A, matriz* DP, matriz* DI) {
    DP->nl = A->nl;
    DP->nc = A->nc;
    DI->nl = A->nl;
    DI->nc = A->nc;
    for (int i=0; i<A->nl; i++)
        for (int j=0; j<A->nc; j++) {
            if (i==j || i < j) DP->values[i][j] = A->values[i][j];
            else DP->values[i][j] = 0;
            if (i>j) DI->values[i][j] = A->values[i][j];
            else DI->values[i][j] = 0;
        }
}

void print_matriz(matriz* A, char nome[50]) {
    printf("\nMatriz: %s\n", nome);
    for (int i=0; i<A->nl; i++) {
        printf("| ");
        for (int j=0; j<A->nc; j++) 
            printf("%.2f ", A->values[i][j]);
        printf("|\n");
    }
}

int main(){
    int a, b;
    
    printf("Digite 2 inteiros:\n");
    scanf("%d %d", &a, &b);

    matriz A, At, DP, DI;
    A.nl = a;
    A.nc = b;

    ini_rand(&A);

    print_matriz(&A, "A");
    
    transposta(&A, &At);
    print_matriz(&At, "At");

    diagonais(&A, &DP, &DI);
    print_matriz(&DP, "DP");
    print_matriz(&DI, "DI");


    return 0;
}