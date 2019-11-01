#include <stdio.h>

int main(){
    int a = 0;
    int cont = 0;

    printf("Digite um número:\n");
    scanf("%d", &a);

    for (int i = 2; i <= a; i++){
        if (a % i == 0)
            cont++;
    }

    printf("%d\n", cont);
    return 0;
}
