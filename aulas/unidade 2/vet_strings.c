#include <stdio.h>
#include <string.h>

int main() {
    int i=0, n;
    printf("Digite  tamanho do vetor de strings\n");
    scanf("%d", &n);

    char vet_str[n][50];

    while (i<n) {
        scanf(" %s", vet_str[i]);
        i++;
    }    
    
    i--;
    while (i >= 0) {
        printf("%s\n", vet_str[i]);
        i--;       
    }
    
    return 0;
}