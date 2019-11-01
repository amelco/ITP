#include <stdio.h>

typedef enum bool_t {
    false=0,
    true
} bool;

typedef struct matriz_t {
    int n;
    int m;
    int value[10][10];
} matriz;


bool verifica_simetria(int n, int A[n][n], int pos_i[50], int pos_j[50]) {
    int ii=0;
    int ij=0;
    bool simetrico = true;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (i!=j) {
                if (A[i][j] != A[j][i]) {
                    pos_i[ii] = i;
                    pos_j[ij] = j;
                    pos_i[ii+1] = -1;
                    pos_j[ij+1] = -1;
                    simetrico = false;
                    // printf ("%d, %d\n", i, j);
                }
            }
        }
    }
    return simetrico;
}

int main() {
    int M1[3][3] = {{1,2,5},
                   {2,2,6},
                   {5,6,3}};
    int M2[3][3] = {{1,7,5},
                   {2,2,6},
                   {3,6,3}};
    int pos_i[50];
    int pos_j[50];

    if(verifica_simetria(3, M2, pos_i, pos_j)) {
        printf("Matriz simétrica.\n");
    } else {
        printf("Matriz não simétrica pois os seguintes elementos são diferentes: ");
        int i = 0;
        while (pos_i[i]>=0) {
            printf("[%d, %d]\n", pos_i[i], pos_j[i]);
            i++;
        }
    }

    return 0;
}