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

    // conta(n, texto);

    // for (int i=0; i<n; i++) {
    //     printf("%s\n", texto[i]);
    // }

    return 0;
 }