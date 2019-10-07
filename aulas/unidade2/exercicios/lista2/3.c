#include <stdio.h>
#include <string.h>

int pos_menor(int n, char str[n][51]) {
    int pos = 0;
    int menor = strlen(str[pos]);

    for (int i=0; i<n; i++){
        if (strlen(str[i]) < menor)
            menor = strlen(str[i]);
            pos = i;
    }
}

int main() {
    int n = 0, c = 0;
    char str1[51];

    printf("Entre com o numero n: ");
    scanf("%d", &n);

    char vs[n][51];

    for (int i=0; i<n; i++){
        printf("Digite a string %d: ", i+1);
        scanf(" %s", &vs[i]);
    }

    printf("Digite outra string: ");
    scanf(" %s", &str1);

    for (int i=0; i<n; i++){
        if (strcmp(str1, vs[i]) == 0) {
            printf("String encontrada na posição %d\n", i+1);
            c++;
            break;

        }
    }
    if (c == 0) printf("String não encontrada\n");

    int pmenor = pos_menor(n, vs);
    printf("%s tamanho: %d\n", vs[pmenor], strlen(vs[pmenor]));
    
    

}