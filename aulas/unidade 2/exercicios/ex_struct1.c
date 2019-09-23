#include <stdio.h>

typedef struct racional_t {
    int num;
    int den;
} racional;

typedef struct vetor_t {
    int len;
    int value[];
} vetor;


racional soma(racional* a, racional* b) {
    racional result;
    result.num = (a->num*b->den + b->num*a->den);
    result.den = (a->den*b->den);
    return result;
}

racional divide(racional* a, racional* b) {
    racional result;
    result.num = a->num*b->den;
    result.den = a->den*b->num;
    return result;
}

int main() {
    racional num1, num2, res;
    
    num1.num = 2;
    num1.den = 2;
    num2.num = 4;
    num2.den = 2;
    
    res = soma(&num1, &num2);
    
    printf("SOMA: %d/%d + %d/%d = %d/%d\n", num1.num, num1.den, num2.num, num2.den, res.num, res.den);

    res = divide(&num1, &num2);

    printf("DIVISÃO: %d/%d / %d/%d = %d/%d\n", num1.num, num1.den, num2.num, num2.den, res.num, res.den);
    
    return 0;
}