/*** QUESTAO 1 ***/
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

/*** QUESTAO 2 ***/
#include <stdio.h>
#include <string.h>

typedef struct hist_val_t {
    char str[50];
    int ocorrencia;
} hist_val;


void conta(int n, char texto[n][50]) {
    int i = 1, j, cont, ih = 0;
    char word[50];
    printf("ini");

    strcpy(word, texto[0]);
    printf("here");
    while(i<n) {
        printf("%d ", i);
        while(j<n) {
            if (strcmp(texto[j], word) == 0) {
                cont++;
            }
        }
        // strcpy(h[ih]->str, texto[i]);
        // h[ih]->ocorrencia = cont;
        printf("%s %d\n", texto[j], cont);
        ih++;
        i++;
        j = i;
        cont = 0;
    }
}

int main() {
    int n;
    hist_val histograma[1000];
    
    scanf("%d", &n);
    char texto[n][50];
    
    for (int i=0; i<n; i++) {
        scanf("%s", texto[i]);
    }

    conta(n, texto);

    // for (int i=0; i<n; i++) {
    //     printf("%s\n", texto[i]);
    // }

    return 0;
 }

 /*** QUESTAO 3 ***/
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