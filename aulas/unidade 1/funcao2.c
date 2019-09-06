#include <stdio.h>

int mult(int a, int b, int *c){
    *c = a * b;
    return a * b;
}

void troca(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a=10, b=2, c=0;
    printf("%d\n", c);
    mult(a, b, &c);
    printf("%d\n", c);
    printf("%d %d\n", a, b);
    troca(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}