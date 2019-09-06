#include <stdio.h>
#include <math.h>

int main(){
    int exp = 1, x = 0;
    printf("Digite a base da sequência de potencia\n");
    scanf("%d", &x);
    for (int i=0; i<10; i++){
        printf("%.0lf ", pow(x, exp));
        exp += 2;
    }
    printf("\n");    

    return 0;
}