#include<stdio.h>
#include<stdlib.h>

size_t fatorial(size_t num){
    if (num == 1) {
        return 1;
    } else {
        return num * fatorial(num - 1);
    }
    
}

int main(void){
    size_t a;
    printf("Digite um número: ");
    scanf("%zu", &a);
    printf("O fatorial de %zu é %zu\n", a, fatorial(a));
    return EXIT_SUCCESS;
}