#include <stdio.h>
int k = 10;

int main(){
    int a = 1 + k;
    if (a){
        int b = 2;
        a = a + b;
    }
    int b = 3;
    {
        int c = 4;
        a = a + b + c;
    }
    k = c;
    return 0;
}