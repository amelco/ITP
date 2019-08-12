#include <stdio.h>

void ordena(int *v, int tam){
    int i, j, aux;
    for(i=0; i<tam; i++){
        for(j=i+1; j<tam; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main(){
    int v[] = {5,4,3,2,1};
    printf("[%d,%d,%d,%d,%d]\n",v[0],v[1],v[2],v[3],v[4]);
    ordena(v, 5);
    printf("[%d,%d,%d,%d,%d]\n",v[0],v[1],v[2],v[3],v[4]);
    return 0;
}