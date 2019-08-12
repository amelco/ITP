#include <stdio.h>

int mult(int a, int b, int c){
    c = a * b;
    return a * b;
}

int main(){
    int a=10, b=2, c=5;
    mult(a, b, c);
    printf("%d\n", c);
    mult(10, 20, 30);
    printf("%d\n", c);
    return 0;
}