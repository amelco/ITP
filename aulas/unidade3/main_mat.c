#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"
#include "matrizes_struct.h"

int main()
{
    int m = 2, n = 2;
    int m1[n][m];
    int m2[n][m];
    int mr[n][m];

     for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            m1[i][j] = rand() % 11;
            m2[i][j] = rand() % 11;
        }
    }

    matSub(n, m, mr, m1, m2);
    matSum(n, m, mr, m1, m2);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", mr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    matriz A, B, R;
    A.m = m; A.n = n;
    B.m = m; B.n = n;
    R.m = m; R.n = n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            A.valores[i][j] = rand() % 11;
            B.valores[i][j] = rand() % 11;
        }
    }

    matSub_struct(&R, &A, &B);
    matSum_struct(&R, &A, &B);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", R.valores[i][j]);
        }
        printf("\n");
    }

    return 0;
}