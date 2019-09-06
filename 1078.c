#include <stdio.h>

int mul(int a, int b) {
    return a * b;
}

int main() {
    int a, i;

    printf("Digite o num da tabela de tabuada ");
    scanf("%d", &a);

    for (i=1; i<=10; i++) {
        printf("%d x %d = %d\n", a, i, mul(a, i));
    }
    printf("\n");

    i=1;
    while (i<=10) {
        printf("%d x %d = %d\n", a, i, mul(a, i));
        i++;
    }
    printf("\n");

    i=1;
    do {
        printf("%d x %d = %d\n", a, i, mul(a, i));
        i++;
    } while (i<=10);
    
    return 0;
}