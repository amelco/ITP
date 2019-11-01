#include <stdio.h>
#include <stdlib.h>

typedef struct matriz_t {
    int n;
    int m;
    int value[200][200];
} matriz;

void mult_m(matriz* A, matriz* B, matriz* R) {
    int acc;
    for (int i=0; i<A->n; i++) {
        for (int j=0; j<B->m; j++) {
            acc=0;
            for (int k=0; k<A->m; k++) {
                acc = acc + A->value[i][k]*B->value[k][j]; 
            }
            R->value[i][j] = acc;
        }
    }
}

void diag(matriz* A, matriz* d1,matriz* d2) {
    d1->n = 1;
    d1->m = A->m;
    d2->n = d1->n;
    d2->m = d1->m;
    for (int i=0; i<A->n; i++) {
        for (int j=0; j<A->m; j++) {
            if (i==j) d1->value[0][j] = A->value[i][j];
            if (i+j==A->m) d2->value[0][j] = A->value[i][j];
        }
    }
}

int main() {
    matriz A;
    matriz B;
    matriz R;
    matriz d1;
    matriz d2;

    A.m = 3;
    B.m = 3;
    R.m = 3;
    A.n = 3;
    B.n = 3;
    R.n = 3;

    for (int i=0; i<A.n; i++) {
        for (int j=0; j<A.m; j++) {
            A.value[i][j] = rand() % 11;
            B.value[i][j] = rand() % 11;
        }
    }

    mult_m(&A, &B, &R);

    for (int i=0; i<A.n; i++) {
        for (int j=0; j<A.m; j++) {
            printf("%d ", R.value[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    for (int i=0; i<A.n; i++) {
        for (int j=0; j<A.m; j++) {
            printf("%d ", A.value[i][j]);
        }
        printf("\n");
    }

    diag(&A, &d1, &d2);

    printf("\n");
    for (int i=0; i<d1.n; i++) {
        for (int j=0; j<d1.m; j++) {
            printf("%d ", d1.value[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i=0; i<d2.n; i++) {
        for (int j=0; j<d2.m; j++) {
            printf("%d ", d2.value[i][j]);
        }
        printf("\n");
    }



    return 0;
}