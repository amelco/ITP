#include <stdio.h>
#include <string.h>

void decode(int n, char vec_cifra[n][51], int vec_desloc[n], char vec_decode[n][51]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<strlen(vec_cifra[i]); j++) {
            printf("%c", vec_cifra[i][j]-(vec_desloc[i]%90));
        }
        printf("\n");
    }
}

int main() {
    int num, i = 0;
    scanf("%d", &num);
    char vec_cifra[num][51];
    int vec_desloc[num];
    char vec_decode[num][51];

    while (i < num) {
        scanf(" %s", vec_cifra[i]);
        scanf("%d", &vec_desloc[i]);
        i++;
    }
    decode(num, vec_cifra, vec_desloc, vec_decode);

    return 0;
}