#include <stdio.h>

long int h2s(int h, int m, int s) {
    return h*3600 + m*60 + s;
}

int main() {
    int h, m, s;
    printf("Digite horas, minutos e segundos:\n");
    scanf("%d %d %d", &h, &m, &s);
    printf("Da hora 0 até %d:%d:%d se passaram %ld segundos.\n", h,m,s, h2s(h, m, s));
    return 0;
}
