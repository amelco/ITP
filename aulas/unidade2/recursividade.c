#include <stdio.h>

void bin(int num) {
    if (num > 0) {
        bin(num/2);
        printf("%d", num%2);
    }
}

void bin_it(int num) {
    while (num/2 > 0) {
        printf("%d", num%2);
        num = num/2;
    }
    printf("%d\n", num%2);
}

int fat(int num) {
    if (num == 1) 
        return 1;
    else
        return num*fat(num-1);
}

int main() {
    long int num;
    scanf("%d", &num);
    // bin(num);
    // bin_it(num);
    printf("%ld\n", fat(num));
    return 0;
}