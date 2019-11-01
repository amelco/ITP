/* Vetores multidimensionais */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void soma() {

}

// void printMatriz(int matriz[][], n, m) {
//     int i, j;
//     for (i=0; i<n; i++) {
//         for (j=0; j<m; j++) {
//             printf("%d ", matriz[i][j]);
//         }
//     }
// // }

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
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    } 
    printf("\n");

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    } 
    printf("\n");

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }    

    return 0;
}