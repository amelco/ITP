#include<stdio.h>
#include<stdlib.h>

unsigned long long int fatorial(unsigned int num){
    if (num == 1 || num == 0) {
        return 1;
    } else {
        return num * fatorial(num - 1);
    }
    
}

int main(void){
    unsigned int a;
    printf("Digite um número: ");
    scanf("%u", &a);
    printf("O fatorial de %u é %llu\n", a, fatorial(a));
    return EXIT_SUCCESS;
}