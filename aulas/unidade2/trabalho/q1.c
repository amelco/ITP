#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matriz_t {
    int nl;
    int nc;
    int values[100][100];
} matriz;

typedef struct posicao_t {
    int i;
    int j;
} posicao;

void init_matriz(matriz* A) {
    A->nl = rand() % 5 + 1;
    A->nc = rand() % 5 + 1;
    // A->nl = 3;
    // A->nc = 3;
    for (int i=0; i<A->nl; i++) 
        for (int j=0; j<A->nc; j++) {
            A->values[i][j] = rand() % 10;
        }
}

void print_matriz(matriz* A, char nome[50]) {
    printf("\nMatriz: %s\n", nome);
    for (int i=0; i<A->nl; i++) {
        printf("| ");
        for (int j=0; j<A->nc; j++) 
            printf("%d ", A->values[i][j]);
        printf("|\n");
    }
}

void verifica_rep(int elemento, posicao* pos, matriz* A) {
    for (int i=0; i<A->nl; i++) {
        for (int j=0; j<A->nc; j++) {
            if (i != pos->i && j != pos->j)
                if (elemento == A->values[i][j])
                    printf("e=%d : %d %d\n", elemento, i, j);
        }
    }
}

void duplicados(matriz* A, matriz* DUP) {
    int elemento;
    posicao pos;

    // percorre matriz elemento por elemento e armazena elemento atual
    for (int i=0; i<A->nl; i++) {
        for (int j=0; j<A->nc; j++) {
            elemento = A->values[i][j];
            pos.i = i;
            pos.j = j;
            verifica_rep(elemento, &pos, A);
        }
    }
}

int main() {
    srand(time(NULL));

    matriz A, DUP;

    init_matriz(&A);
    print_matriz(&A, "A");
    duplicados(&A, &DUP);

    return 0;
}