#include <stdio.h>
#include <stdlib.h>

int main() {
    int* vet = NULL;
    int tam = 0;
    char res;
    int i = 0;

    // vet = (int*) malloc(sizeof(int) * 1);

    printf("deseja inserir elemento ao vetor: \n");
    scanf(" %c", &res);
    while (res == 's'){
        tam++;
        vet = (int*) realloc(vet, sizeof(int) * tam);
        printf("valor:\n");
        scanf("%d", &vet[i]);
        i++;
        printf("deseja inserir elemento ao vetor: \n");
        scanf(" %c", &res);
    }
    
    for (int i=0; i<tam; i++) 
        printf("vet[%d] = %d\n", i, vet[i]);

    free(vet);


    return 0;
}