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