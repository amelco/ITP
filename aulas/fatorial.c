#include <stdio.h>
#include <math.h>

double fatorial(int num) {
    double fat = 1;
    for (int i=num; i>1; i--){
        fat *= num;
    }
    return fat;
}

double ex(int x){
    double e = 0;

    for (int i=1; i<=100; i++){
        e += pow(x,i) / fatorial(i);
    }

    return e;
}

int main(){
    int x;

    printf("exp(x)\n x=?\n");
    scanf("%d", &x);
    printf("exp(%d) = %lf\n", x, ex(x));
    printf("%d! = %lf\n", x, fatorial(x));
    return 0;
}