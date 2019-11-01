#include <stdio.h>

float preco[5] = {4.0, 4.5, 5.0, 2.0, 1.5};

int main(){
    int cod, qtd;
    scanf("%d %d", &cod, &qtd);

    printf("Total: R$ %.2f\n", qtd*preco[cod-1]);

}
