#include <stdio.h>

int soma_vet(int v1[], int t_v1, 
             int v2[], int t_v2, 
             int v_r[])
{
    if (t_v1!=t_v2) return 0;
    
    for (int i=0; i<t_v1; i++){
        v_r[i] = v1[i] + v2[i];
    }

    return 1;
}

int main(){
    int v1[] = {4,3,3,10,4};
    int v2[] = {7,10,3,1,8};
    int v3[] = {10,2,5,7,5,5,1};
    int v4[] = {4,8,10,6,2,3};
    int vr[5]; 

    soma_vet(v1, 5, v2, 5, vr);

    return 0;
}