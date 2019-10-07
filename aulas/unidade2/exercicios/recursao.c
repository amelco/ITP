#include <stdio.h>
#include <math.h>

int somaalg(int x) {
    if (x<0) return somaalg(-x);
    else if (x >= 0 && x <= 9) return x;
    else return somaalg(x / 10) + x%10;
}

int main() {
    int num = 0;
    scanf("%d", &num);
    printf("%d\n", somaalg(num));
    return 0;
}