#include <stdio.h>

int main(){
    int a;
    int b;
    char op;
    
    printf("Digite um número: \n");
    scanf("%d", &a);
    printf("Digite outro número: \n");
    scanf("%d", &b);

    printf("Que operação deseja fazer? [+, -, *, /]\n");
    scanf("%c", &op);
    
    switch(op) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
        case '/':
            printf("%d / %d = %d\n", a, b, a / b);
    }
    

    return 0;
}
