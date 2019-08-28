#include <stdio.h>

void box(int l, char letra){
    int aux=0;
    for (int i=0; i<l; i++){
        for (int j=0; j<l; j++){
            if (i==0 || j==0 || i==l-1 || j==l-1) printf("%c", '*');
            if (j==l-1)  printf("\n"); 
            if (i==l/2 && j==l/2) printf("%c", letra);
            printf("*");
        }
    }
}

int main(){
    box(3,'a');
    return 0;
}
