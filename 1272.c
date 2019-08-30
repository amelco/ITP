#include <stdio.h>
#include <string.h>

void discover(char texto[]) {
    int i;
    for (i=0; texto[i]!='\0'; i++) {
        printf("a");
        if (texto[i]==' ' && texto[i+1]!=' ') printf("%c", texto[i+1]);
    }
    printf("\n");
}

int main() {
    int i, n;
    char texto[50];
    
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%[^\n]", texto);
        discover(texto);
    }

    return 0;
}