#include <stdio.h>

int main(){
    int num;

    scanf("%d", &num);
    
    for (int i = 2; i*i <= num; i++){
        if (num % i == 0){
            printf("%d não primo. %d o divide.\n", num, i);
            return 0;
        }
    }
    printf("%d é primo.\n", num);

    return 0;
}
