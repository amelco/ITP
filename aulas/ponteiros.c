#include <stdio.h>

int main() {
    int a = 10;
    int *b, *c, *d;
    b = &a;
    printf("%p %d\n", b, a);
    printf("%d %d\n", *b, a);
    printf("%p %p\n", b, &a);
    c = b;
    d = &a;
    printf("%p %p %p %p\n", &a, b, c, d);
    a = 20;
    printf("%d %d %d %d\n", a, *b, *c, *d);
    *b = 30;
    printf("%d %d %d %d\n", a, *b, *c, *d);
    return 0;
}