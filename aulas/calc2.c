#include <stdio.h>

enum op {sum='+', sub='-', mul='*', div='/'};

int main(){
	float a, b;
	enum op choice = sum;

    printf("Digite dois números:\n");
	scanf("%f %f", &a, &b);
    printf("Digite uma operação: [+ - * /]\n");
	scanf(" %c", &choice);
    
    switch(choice){
        case sum: printf("%.2f + %.2f = %.2f\n", a, b, a+b); break;
        case sub: printf("%.2f - %.2f = %.2f\n", a, b, a-b); break;
        case mul: printf("%.2f * %.2f = %.2f\n", a, b, a*b); break;
        case div: printf("%.2f / %.2f = %.2f\n", a, b, a/b); break;
        default: break;
    }
    
}
