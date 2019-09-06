#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void somaMat(int d1, int d2, int A[d1][d2], int B[d1][d2], int R[d1][d2]) {
    int i, j;

    for (i=0; i<d1; i++) {
        for (j=0; j<d2; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

void printMat(int d1, int d2, int A[d1][d2]) {
    int i, j;
    for (i=0; i<d1; i++) {
        for (j=0; j<d2; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n, m;
    int i, j;
    srand(time(NULL));

    printf("Digite n e m:\n");
    scanf("%d %d", &n, &m);
    
    int mat1[n][m];
    int mat2[n][m];
    int res[n][m];
    
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;

        }
    }

    somaMat(n, m, mat1, mat2, res);

    printMat(n, m, mat1);
    printMat(n, m, mat2);
    printMat(n, m, res);

    return 0;
}