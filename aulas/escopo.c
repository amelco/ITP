#include <stdio.h>
int a = 2;
int main(){
    printf("%d\n", a);
    {
        int a = 30;
        printf("%d\n", a);
    }
    printf("%d\n", a);
    return 0;
}