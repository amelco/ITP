#include <stdio.h>

int main(){
    unsigned long int seqfib[61] = {0,1};
    for(int i=2;i<=60;i++){
        seqfib[i]=seqfib[i-1]+seqfib[i-2];
        printf("%d: %lu\n", i, seqfib[i]);
    }

    return 0;
}