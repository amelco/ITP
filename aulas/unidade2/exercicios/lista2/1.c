#include <stdio.h>

typedef struct matriz_t {
    int nl;
    int nc;
    float values[100][100];
} matriz;

void le_matriz(matriz* A) {
    for (int i=0; i<A->nl; i++) 
        for (int j=0; j<A->nc; j++) {
            scanf("%f", &A->values[i][j]);
            // printf("%f\n", A->values[i][j]);
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

float minimo(matriz* A) {
    float min = A->values[0][0];
    for (int i=0; i<A->nl; i++) 
        for (int j=0; j<A->nc; j++)
            if (A->values[i][j] < min)
                min = A->values[i][j];
    return min;
}

float maximo(matriz* A) {
    float max = A->values[0][0];
    for (int i=0; i<A->nl; i++) 
        for (int j=0; j<A->nc; j++)
            if (A->values[i][j] > max)
                max = A->values[i][j];
    return max;
}
float medio(matriz* A) {
    float soma = 0;
    for (int i=0; i<A->nl; i++) 
        for (int j=0; j<A->nc; j++)
            soma += A->values[i][j];
    return (float)soma / (A->nl * A->nc);
    
}

void soma_matrizes (matriz* A, matriz* B, matriz* R) {
    if (A->nl != B->nl || A->nc != B->nc) {
        printf("Soma impossível\n");
        return;
    }
    R->nl = A->nl;
    R->nc = A->nc;
    for (int i=0; i<A->nl; i++)
        for (int j=0; j<A->nc; j++)
            R->values[i][j] = A->values[i][j] + B->values[i][j];
}

void media_matrizes (matriz* A, matriz* B, matriz* R) {
    if (A->nl != B->nl || A->nc != B->nc) {
        printf("Média impossível\n");
        return;
    }
    for (int i=0; i<A->nl; i++)
        for (int j=0; j<A->nc; j++)
            R->values[i][j] = (A->values[i][j] + B->values[i][j]) / 2.0;
}

int main() {
    matriz A, B, C;

    printf("Número de linhas e colunas da matriz A: ");
    scanf("%d %d", &A.nl, &A.nc);
    printf("Número de linhas e colunas da matriz B: ");
    scanf("%d %d", &B.nl, &B.nc);
    
    printf("Digite os elementos da matriz A:\n");
    le_matriz(&A);
    printf("Digite os elementos da matriz B:\n");
    le_matriz(&B);

    print_matriz(&A, "A");
    print_matriz(&B, "B");

    soma_matrizes(&A, &B, &C);
    print_matriz(&C, "A+B");
    
    media_matrizes(&A, &B, &C);
    print_matriz(&C, "média(A, B)");

    printf("\nMáximo de A:%.2f\nMáximo de B:%2.f\n", maximo(&A), maximo(&B));
    printf("\nMínimo de A:%.2f\nMínimo de B:%2.f\n", minimo(&A), minimo(&B));
    printf("\nMédio de A :%.2f\nMédio de B :%2.f\n", medio(&A), medio(&B));

    return 0;
}