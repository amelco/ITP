#include <stdio.h>

int main(){
    int n = 10;
    int numeros[n];
    int i;

    for(i=0; i<n; i++){
        scanf("%d", &numeros[i]);
    }
    for(i=n-1; i>=0; i--){
        printf("%d ", numeros[i]);
    }
    printf("\n");
}