#include <stdio.h>

int _isPrime(int num) {
    int i;
    if (i==0 || i==1) return 1;
    for (i=1; i*i < num; i++) {
        printf("%d %d\n", i*i, num);
        if (num % i == 0){
            return 1;
        }
    }
    return 0;
}

void organize(int input[], int t_input, int impar[], int par[], int primo[]) {
    int i;
    int ii=0, ip=0, ipp=0;

    for (i=0; i<t_input; i++) {
        par[i] = -1;
        impar[i] = -1;
        primo[i] = -1;
        if (input[i] % 2== 0) {
            par[ip%10] = input[i];
            ip++;
        }
        else {
            impar[ii%10] = input[i];
            ii++;
        }
        if (_isPrime(input[i]) == 0) {
            primo[ipp%10] = input[i];
            ipp++;
        }
    }
}

int main() {
    int i, qtd=0;
    
    scanf("%d", &qtd);
    
    int input[100];
    int impar[100];
    int par[100];
    int primo[100];

    for (i=0; i<qtd; i++) {
        scanf("%d", &input[i]);
        // printf("%d ", input[i]);
    }

    organize(input, qtd, impar, par, primo);

    printf("Impares: [");
    for (i=0; i<qtd; i++) {
        if (impar[i] > 0) printf("%d ", impar[i]);
    }
    printf("\b]\n");
    printf("Pares: [");
    for (i=0; i<qtd; i++) {
        if (par[i] > 0) printf("%d ", par[i]);
    }
    printf("\b]\n");
    printf("Primos: [");
    for (i=0; i<qtd; i++) {
        if (primo[i] > 0) printf("%d ", primo[i]);
    }
    printf("\b]\n");

    return 0;
}