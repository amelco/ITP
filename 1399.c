#include <stdio.h>

int menores(int vec[], int t_v, int L, int R, int v) {
    int k=0;
    for (int i = L-1; i < R-1; i++) {
        if (vec[i] < v) k++;
    }
    return k;
}

void transform(int A[], int args[]){
    A[args[0]] = args[1]*args[2]/(args[3]-args[4]+1);
}

int main() {
    int i, j;
    int n, m, u;
    int L, R, v, p;
    int k=0;
    
    scanf("%d %d %d", &n, &m, &u);

    int A[n];

    for (i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    for (i=0; i<m; i++) {
        scanf("%d %d %d %d", &L, &R, &v, &p);
        k = menores(A, n, L, R, v);
        // A[p-1] = u*k/(R-L+1);
        int args[] = {p, u, k, R, L};
        transform(A, args);
        for (j=0; j<n; j++) {
            printf("%d\n", A[j]);
        }
    }

    return 0;
}