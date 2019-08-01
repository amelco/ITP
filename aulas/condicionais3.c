#include <stdio.h>

int main(){
    float a;
    float b;

    scanf("%f", &a);
    scanf("%f", &b);

    if (a == b){
        printf("%f\n", a * b);
    } else if (a < b) {
        printf("%f\n", b - a);
    } else {
        printf("%f\n", a - b);
    }

    return 0;
}
