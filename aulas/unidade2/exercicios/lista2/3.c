#include <stdio.h>
#include <string.h>

int pos_menor(int n, char str[n][51]) {
    int pos = 0;
    int menor = strlen(str[pos]);

    for (int i=0; i<n; i++){
        if (strlen(str[i]) < menor) {
            menor = strlen(str[i]);
            pos = i;
        }
    }
    return pos;
}

int pos_maior(int n, char str[n][51]) {
    int pos = 0;
    int maior = strlen(str[pos]);

    for (int i=0; i<n; i++){
        if (strlen(str[i]) > maior) {
            maior = strlen(str[i]);
            pos = i;
        }
    }
    return pos;
}

float media(int n, char str[n][51]) {
    int soma = 0;

    for (int i=0; i<n; i++)
        soma += strlen(str[i]);
    
    return (float)soma/n;
}

void substitui(int n, char vs[n][51], int pos, char subs[51]) {
    for (int i=0; i<n; i++) {
        if (i == pos) strcpy(vs[i], subs);
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

    printf("\nDigite outra string: ");
    scanf(" %s", &str1);

    for (int i=0; i<n; i++){
        if (strcmp(str1, vs[i]) == 0) {
            printf("\nString encontrada na posição %d\n", i);
            c++;
            break;
        }
    }
    if (c == 0) printf("String não encontrada\n\n");

    int pmenor = pos_menor(n, vs);
    int pmaior = pos_maior(n, vs);
    printf("%s tamanho: %d\n", vs[pmenor], strlen(vs[pmenor]));
    printf("%s tamanho: %d\n", vs[pmaior], strlen(vs[pmaior]));
    printf("média dos tamanhos: %.2f\n", media(n, vs));
    
    char subs[51];
    int pos = 0;
    printf("Entre com a string que deseja substituir:\n");
    scanf("%s", subs);
    printf("Entre com a posição para substituição: ");
    scanf("%d", &pos);

    substitui(n, vs, pos, subs);
    
    printf("\n");
    for (int i=0; i<n; i++)
        printf("%s\n", vs[i]);

}