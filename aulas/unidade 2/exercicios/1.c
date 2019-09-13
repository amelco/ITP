#include <stdio.h>
#include <stdlib.h>

int main() {
    int nlA, ncA, nlB, ncB;
    int l, c;

    printf("Digite o tamanho das matrizes A e B\n");
    scanf("%d %d %d %d", &nlA, &ncA, &nlB, &ncB);

    if (nlA != nlB || ncA != ncB)
        printf("Média impossível.\n");
    else {

        int A[nlA][ncA];
        int B[nlB][ncB];
        int C[nlA][ncA];

        for (l=0; l<nlA; l++) {
            for (c=0; c<ncA; c++) {
                A[l][c] = rand() % 10;
                B[l][c] = rand() % 10;
                C[l][c] = (A[l][c] + B[l][c])/2;
            }
        }

    }
    return 0;
}