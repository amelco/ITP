#include <stdio.h>

int main(){
    char str[100] = "teste !@#$ 12345 TESTE";

    for(int i=0; i<100; i++){
        if ( (str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) ){
            if (str[i]>=97 && str[i]<=122) printf("%c", str[i]-32);
            if (str[i]>=65 && str[i]<=90) printf("%c", str[i]+32);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}