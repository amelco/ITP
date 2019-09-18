#include <stdio.h>

void triang(int n) {
    int tp[n][n];
    
    for (int i=0; i<n; i++) {
        tp[n]
    }
}


void tartaglia(int n, int pasc_triang[n]) {
    int next[n];
    next[0] = 1;

    if (n==1) {
        for (int i=1; i<n; i++) {
            next[i] = 0;
            printf("%d ", next[i]);
        }
    }
    else {
        for (int i=1; i<n; i++) {
            next[i] = pasc_triang[i-1] +  pasc_triang[i]; 
            printf("%d ", next[i]);
        }
        tartaglia(n-1, next);
    }
}

int main() {
    
    return 0;
}