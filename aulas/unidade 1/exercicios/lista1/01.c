#include <stdio.h>

int arredondar(float num){
    if ((num - (int)num) * 10 >= 5) return (int)num+1;
    else return (int)num;
}

int arredonda10(int num){
    if (num%10 >= 5) return num - num%10 + 10;
    else return num - num%10;
}

int main(){
    printf("%d\n", arredondar(0.7));
    printf("%d\n", arredondar(0.4));
    printf("%d\n", arredondar(15.5));
    printf("%d\n", arredondar(16.8));
    printf("%d\n", arredonda10(15));
    printf("%d\n", arredonda10(21));
    printf("%d\n", arredonda10(25));
    printf("%d\n", arredonda10(31));


    return 0;
}
