#include <stdio.h>

int main(){
    int tam=4;
    int v[4] = {1, 2, 3, 4};
    int e = 2, i;
    int count=0;

    for(i=0; i<tam; i++){
        if(v[i] == e){
            count++;
        }
    }
    if(count>0){
        printf("%d aparece %d vezes\n", e, count);
    }

    return 0;
}