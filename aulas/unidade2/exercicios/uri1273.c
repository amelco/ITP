#include <stdio.h>
#include <string.h>

void pr_inv(int num, char texto[num][50]) {
    int tam = 0, max = 0, imax = -1;
    
    for (int i=0; i < num; i++) {
        tam = strlen(texto[i]);
        if (tam > max) max = tam;
    }
    for (int i=0; i < num; i++) {
        for (int j=0; j<max; j++) {
            if (i != imax) {
                for (int k=0; k<imax-strlen(texto[i]); k++) printf(" ");
            }
            printf("%s\n", texto[i]);

        }
    }

}

int main() {
    int num = -1;

    scanf("%d", &num);
    while (num != 0) {
        char texto[num][50];
        for(int i=0; i<num; i++) {
            char tmp[50];
            scanf(" %s", texto[i]);
        }
        pr_inv(num, texto);
        scanf("%d", &num);
    }

    return 0;
}