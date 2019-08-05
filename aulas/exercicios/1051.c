#include <stdio.h>

int main(){
    float sal = 0.0;
    float imp = 0.0;
    
    do{
        scanf("%f", &sal);
    } while (sal < 0.0);
    

    if (sal >= 2000.01 && sal <= 3000.0){
        imp = (sal-2000.0)*0.08;
    } 
    if (sal >= 3000.01 && sal <= 4500.0){
        imp += (sal-2000.0)*0.18;
    } 
    if (sal > 4500.0) {
        imp += (sal-2000.0)*0.28;
    }
    
    printf("R$ %.2f\n", imp);

    return 0;
}
