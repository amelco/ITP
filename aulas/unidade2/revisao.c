#include <stdio.h>

void funcao (int l, int c, int matriz[l][c], int res[l][c], int n) {
    return;
}

int main() {
    
    int A[4][4];
    int B[5][5];
    int R[5][5];

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    funcao(l, c, A, R, 4);

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            printf("%d " A[i][j]);
        printf("\n");
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            printf("%d " R[i][j]);
        printf("\n");
    }
    
    funcao(l, c, B, R, 5);

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            printf("%d " B[i][j]);
        printf("\n");
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            printf("%d " R[i][j]);
        printf("\n");
    }

    return 0;
}