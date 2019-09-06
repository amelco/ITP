#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int xyrand(int min, int max){
    return rand() % max + min;
}

int main(){
    srand(time(NULL));
    for (int i=0; i<20; i++){
        printf("%d\n", xyrand(2, 12));
    }

    return 0;
}
