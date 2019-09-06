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