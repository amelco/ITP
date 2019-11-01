#include <stdio.h>

int rec(int n) {
    if (n==1) 
        return 10;
    else {
        return 5+rec(n-1);
    }
}

int main() {
    printf("%d\n", rec(6));
    return 0;
}