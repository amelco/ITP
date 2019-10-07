#include <stdio.h>

void box(int l, char letra){
    int aux=0;
    for (int i=0; i<l; i++){
        for (int j =0; j<l; j++){
            if (i==l/2 && j==l/2) printf("%c", letra);
            else {
                if (i==0 || j==0 || i==l-1 || j==l-1) printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    box(7,'a');
    return 0;
}
