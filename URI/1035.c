#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c;
    float delta=0, r1=0, r2=0;
    
    scanf("%f %f %f", &a, &b, &c);
    delta = pow(b, 2) - 4*a*c;
    if (delta < 0 || a == .0) printf("Impossivel calcular\n");
    else {
        r1 = (-b + sqrt(delta)) / (2*a);
        r2 = (-b - sqrt(delta)) / (2*a);
        printf("R1 = %.5f\nR2 = %.5f\n", r1, r2);
    }
    

    return 0;
}
