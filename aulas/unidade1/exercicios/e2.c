#include <stdio.h>

int main(){
    char o;
    int n;
    int i = 0;
    int j = 0;

    scanf("%c", &o);
    scanf("%d", &n);

    if (o == 'c'){
        while (j < n){
            while (i < n) {
                printf("%c", '*');
                i++;
            }
            printf("%c", '\n');
            j++;
            i=0;
        }
    }
    

    return 0;
}