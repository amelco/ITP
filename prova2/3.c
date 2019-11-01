#include <stdio.h>

void mat2vet(int n, int m, int A[n][m], int vet[n*m]) {
    int i=0, j=0;
    int mi=1;
    int vi=0;

    vet[0] = A[0][0];
    vi++;
    
    while (vi < n*m) {
        i = mi;
        j = 1;
        while (i>=0) {
            vet[vi] = A[i][j];
            printf("%d %d\n", i, j)
            vi++;
            i--;
            j++;
        }
        mi++;
    }
}

int main() {
    int A[4][5] = {
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    int vet[20];

    mat2vet(4, 5, A, vet);

    return 0;
}