/********************
 * QUESTAO 1
 * ******************/

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

/********************
 * QUESTAO 2
 * ******************/

#include <stdio.h>




int main() {
    int i=0, qtd=0;
    char txt[50];
    
    scanf("%d", &qtd);

    while(i<qtd) {
        scanf(" %[^\n]", txt);
        printf("%s\n", txt);
        i++;
    }

    
    
    return 0;
}

/********************
 * QUESTAO 3
 * ******************/

#include <stdio.h>

void combinar(char txt1[], char txt2[], char result[]) {
    int i=0;
    int i1=0;
    int i2=0;
    while(i<100) {
        // printf("%d\n", i);
        if (i%2==0) {
            result[i] = txt1[i1];
            i1++;
        } else {
            result[i] = txt2[i2];
            i2++;
        }
        i++;
    }
    result[i]='\0';
}

int main() {
    int i, j, qtd=0;
    char txt1[50];
    char txt2[50];
    char result[100];
    
    scanf("%d", &qtd);

    for (i=0; i<qtd; i++) {
        scanf("%s %s", txt1, txt2);
        combinar(txt1, txt2, result);
        printf("%s\n", result);
    }
    
    return 0;
}

/********************
 * QUESTAO 4
 * ******************/

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
            par[ip] = input[i];
            ip++;
        }
        else {
            impar[ii] = input[i];
            ii++;
        }
        if (_isPrime(input[i]) == 0) {
            primo[ipp] = input[i];
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

    printf("Impares: [ ");
    for (i=0; i<qtd; i++) {
        if (impar[i] > 0) printf("%d ", impar[i]);
    }
    printf("]\n");
    printf("Pares: [ ");
    for (i=0; i<qtd; i++) {
        if (par[i] > 0) printf("%d ", par[i]);
    }
    printf("]\n");
    printf("Primos: [ ");
    for (i=0; i<qtd; i++) {
        if (primo[i] > 0) printf("%d ", primo[i]);
    }
    printf("]\n");

    return 0;
}