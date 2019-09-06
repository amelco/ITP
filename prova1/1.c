#include <stdio.h>


void fibonacci(int fib[]) {
    int i;
    int a[50];

    a[0] = 1;
    a[1] = 1;
    for (i=2; i<50; i++) {
        a[i] = a[i-1] + a[i-2];
        fib[i] = a[i];
    }
}

int fibonot(int termo) {
    int i;
    int a[50];
    int fib[50];
    int fibnot[50];

    fibonacci(fib);
    int pos=0;
    for (i=1; i<50; i++) {
        for (j=0; j<50; j++) {
            if (fib[j] == i) break;
            else {
                fibnot[pos] = i;
                pos++;
            }

        }
    }



    
}

int main() {

    return 0;
}